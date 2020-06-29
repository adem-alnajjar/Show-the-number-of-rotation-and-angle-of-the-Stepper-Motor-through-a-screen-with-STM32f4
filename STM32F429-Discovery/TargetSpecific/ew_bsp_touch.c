/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This software is delivered "as is" and shows the usage of other software
* components. It is provided as an example software which is intended to be
* modified and extended according to particular requirements.
*
* TARA Systems hereby disclaims all warranties and conditions with regard to the
* software, including all implied warranties and conditions of merchantability
* and non-infringement of any third party IPR or other rights which may result
* from the use or the inability to use the software.
*
********************************************************************************
*
* DESCRIPTION:
*   This file is part of the interface (glue layer) between an Embedded Wizard
*   generated UI application and the board support package (BSP) of a dedicated
*   target.
*   Please note: The implementation of this module is partially based on
*   examples that are provided within the STM32 cube firmware. In case you want
*   to adapt this module to your custom specific hardware, please adapt the
*   hardware initialization code according your needs or integrate the generated
*   initialization code created by using the tool CubeMX.
*   This template is responsible to initialize the touch driver of the display
*   hardware and to receive the touch events for the UI application.
*
*******************************************************************************/

#include "ewconfig.h"
#include "string.h"
#include "stm32f4xx_hal.h"
#include "stm32f429i_discovery.h"
#include "stm32f429i_discovery_ts.h"

#include "ewrte.h"

#include "ew_bsp_clock.h"
#include "ew_bsp_touch.h"

#define NO_OF_FINGERS                   1

/* additional touch flag to indicate idle state */
#define EW_BSP_TOUCH_IDLE               0

/* additional touch flag to indicate hold state */
#define EW_BSP_TOUCH_HOLD               4


static int                    TouchAreaWidth  = 0;
static int                    TouchAreaHeight = 0;
static unsigned char          TouchState      = EW_BSP_TOUCH_IDLE;
static XTouchEvent            TouchEvent[ NO_OF_FINGERS ];


/*******************************************************************************
* FUNCTION:
*   EwBspTouchInit
*
* DESCRIPTION:
*   Initializes the touch driver.
*
* ARGUMENTS:
*   aWidth  - Width of the toucharea (framebuffer) in pixel.
*   aHeight - Height of the toucharea (framebuffer) in pixel.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspTouchInit( int aWidth, int aHeight )
{
  TouchAreaWidth  = aWidth;
  TouchAreaHeight = aHeight;
  memset( TouchEvent, 0, sizeof( TouchEvent ));

  BSP_TS_Init( aWidth, aHeight );
}


/*******************************************************************************
* FUNCTION:
*   EwBspTouchDone
*
* DESCRIPTION:
*   Terminates the touch driver.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspTouchDone( void )
{
}


/*******************************************************************************
* FUNCTION:
*   EwBspTouchGetEvents
*
* DESCRIPTION:
*   The function EwBspTouchGetEvents reads the current touch positions from the
*   touch driver and returns the current touch position and touch status of the
*   different fingers. The returned number of touch events indicates the number
*   of XTouchEvent that contain position and status information.
*   The orientation of the touch positions is adjusted to match GUI coordinates.
*   If the hardware supports only single touch, the finger number is always 0.
*
* ARGUMENTS:
*   aTouchEvent - Pointer to return array of XTouchEvent.
*
* RETURN VALUE:
*   Returns the number of detected touch events, otherwise 0.
*
*******************************************************************************/
int EwBspTouchGetEvents( XTouchEvent** aTouchEvent )
{
  static TS_StateTypeDef touchPadState;
  int                    tsPosX;
  int                    tsPosY;
  int                    x;
  int                    y;
  int                    noOfEvents     = 0;
  unsigned long          ticks          = EwGetTicks();
  static unsigned long   ticksLastDown  = 0;
  static unsigned long   ticksLastUp    = 0;

  /* access touch driver to receive current touch status and position */
  touchPadState.TouchDetected = 0;

  CPU_LOAD_SET_IDLE();
  BSP_TS_GetState( &touchPadState );
  CPU_LOAD_SET_ACTIVE();

  tsPosX = touchPadState.X;
  tsPosY = touchPadState.Y;

  if ( touchPadState.TouchDetected &&
     ( tsPosX > 0 ) && ( tsPosX < TouchAreaWidth  - 1 ) &&
     ( tsPosY > 0 ) && ( tsPosY < TouchAreaHeight - 1 ))
  {
    #if ( EW_SURFACE_ROTATION == 90 )

      x = tsPosY;
      y = TouchAreaWidth  - tsPosX;

    #elif ( EW_SURFACE_ROTATION == 270 )

      x = TouchAreaHeight - tsPosY;
      y = tsPosX;

    #elif ( EW_SURFACE_ROTATION == 180 )

      x = TouchAreaWidth  - tsPosX;
      y = TouchAreaHeight - tsPosY;

    #else

      x = tsPosX;
      y = tsPosY;

    #endif

    ticksLastDown = ticks;

    if (( x == TouchEvent[ 0 ].XPos ) && ( y == TouchEvent[ 0 ].YPos ))
      return 0;

    if ( ticks - ticksLastUp < 40 )
      return 0;

    if ( TouchState == EW_BSP_TOUCH_IDLE )
      TouchState = EW_BSP_TOUCH_DOWN;
    else
      TouchState = EW_BSP_TOUCH_MOVE;

    TouchEvent[ 0 ].XPos   = x;
    TouchEvent[ 0 ].YPos   = y;
    TouchEvent[ 0 ].State  = TouchState;
    noOfEvents = 1;
  }
  else
  {
    /* touch driver provides permanently 'up' events while finger is pressed - in order
       to avoid that a touch sequence is interrupted by unwished 'up' events we have to
       filter over a certain time period until a real 'up' event is detected */
    if (( TouchState != EW_BSP_TOUCH_IDLE ) && ( ticks - ticksLastDown > 40 ))
    {
      TouchEvent[ 0 ].State  = EW_BSP_TOUCH_UP;
      TouchState = EW_BSP_TOUCH_IDLE;
      noOfEvents = 1;
      ticksLastUp = ticks;
    }
  }

  /* return the prepared touch events and the number of prepared touch events */
  if ( aTouchEvent )
    *aTouchEvent = TouchEvent;

  return noOfEvents;
}

/* msy, mli */
