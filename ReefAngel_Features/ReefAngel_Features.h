/*
 * Copyright 2010 Curt Binder
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __REEFANGEL_FEATURES_H__
#define __REEFANGEL_FEATURES_H__

/*
This contains all the defines for enabling/disabling features with the controller software.

This file can be AutoGenerated by using the RAGen program.
*/

/*
If your sketch/compile size is getting too big or if you are running out of RAM and having bizarre events
happen with the controller, you may want to not display the graphics on screen which can save some memory.
Just comment out the next line to prevent any graphics from being displayed, you will have text only screens
during water changes and feeding modes.

Approximately 346 bytes to have this feature
*/
#define DisplayImages  // do we display the graphics for feeding or water change mode

/*
The next line is for displaying the setup screens to configure the values for the Feeding Mode timer and
the LCD shutoff timer.  The defaults are fine, BUT if you would like to have the ability to change them
from the setup screen, uncomment the next line.  This will increase the file size.  If you do not plan
to change these values often (or at all), keep the next line commented out.

Approximately 362 bytes to have this feature
*/
//#define SetupExtras  // feeding mode & screensaver timeout setup. ACTIVATE WITH CAUTION

/*
Since we may or may not need to always configure the Wavemakers, give the option to
turn off the setup screens to keep the compile size down.  You can still use the Wavemakers,
you just will not have the setup screen available to configure the values.  You will have to manually set
the intervals inside the Sketch (hardcode or have it read from memory if the memory contains the correct values).

Approximately 378 bytes to have WavemakerSetup
*/
//#define WavemakerSetup

/*
These next two options are for the Dosing Pumps.  They operate differently, so read carefully to determine
what option you want.

DosingPumpSetup
  Allows for specifying a specific time in which you want the dosing pump to turn on and run for.
  It only runs once per day and for the specified duration/run time.
  This feature will allow you to configure the start time and run time from the setup screens.

DosingPumpIntervalSetup
  Allows for specifying a minute interval that you would like the pump to turn on and run for.
  It runs every minute interval for the entire day.  It's start time is based off of midnight of the current day.
  If you specified a 60 minute interval, it will run for the specified duration every hour.
  This feature will allow you to configure the minute interval and run time from the setup screens.

Both options use the same Run Time that is stored in memory, so you will only be able to use one or the other
if you plan on configuring the run time from the setup screens.  If you use the hard coded values, you won't
need to use these options and you can use separate run times.

You can still use the DosingPump and DosingPumpInterval functions without these options,
you will just need to have the memory already be set or specifically set the values in the PDE file.
You just will not be able to change the values from the controller's setup screen.

Approximately 2000 bytes to have DosingPumpSetup
Approximately 368 bytes to have DosingPumpIntervalSetup
*/
//#define DosingPumpSetup
//#define DosingPumpIntervalSetup


/*
Overheat Temperature is fairly constant.  This value will most likely not get changed very often (if ever).
The default value is set to 150.0F.  Once this value is reached, all the lights will get shutoff.  If you
would like the ability to change this value from the menus, uncomment the next line.  Otherwise you will have
to hardcode the value in the ShowInterface Function

Approximately 156 bytes to have this feature
*/
//#define OverheatSetup

/*
The ability to set the Date & Time on the controller is controlled by this next line.  This line will add
in a Date / Time Setup menu entry which will allow you to set the date & time on the controller easily.
Comment the next line to remove this ability.

Approximately 1984 bytes to have this feature
*/
#define DateTimeSetup

/*
If you do not want to have a Version menu entry to see what version of the software is on the controller,
then you will want to comment out the next line

Approximately 144 bytes to have this feature
*/
#define VersionMenu

/*
If you do not use any of the ATO features in your setup, you can comment out this next line to remove
the ATO set and clear menu items.

Approximately 900 bytes to have this feature (and without SetupExtras)

When this or SetupExtras are defined, the Timeouts menu is included.
Timeouts menu requires approximately 710 bytes
This feature requires approximately 190 bytes if SetupExtras is defined
*/
//#define ATOSetup

/*
This item will remove all lighting functionality from the controller.  It is the equivalent to
commenting out MetalHalideSetup, StandardLightSetup, DisplayLEDPWM
This will OVERRIDE any of the other defines.  So use caution when enabling this feature.

Approximately 2796 bytes to have this feature
*/
//#define RemoveAllLights

/*
If you do not use metal halides and do not wish to have any of the setup screens on your controller,
you can comment out the next line to remove the Metal Halide Setup and Metal Halide Delay

Approximately 258 bytes to have this feature
*/
//#define MetalHalideSetup

/*
If you do not use standard lights and do not wish to have the setup screens on your controller,
you can comment out the next line to remove the Standard Lights Setup

Approximately 90 bytes to have this feature
*/
//#define StandardLightSetup

