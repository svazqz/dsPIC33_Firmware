/*
 * File:   main.c
 * Author: Sergio Vazquez
 *
 * Created on 12 de agosto de 2018, 12:27 PM
 */
#ifndef SYSTEM_H
#define	SYSTEM_H
#include "common.h"

// Peripherals libraries

// // Clock peripherals
#include "peripherals/time/clock.h"
// #include "peripherals/time/timer1.h"
// #include "peripherals/time/timer2.h"
// #include "peripherals/time/timer3.h"
// #include "peripherals/time/timer4.h"
// #include "peripherals/time/timer5.h"
// // // #include "peripherals/time/rtc.h"

// // Memory peripherals
// // // #include "peripherals/memory/ram.h"
// // // #include "peripherals/memory/rom.h"

// // I/O peripherals
#include "peripherals/io/adc.h"
// #include "peripherals/io/gpio.h"
// // // #include "peripherals/io/pwm.h"

// // Communication peripherals
// #include "peripherals/com/ecan.h"
// #include "peripherals/com/uart.h"
// #include "peripherals/com/i2c.h"
// #include "peripherals/com/spi.h"

void System_Init( void );
#endif