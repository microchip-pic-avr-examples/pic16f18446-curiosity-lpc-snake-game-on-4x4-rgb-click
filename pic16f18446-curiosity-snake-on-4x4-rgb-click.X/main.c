/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65
        Device            :  PIC16F18446
        Driver Version    :  2.00
 */

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

#include "mcc_generated_files/mcc.h"
#include <stdlib.h>

#define PIXEL_COUNT 16
#define BYTES_TO_SEND PIXEL_COUNT*3

#define SNAKE_COLOR 0x000B00
#define SNAKE_HEAD_COLOR 0x00000B
#define EMPTY_COLOR 0x000000
#define FOOD_COLOR 0x0B0000
#define FAIL_COLOR 0x0B0B0B
#define FILL_COLOR 0x0B0B0B


uint32_t rgbData[PIXEL_COUNT];
uint8_t bytesToSend[BYTES_TO_SEND];

void setPixel(int8_t x, int8_t y, uint32_t color)
{
    if (x < 0) return;
    if (y < 0) return;
    if (x > 3) return;
    if (y > 3) return;
    rgbData[x + (3 - y)*4] = color;
}

uint32_t getPixel(int8_t x, int8_t y)
{
    if (x < 0) return 0;
    if (y < 0) return 0;
    if (x > 3) return 0;
    if (y > 3) return 0;
    return rgbData[x + (3 - y)*4];
}

inline void RGB_Send0()
{
    RGB_LAT = 1;
    asm("NOP");
    RGB_LAT = 0;
    //asm("NOP");
    //asm("NOP"); // next instructions take much longer anyway
}

inline void RGB_Send1()
{
    RGB_LAT = 1;
    asm("NOP");
    asm("NOP");
    asm("NOP");
    RGB_LAT = 0;
    //asm("NOP");
    //asm("NOP"); // next instructions take much longer anyway
}

uint8_t flip8(uint8_t d)
{
    uint8_t res = 0;
    uint8_t i;

    for (i = 0; i < 8; i++)
    {
        res = (res << 1) + (d & 1);
        d = d >> 1;
    }
    return res;
}

void updateDisplay()
{

    uint32_t rgb;
    uint8_t i, j, r, g, b;
    uint8_t byteToSend;

    for (i = 0; i < PIXEL_COUNT; i++)
    {
        rgb = rgbData[i];
        b = rgb & 0xFF;
        rgb >>= 8;
        g = rgb & 0xFF;
        rgb >>= 8;
        r = rgb & 0xFF;

        bytesToSend[i * 3 ] = flip8(g);
        bytesToSend[i * 3 + 1] = flip8(r);
        bytesToSend[i * 3 + 2] = flip8(b);
    }

    for (i = 0; i < BYTES_TO_SEND; i++)
    {
        byteToSend = bytesToSend[i];
        for (j = 0; j < 8; j++)
        {
            if (byteToSend & 1)
            {
                RGB_Send1();
            }
            else
            {
                RGB_Send0();
            }
            byteToSend = byteToSend >> 1;
        }
    }

    __delay_us(50);
}



int8_t snakeX[PIXEL_COUNT];
int8_t snakeY[PIXEL_COUNT];
uint8_t snakeLen;
uint8_t snakeDir;

void snakeInit()
{
    snakeX[0] = 0; /// tail
    snakeY[0] = 0; //
    snakeX[1] = 1;
    snakeY[1] = 0;
    snakeX[2] = 2;
    snakeY[2] = 0;

    snakeLen = 3;

    snakeDir = 'r';
}

void snakeDraw()
{
    uint8_t i;

    for (i = 0; i < snakeLen - 1; i++)
    {
        setPixel(snakeX[i], snakeY[i], SNAKE_COLOR);
    }

    setPixel(snakeX[i], snakeY[i], SNAKE_HEAD_COLOR);
}

void snakeErase()
{
    uint8_t i;

    for (i = 0; i < snakeLen - 1; i++)
    {
        setPixel(snakeX[i], snakeY[i], EMPTY_COLOR);
    }

}

void generateFood()
{
    uint8_t foodX;
    uint8_t foodY;
    uint8_t i;

    for (i = 0; i < 200; i++)
    {
        foodX = rand() % 4;
        foodY = rand() % 4;
        if (getPixel(foodX, foodY) == EMPTY_COLOR)
        {
            setPixel(foodX, foodY, FOOD_COLOR);
            break;
        }
    }
}