/*
If you want to use the old way of reading the temp sensor which is always reading the value in
and not performing any sanity check, then you will want to uncomment this next line.

Otherwise, you will use the new way to handle the temperatures.  The value is read in and then
compared to the existing value.  If the difference between the 2 values is less than MAX_TEMP_SWING
or the temperature is 0 then the temperature is allowed to be updated, otherwise it is not updated.
MAX_TEMP_SWING is currently set to 50, which is 5.0 F.  This prevents any temporary large fluctations
in temperatures.  Also, there should not be more than a 5.0 F degree fluctation in 1 second.
*/
//#define DirectTempSensor

/*
Do we save the relay state before we enter Feeding Mode or Water Change Mode?

Comment out the next line to not save the state and always force specific ports to be turned off and then
back on again after we exit the mode.  This can turn on some ports that were not already on.  This
is also how the controller originally works.

Currently untested.
*/
//#define SaveRelayState

/*
If you have the wifi module for your controller and wish to use it, you must uncomment this next line
to utilize the built-in webserver for the controller.

If enabled, you may want to consider enabling SIMPLE_MENU and disabling DateTimeSetup to save space.
This is advisable since all settings can be updated via the wifi interface.

Approximately 5000+ bytes to have this feature. This size can vary.
*/
#define wifi

/*
This next line will control the displaying of all LED PWM related items.  The items it controls are:

DP & AP displaying on main screen
LED PWM Setup screen

So, if you do not use LED PWM's at all and do not wish to display anything related to it, comment out
the next line and all that stuff will be removed.

Approximately 720 bytes to have this feature
*/
#define DisplayLEDPWM

/*
PWM Expansion Device

This next line will allow the enabling of the PWM Expansion Device.  It will add a menu entry that displays
"PWM ->".  It will give the preset defaults for the expansion device.
The menu entries will be:

Slow Cloud
Fast Cloud
T-storm 1
T-storm 2
0%
50%
100%
Custom

Approximately 630 bytes to have this feature
*/
//#define PWMEXPANSION

/*
This next line will allow you to use the ATO switches independently from each other.  You can specify
separate ports to control, separate timeouts and separate hourly intervals.
If you have this defined, you cannot use both switches together like originally intended.
The setup screens will show configurations for both switches.

Approximately 454 bytes to have this feature
*/
//#define SingleATOSetup

/*
If this next line is uncommented, you must include the following lines in
the PDE file at the top above all other include statements:
#include <ReefAngel_Colors.h>
#include <ReefAngel_CustomColors.h>
*/
//#define COLORS_PDE

/*
This will enable code for multiple expansion modules.  If you have expasion modules this must
be enabled to make use of them.

If you have more than 1 expansion module, you will need to uncomment and adjust the number of
expansion modules.  If it's left commented out, it is assumed to have 1 expansion module.  This
is only necessary when 2 or more modules are enabled so the web banner data gets sent
appropriately and possibly other enhancments in the future (in an attempt to keep code size
down and make the controller more customized for the user)

Approximately 530 bytes to have RelayExp
Approximately 94, 176 or 270 additional bytes needed when increasing InstalledRelayExpansionModules
*/
//#define RelayExp
//#define InstalledRelayExpansionModules	1

/*
This will enable the ability for people to create a custom main screen with the complete menu system
and without having to modify the libraries.
Once this is defined/enabled, you MUST create the following functions inside your PDE file.  If you do
not, then you will receive errors about missing functions.  If you create them and leave them blank,
you will have a blank main screen.  :)

void DrawCustomMain()
{
}
void DrawCustomGraph()
{
}

Just copy and paste the framework of the functions above into your PDE file.

If you do not want a graph to be displayed, you can leave it blank/empty.
*/
//#define CUSTOM_MAIN


/*
This is for the simplified menu.  All the additional / extra menus have been stripped down.
The bare basics are only left for operating on the controller.  This is useful for those who want
all the extra memory they can get on the controller.  Also for those who hardcode their values or
use the Client Suite (or other app or SetInternalMemory PDE) to update their memory values.

The menu system only contains:
	- Feeding Mode
	- Water Change Mode
	- ATO Clear
	- Overheat Clear
	- PH Calibration
	- Date / Time Setup (ability to be removed)
	- Version Menu (ability to be removed)

When this is enabled, the following other features are ignored, you can still use the functions,
you just won't have a setup menu for them:
	- StandardLightsSetup
	- MetalHalideSetup
	- ATOSetup
	- DosingPumpSetup
	- DosingPumpIntervalSetup
	- WavemakerSetup
	- SingleATOSetup

The following features are available for use with this feature:
	- DisplayLEDPWM / RemoveAllLights - shows or hides the LED PWM values on the main screen, no setup menu
	- wifi
	- SaveRelayState
	- DirectTempSensor
	- VersionMenu
	- DateTimeSetup
	- DisplayImages
	- CUSTOM_MAIN
	- COLORS_PDE
	- RelayExp
	- InstalledRelayExpansionModules

The following features partially work.  There is no setup menu for them, BUT if you want to use
the Internal Memory values for them you must enable the features:
	- SetupExtras (Feeding Timer and LCD Timeout Timer)
	- OverheatSetup (Change the overheat temperature)

Approximately 4566 bytes removed when using the Simplified Menu
*/
#define SIMPLE_MENU

