# Introduction

This is an example of a small snake game running on a PIC16F18446.

![Board](./images/1.jpg)

# Description

In this demo,

- PIC16F18446 (20-pin, PDIP) MCU is used to run the snake game.
- 4X4 RGB Click Board from MikroElektronika™ is used as a display.
- The Curiosity development board is used as it supports a mikroBUS slot for MikroElektronika™ click boards and has got on-board programmer and debugger.
- A custom made board with 4 pushbuttons is used as a controller.

Buttons are connected as follows:

![Buttons schematic](./images/2.png)

# Software Tools

Make sure the latest MCC libraries for PIC16F18446 MCU are installed. The demo/example uses the following version of software tools from Microchip:

- MPLAB® X IDE v5.30
- XC8® Compiler v2.10
- MPLAB® Code Configurator (Plugin) v3.95
- MCC Core v4.85
- Microcontrollers and peripherals Library v1.80

# Demo Hardware Setup

- Plug the PIC16F18446 MCU into its socket on the Curiosity board
- Plug the 4X4 RGB Click into the mikroBUS slot of the Curiosity board
- Connect the buttons according to the schematic above

# MCC Settings

This section shows the settings used in the demo/example for various MCU modules configuration. These settings were done using the Microchip Code Configurator (MCC). Open MCC to look at the settings of the modules.

## System Module Settings

The MCU uses the high frequency internal oscillator (HFINTOSC), and the clock is set to 32 MHz. Watchdog Timer is not used in this demo, so it is disabled.

![System modules settings](./images/3.png)

## Pin Manager Settings

The pins are configured as follows:

- Pin RA4 is the output for controlling the RBG Click.
- Pin RB4 is the input for the UP button.
- Pin RB5 is the input for the DOWN button.
- Pin RB6 is the input for the LEFT button.
- Pin RB7 is the input for the RIGHT button.

The button pins have pull-ups enabled, so they read '1' when the buttons are released, and '0' when the buttons are pressed. The common button pin is GND.

![Pin Manager Settings](./images/4.png)
![Pin Manager Settings](./images/5.png)

# Operation

1. After making the above hardware connections, connect the Curiosity board to PC using the USB cable.
2. Build demo firmware and load the generated hex file onto the PIC16F18446 MCU. When the demo firmware is loaded, the snake game will start.
3. Use the 4 buttons to control the snake.

# Conclusion

This example shows how easy it is to make a simple snake game with the PIC16F18446, 4x4 RGB Click and MCC.
