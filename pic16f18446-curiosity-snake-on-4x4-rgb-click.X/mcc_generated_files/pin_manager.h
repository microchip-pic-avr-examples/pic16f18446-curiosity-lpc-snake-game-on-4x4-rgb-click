/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.80.0
        Device            :  PIC16F18446
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RGB aliases
#define RGB_TRIS                 TRISAbits.TRISA4
#define RGB_LAT                  LATAbits.LATA4
#define RGB_PORT                 PORTAbits.RA4
#define RGB_WPU                  WPUAbits.WPUA4
#define RGB_OD                   ODCONAbits.ODCA4
#define RGB_ANS                  ANSELAbits.ANSA4
#define RGB_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RGB_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RGB_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RGB_GetValue()           PORTAbits.RA4
#define RGB_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RGB_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RGB_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define RGB_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define RGB_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define RGB_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define RGB_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define RGB_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set UP aliases
#define UP_TRIS                 TRISBbits.TRISB4
#define UP_LAT                  LATBbits.LATB4
#define UP_PORT                 PORTBbits.RB4
#define UP_WPU                  WPUBbits.WPUB4
#define UP_OD                   ODCONBbits.ODCB4
#define UP_ANS                  ANSELBbits.ANSB4
#define UP_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define UP_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define UP_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define UP_GetValue()           PORTBbits.RB4
#define UP_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define UP_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define UP_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define UP_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define UP_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define UP_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define UP_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define UP_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set DOWN aliases
#define DOWN_TRIS                 TRISBbits.TRISB5
#define DOWN_LAT                  LATBbits.LATB5
#define DOWN_PORT                 PORTBbits.RB5
#define DOWN_WPU                  WPUBbits.WPUB5
#define DOWN_OD                   ODCONBbits.ODCB5
#define DOWN_ANS                  ANSELBbits.ANSB5
#define DOWN_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define DOWN_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define DOWN_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define DOWN_GetValue()           PORTBbits.RB5
#define DOWN_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define DOWN_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define DOWN_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define DOWN_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define DOWN_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define DOWN_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define DOWN_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define DOWN_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set LEFT aliases
#define LEFT_TRIS                 TRISBbits.TRISB6
#define LEFT_LAT                  LATBbits.LATB6
#define LEFT_PORT                 PORTBbits.RB6
#define LEFT_WPU                  WPUBbits.WPUB6
#define LEFT_OD                   ODCONBbits.ODCB6
#define LEFT_ANS                  ANSELBbits.ANSB6
#define LEFT_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define LEFT_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define LEFT_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define LEFT_GetValue()           PORTBbits.RB6
#define LEFT_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define LEFT_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define LEFT_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define LEFT_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define LEFT_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define LEFT_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define LEFT_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define LEFT_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set RIGHT aliases
#define RIGHT_TRIS                 TRISBbits.TRISB7
#define RIGHT_LAT                  LATBbits.LATB7
#define RIGHT_PORT                 PORTBbits.RB7
#define RIGHT_WPU                  WPUBbits.WPUB7
#define RIGHT_OD                   ODCONBbits.ODCB7
#define RIGHT_ANS                  ANSELBbits.ANSB7
#define RIGHT_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RIGHT_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RIGHT_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RIGHT_GetValue()           PORTBbits.RB7
#define RIGHT_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RIGHT_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RIGHT_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define RIGHT_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define RIGHT_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define RIGHT_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define RIGHT_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define RIGHT_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/