/*
This option allows for the user to handle the menu in their PDE file

This option OVERRIDES SIMPLE_MENU

To use, you must enable CUSTOM_MENU AND define how many entries you want in your menu.
To define how many entries, you must change the number after CUSTOM_MENU_ENTRIES below.

When you enable this, you have to add several items to your PDE file.  You will be creating your menu
at the top of the file just like in the Standard Libraries.  You will also need to create the menu entry
functions associated with all of your menu entries.

To create the menu entries, use this code:

#include <avr/pgmspace.h>
prog_char menu0_label[] PROGMEM = "Item 1";
prog_char menu1_label[] PROGMEM = "Item 2";
prog_char menu2_label[] PROGMEM = "Item 3";
prog_char menu3_label[] PROGMEM = "Item 4";
prog_char menu4_label[] PROGMEM = "Item 5";
prog_char menu5_label[] PROGMEM = "Item 6";
prog_char menu6_label[] PROGMEM = "Item 7";
prog_char menu7_label[] PROGMEM = "Item 8";
prog_char menu8_label[] PROGMEM = "Item 9";
PROGMEM const char *menu_items[] = {
menu0_label, menu1_label, menu2_label,
menu3_label, menu4_label, menu5_label,
menu6_label, menu7_label, menu8_label
};

Only include the number of menu items that you are going to use.  If you add more than needed, it can cause problems.
So just copy and paste, remove the labels (starting from 8 and going down) until you get the total number you need.
Then change the string to be something you want.  There is a max of 20 characters per item.

Next, we must create the menu entry functions for use.  Use this code:

void MenuEntry1()
{
  ReefAngel.DisplayMenuEntry("Item 1");
}
void MenuEntry2()
{
  ReefAngel.DisplayMenuEntry("Item 2");
}
void MenuEntry3()
{
  ReefAngel.DisplayMenuEntry("Item 3");
}
void MenuEntry4()
{
  ReefAngel.DisplayMenuEntry("Item 4");
}
void MenuEntry5()
{
  ReefAngel.DisplayMenuEntry("Item 5");
}
void MenuEntry6()
{
  ReefAngel.DisplayMenuEntry("Item 6");
}
void MenuEntry7()
{
  ReefAngel.DisplayMenuEntry("Item 7");
}
void MenuEntry8()
{
  ReefAngel.DisplayMenuEntry("Item 8");
}
void MenuEntry9()
{
  ReefAngel.DisplayMenuEntry("Item 9");
}

Remove the functions that you do not need.  The above code just displays the text in the string on the display.
You can remove that line and put whatever you want in the function.
*/
//#define CUSTOM_MENU
// max of 9 entries
//#define CUSTOM_MENU_ENTRIES		6


/*
Alternate Fonts

To use the alternate fonts, you must uncomment the appropriate define statement to make the font available.
Once the font is available, it is not automatically used everywhere.  It's not used with the default main screen
and default menus.  You must enable the CUSTOM_MAIN so you can make use of the font when drawing your own main
screen.

There are full fonts for the sizes:  5x8 (built in), 8x8, 8x16, 12x16
There are numbers only for sizes:  8x8, 8x16, 12x16, 16x16

How to use:

Font 8x8:
ReefAngel.NokiaLCD.DrawLargeText(..., Font8x8);

Numbers 8x8:
ReefAngel.NokiaLCD.DrawLargeText(..., Num8x8);

Font 8x16:
ReefAngel.NokiaLCD.DrawLargeText(..., Font8x16);

Numbers 8x16:
ReefAngel.NokiaLCD.DrawLargeText(..., Num8x16);

Font 12x16:
ReefAngel.NokiaLCD.DrawHugeText(..., Font12x16);

Numbers 12x16:
ReefAngel.NokiaLCD.DrawHugeText(..., Num12x16);

Numbers 16x16:
ReefAngel.NokiaLCD.DrawHugeNumbers(...);

The ... means that the default parameters for the functions should be used.  It is just a place holder.
The DrawHugeNumbers needs to have the numbers drawn in a string, so it cannot take numeric values,
they must be converted prior to calling the function.

Enabling fonts requires more memory usage.  The more fonts you enable, the more memory is used.  It is advisable
to only enable the fonts that you plan on using.  Try to not use several at once to keep memory usage down.

ENABLE AT YOUR OWN RISK
*/
//#define FONT_8x8
//#define FONT_8x16
//#define FONT_12x16
//#define NUMBERS_8x8
//#define NUMBERS_8x16
//#define NUMBERS_12x16
//#define NUMBERS_16x16

