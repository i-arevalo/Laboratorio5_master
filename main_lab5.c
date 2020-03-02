/*
 * File:   main_lab6_master.c
 * Author: Arevalo
 *
 * Created on 28 de febrero de 2020, 03:20 AM
 */

#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)


//#ifndef
#define _XTAL_FREQ 4000000
//#endif

#include <xc.h>
#include <stdint.h>
#include <pic16f887.h>
#include <stdio.h>
#include <stdlib.h>
#include "I2C.h"
#include "LCD.h"

uint8_t pote;
uint8_t foto;
float pote_float;
float foto_float;
char res_pote[8];
char res_foto[8];
uint8_t uni;
uint8_t dec;
uint8_t cont;

void init(void);

void main(void) {
    init();
    iniciar_lcd();
    lcd_clear();
    lcd_cursor(1,1);
    
}

void init(void){
    ANSEL = 0x00;
    ANSELH = 0x00;
    TRISD = 0x00;
    TRISB = 0x00;
    PORTB = 0;
    PORTD = 0;
}
