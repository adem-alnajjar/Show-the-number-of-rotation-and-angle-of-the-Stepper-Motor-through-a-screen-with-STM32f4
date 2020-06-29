@echo off

rem *************************************************************************************************
rem Please set the ABSOLUTE installation path of the ST-LINK utility
rem *************************************************************************************************

set ST-LINK_Utility_Path=C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility

rem *************************************************************************************************
rem Please do NOT change the following settings
rem *************************************************************************************************
set PlatformName=STM32F429-Discovery
set BuildEnvVersion=V9.30
set GettingStartedLink=getting-started-stm32f429-discovery
cmd /K Application\Project\GCC\devenv.cmd