/*
Watchdog Timers

With the optiboot bootloader, enabling the watchdog timer is possible.  You must have version 4 of the
optiboot booloader installed on the controller for this to work.  Once enabled, the watchdog timer must
be reset/tickled/touched periodically or else the controller will reboot.

If enabled, there is a check on controller initialization that verifies the proper bootloader is installed
before enabling the watchdog timer.
This option is called WDT.  This option also overrides WDT_FORCE (mentioned below).

There is also another option for people who have the optiboot bootloader prior to version 4.  There is only
a couple people who fall into this category.  This option should not be enabled unless instructed to do so.
Enabling this option otherwise could potentially cause problems with your controller.
This option is called WDT_FORCE.

Approximately 82 bytes to have Watchdog Enabled (WDT).
*/
// Watchdog Timer
//#define WDT
// Force Watchdog Timer - DO NOT ENABLE UNLESS TOLD TO DO SO
//#define WDT_FORCE

/*
Enable Exceeded flags

The red LED on the controller gets turned on when either the Overheat temp is reached OR if the ATO timeout is exceeded.
You do not know which event is the the one that caused the LED to turn on.  When you clear either event the LED is turned
off and you do not the other event was triggered.

Enabling this feature will keep track of which event caused the LED to be turned on.  The event gets stored in the internal
memory.  To know what event triggered the LED, you have to add in a display on your CUSTOM_MAIN screen to perform a check
or query the controller in the specified memory spaces to check.  When you clear the event (either ATO or Overheat), the event
is cleared from memory.  The time the event occurs is not logged only that the event did occur.

The memory locations are as follows:

ATO_Exceed_Flag
ATO_Single_Exceed_Flag
Overheat_Exceed_Flag

The ATO Clear will clear both the Standard ATO and Single ATO events.  Currently, there is no distinction between ATO High and
Low events.  This may be added in the future though.

This should only be enabled if you are running a custom main screen because you have to code it manually to display.

Approximately 68 bytes to enable the storing of the exceeded flags (not counting displaying them on the screen)
*/
//#define ENABLE_EXCEED_FLAGS

/*
ATO Event Logging

Enabling will log the ATO events to the internal memory for later querying from another application
such as Client Suite.  This will help catch the ATO events that occur between the logging intervals.
Only useful to enable if you have WIFI enabled as well.

Request ato events with /sa
Events logged with a max of 4 events (4 low / 4 high)
	Standard ATO events are logged with the atolow
	SingleATO events are logged either high or low
Logs are cleared when request for log information is sent

Structure of XML data being sent to requestor is:
	<AL#ON>VALUE</AL#ON>
	<AL#OFF>VALUE</AL#OFF>
	<AH#ON>VALUE</AH#ON>
    <AH#OFF>VALUE</AH#OFF>
Where # is the event number from 0 - 3
VALUE is the number of seconds since the epoc (jan 1, 1970)
*/
//#define ENABLE_ATO_LOGGING

/*
Special prototype PLUS board with built-in WIFI module.  Only 1 exists and Curt Binder has it.
Do NOT enable.  Code will not compile with this enabled.
*/
//#define __PLUS_SPECIAL_WIFI__

/*
Salinity Module

Uncomment this next line if you have a Salinity Module that you would like to use.  You will want to
use a custom main screen as well to display the Salinity values for you.  You must also put this line
in your PDE file above the ReefAngel.h include line:

#include <Salinity.h>  // <-- Add this line
#include <ReefAngel.h>  // <-- Add above this line

If you do not, you will get an error compiling.

Approximately 208 bytes to enable this feature
*/
//#define SALINITYEXPANSION

/*
RF Module

This module is used to control Vortech pumps.  Enable this feature if you want that control.
You will have to add in this line above the ReefAngel.h include:

#include <RF.h>  // <-- add this line
#include <ReefAngel.h>  // add above this line

Approximately 346 bytes to enable this feature
*/
//#define RFEXPANSION

/*
AI LED

This features the ability to control the AI LED's.
You will have to add in this line above the ReefAngel.h include:

#include <AI.h>  // <-- add this line
#include <ReefAngel.h>  // add above this line

Approximately 382 bytes to enable this feature
*/
//#define AI_LED

#endif  // __REEFANGEL_FEATURES_H__