void snakeFail(int8_t x, int8_t y)
{
    uint8_t i;

    for (i = 0; i < 4; i++)
    {
        setPixel(x, y, FAIL_COLOR);
        updateDisplay();
        __delay_ms(125);
        setPixel(x, y, EMPTY_COLOR);
        updateDisplay();
        __delay_ms(125);
    }

    for (i = 0; i < 4; i++)
    {
        setPixel(0, 3 - i, FILL_COLOR);
        setPixel(1, 3 - i, FILL_COLOR);
        setPixel(2, 3 - i, FILL_COLOR);
        setPixel(3, 3 - i, FILL_COLOR);
        updateDisplay();
        __delay_ms(125);
    }

    for (i = 0; i < 4; i++)
    {
        setPixel(0, i, EMPTY_COLOR);
        setPixel(1, i, EMPTY_COLOR);
        setPixel(2, i, EMPTY_COLOR);
        setPixel(3, i, EMPTY_COLOR);
        updateDisplay();
        __delay_ms(125);
    }

}

int8_t snakeStep()
{

    uint8_t i;

    int8_t nextX = snakeX[snakeLen - 1];
    int8_t nextY = snakeY[snakeLen - 1];

    uint32_t nextCol;

    switch (snakeDir)
    {
        case 'u':
            nextY--;
            break;
        case 'd':
            nextY++;
            break;
        case 'l':
            nextX--;
            break;
        case 'r':
            nextX++;
            break;
        default: break;
    }


    if (nextX < 0 ||
        nextY < 0 ||
        nextX > 3 ||
        nextY > 3)
    {

        snakeFail(snakeX[snakeLen - 1], snakeY[snakeLen - 1]);
        return -1;
    }

    nextCol = getPixel(nextX, nextY);

    if (nextCol == SNAKE_COLOR)
    { // snake eats tail
        snakeFail(nextX, nextY);
        return -1;
    }

    snakeErase();

    if (nextCol == FOOD_COLOR)
    {

        // eat food
        snakeX[snakeLen] = nextX;
        snakeY[snakeLen] = nextY;
        snakeLen++;

        snakeDraw();

        generateFood();

    }
    else
    {
        for (i = 0; i < snakeLen - 1; i++)
        {
            snakeX[i] = snakeX[i + 1];
            snakeY[i] = snakeY[i + 1];
        }
        snakeX[i] = nextX;
        snakeY[i] = nextY;

        snakeDraw();
    }

    return 0;

}

void clearDisplay()
{
    uint8_t i;

    for (i = 0; i < PIXEL_COUNT; i++)
    {
        rgbData[i] = EMPTY_COLOR;
    }
}

uint8_t up, down, left, right;

void processButtons()
{

    uint8_t upState;
    uint8_t downState;
    uint8_t leftState;
    uint8_t rightState;

    static uint8_t upOldState = 1;
    static uint8_t downOldState = 1;
    static uint8_t leftOldState = 1;
    static uint8_t rightOldState = 1;

    upState = UP_PORT;
    downState = DOWN_PORT;
    leftState = LEFT_PORT;
    rightState = RIGHT_PORT;

    up = (upState == 0) && (upOldState == 1);
    down = (downState == 0) && (downOldState == 1);
    left = (leftState == 0) && (leftOldState == 1);
    right = (rightState == 0) && (rightOldState == 1);

    upOldState = upState;
    downOldState = downState;
    leftOldState = leftState;
    rightOldState = rightState;
}

void main(void)
{
    uint8_t i;
    uint8_t btnPressed;

    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    RGB_TRIS = 0;
    RGB_LAT = 0;


    clearDisplay();
    snakeInit();
    snakeDraw();
    generateFood();
    updateDisplay();

    
    while (1)
    {

        for (i = 0; i < 10; i++)
        {

            btnPressed = 0;

            processButtons();

            if (up)
            {
                snakeDir = 'u';
                btnPressed = 1;
            }
            if (down)
            {
                snakeDir = 'd';
                btnPressed = 1;
            }
            if (left)
            {
                snakeDir = 'l';
                btnPressed = 1;
            }
            if (right)
            {
                snakeDir = 'r';
                btnPressed = 1;
            }

            if (btnPressed)
            {
                break;
            }

            __delay_ms(40);
        }

        if (snakeStep() != 0)
        {
            clearDisplay();
            snakeInit();
            snakeDraw();
            generateFood();
        }
        updateDisplay();
    }
}
/**
 End of File
 */