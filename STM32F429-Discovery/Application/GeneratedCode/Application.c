/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This file was generated automatically by Embedded Wizard Studio.
*
* Please do not make any modifications of this file! The modifications are lost
* when the file is generated again by Embedded Wizard Studio!
*
* The template of this heading text can be found in the file 'head.ewt' in the
* directory 'Platforms' of your Embedded Wizard installation directory. If you
* wish to adapt this text, please copy the template file 'head.ewt' into your
* project directory and edit the copy only. Please avoid any modifications of
* the original template file!
*
* Version  : 9.30
* Profile  : STM32F429
* Platform : STM.STM32.RGB565
*
*******************************************************************************/

#include "main.h"
#include "ewlocale.h"
#include "_ApplicationApplication.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_GraphicsArcPath.h"
#include "_GraphicsPath.h"
#include "_ResourcesFont.h"
#include "_ViewsRectangle.h"
#include "_ViewsStrokePath.h"
#include "_ViewsText.h"
#include "Application.h"
#include "Graphics.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_it.h"


/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x0000000C, /* ratio 166.67 % */
  0xB8000900, 0x80060452, 0x04010883, 0x00000004, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 240, 320 }};
static const XColor _Const0001 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const0002 = {{ 20, 20 }, { 220, 49 }};
static const XStringRes _Const0003 = { _StringsDefault0, 0x0002 };
static const XRect _Const0004 = {{ 20, 50 }, { 220, 250 }};
static const XPoint _Const0005 = { 100, 100 };
static const XRect _Const0006 = {{ 20, 140 }, { 220, 169 }};

/* Initializer for the class 'Application::Application' */
void ApplicationApplication__Init( ApplicationApplication _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreRoot__Init( &_this->_Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_GCT = EW_CLASS_GCT( ApplicationApplication );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Rectangle, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Text, &_this->_XObject, 0 );
  ViewsStrokePath__Init( &_this->StrokePath, &_this->_XObject, 0 );
  GraphicsArcPath__Init( &_this->ArcPath, &_this->_XObject, 0 );
  CoreTimer__Init( &_this->Timer, &_this->_XObject, 0 );
  ViewsText__Init( &_this->Text1, &_this->_XObject, 0 );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ApplicationApplication );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0001 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0002 );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const0003 ));
  CoreRectView__OnSetBounds( &_this->StrokePath, _Const0004 );
  ViewsStrokePath_OnSetOffset( &_this->StrokePath, _Const0005 );
  ViewsStrokePath_OnSetMiterLimit( &_this->StrokePath, 3.000000f );
  ViewsStrokePath_OnSetWidth( &_this->StrokePath, 10.000000f );
  GraphicsArcPath_OnSetEndAngle( &_this->ArcPath, 100.000000f );
  GraphicsArcPath_OnSetRadius( &_this->ArcPath, 90.000000f );
  GraphicsArcPath_OnSetStyle( &_this->ArcPath, GraphicsArcStyleArc );
  CoreTimer_OnSetPeriod( &_this->Timer, 1 );
  CoreTimer_OnSetEnabled( &_this->Timer, 1 );
  CoreRectView__OnSetBounds( &_this->Text1, _Const0006 );
  ViewsText_OnSetString( &_this->Text1, EwLoadString( &_Const0003 ));
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Rectangle ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Text ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->StrokePath ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Text1 ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &ApplicationFont, ResourcesFont ));
  ViewsStrokePath_OnSetPath( &_this->StrokePath, ((GraphicsPath)&_this->ArcPath ));
  _this->Timer.OnTrigger = EwNewSlot( _this, ApplicationApplication_Slot );
  ViewsText_OnSetFont( &_this->Text1, EwLoadResource( &ApplicationFont, ResourcesFont ));
}

/* Re-Initializer for the class 'Application::Application' */
void ApplicationApplication__ReInit( ApplicationApplication _this )
{
  /* At first re-initialize the super class ... */
  CoreRoot__ReInit( &_this->_Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Rectangle );
  ViewsText__ReInit( &_this->Text );
  ViewsStrokePath__ReInit( &_this->StrokePath );
  GraphicsArcPath__ReInit( &_this->ArcPath );
  CoreTimer__ReInit( &_this->Timer );
  ViewsText__ReInit( &_this->Text1 );
}

/* Finalizer method for the class 'Application::Application' */
void ApplicationApplication__Done( ApplicationApplication _this )
{
  /* Finalize this class */
  _this->_Super._VMT = EW_CLASS( CoreRoot );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Rectangle );
  ViewsText__Done( &_this->Text );
  ViewsStrokePath__Done( &_this->StrokePath );
  GraphicsArcPath__Done( &_this->ArcPath );
  CoreTimer__Done( &_this->Timer );
  ViewsText__Done( &_this->Text1 );

  /* Don't forget to deinitialize the super class ... */
  CoreRoot__Done( &_this->_Super );
}

/* 'C' function for method : 'Application::Application.OnSetProperty()' */
void ApplicationApplication_OnSetProperty( ApplicationApplication _this, XFloat 
  value )
{
  if ( _this->Property == value )
    return;

  _this->Property = value;
}
extern char direction;
static int counter=0;
/* 'C' function for method : 'Application::Application.Slot()' */
void ApplicationApplication_Slot( ApplicationApplication _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Property >= 360.000000f )
  {
    GraphicsArcPath_OnSetEndAngle( &_this->ArcPath, 0.000000f );
    ApplicationApplication_OnSetProperty( _this, 0.000000f );
    ApplicationApplication_OnSetProperty1( _this, _this->Property1 + 1 );
    ViewsText_OnSetString( &_this->Text1, EwNewStringInt( _this->Property1, 0, 10 ));
  }
  if ( _this->Property <= -360.000000f )
    {
      GraphicsArcPath_OnSetEndAngle( &_this->ArcPath, 0.000000f );
      ApplicationApplication_OnSetProperty( _this, 0.000000f );
      ApplicationApplication_OnSetProperty1( _this, _this->Property1 - 1 );
      ViewsText_OnSetString( &_this->Text1, EwNewStringInt( _this->Property1, 0, 10 ));
    }
    	  	 if(direction=='R')
    	  	 {
    	  		 counter++;
    	  	 }
    	  	 if(direction=='L')
    	  	 {
    	  		 counter--;
    	  	 }
  			  if(counter==1)
  			  	{
  				  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_SET);
  			  		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_2,GPIO_PIN_RESET);
  			  		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,GPIO_PIN_RESET);
  			  		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_RESET);
  			  		if(direction=='L')
  			  		{
  			  			counter=5;
  			  		}
  			  	}
  			  	if(counter==2)
  			  	{
  			  		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_RESET);
  			  		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_2,GPIO_PIN_SET);
  			  		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,GPIO_PIN_RESET);
  			  		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_RESET);
  			  	}
  			  	if(counter==3)
  			  	{
  			  		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_RESET);
  			  		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_2,GPIO_PIN_RESET);
  			  		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,GPIO_PIN_SET);
  			  		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_RESET);
  			  	}
  			  	if(counter==4)
  			  		{
  			  		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_RESET);
  			  			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_2,GPIO_PIN_RESET);
  			  			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,GPIO_PIN_RESET);
  			  			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_SET);
  			  			if(direction=='R')
  			  			{
  			  				counter=0;
  			  			}
  			  		}
  			  	if(direction=='R')
  			  	{
  			  		if( _this->Property<0)
  					{
  						 _this->Property=0;
  					}
  				    ApplicationApplication_OnSetProperty( _this, _this->Property + 0.176f );
  				    if(_this->Property1<0)
  				    {
  				    	_this->Property1=0;
  				      ViewsText_OnSetString( &_this->Text1, EwNewStringInt( _this->Property1, 0, 10 ));

  				    }
  			  	}
  			  	if(direction=='L')
  			  	{
  			  		if( _this->Property>0)
  			  		{
  			  			 _this->Property=0;

  			  		}
  				    ApplicationApplication_OnSetProperty( _this, _this->Property - 0.176f );
  				  if(_this->Property1>0)
  				   				    {
  				   				    	_this->Property1=0;
  				   				      ViewsText_OnSetString( &_this->Text1, EwNewStringInt( _this->Property1, 0, 10 ));

  				   				    }

  			  	}




    GraphicsArcPath_OnSetEndAngle( &_this->ArcPath, _this->Property );
    ViewsText_OnSetString( &_this->Text, EwNewStringFloat( _this->Property, 0, -1 ));
  }

/* 'C' function for method : 'Application::Application.OnSetProperty1()' */
void ApplicationApplication_OnSetProperty1( ApplicationApplication _this, XInt32 
  value )
{
  if ( _this->Property1 == value )
    return;

  _this->Property1 = value;
}

/* Variants derived from the class : 'Application::Application' */
EW_DEFINE_CLASS_VARIANTS( ApplicationApplication )
EW_END_OF_CLASS_VARIANTS( ApplicationApplication )

/* Virtual Method Table (VMT) for the class : 'Application::Application' */
EW_DEFINE_CLASS( ApplicationApplication, CoreRoot, Rectangle, Rectangle, Rectangle, 
                 Rectangle, Property, Property, "Application::Application" )
  CoreRectView_initLayoutContext,
  CoreRoot_Draw,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreRoot_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreRoot_OnSetFocus,
  CoreRoot_DispatchEvent,
  CoreRoot_BroadcastEvent,
  CoreRoot_InvalidateArea,
EW_END_OF_CLASS( ApplicationApplication )

/* Include a file containing the font resource : 'Application::Font' */
#include "_ApplicationFont.h"

/* Table with links to derived variants of the font resource : 'Application::Font' */
EW_RES_WITHOUT_VARIANTS( ApplicationFont )

/* Embedded Wizard */
