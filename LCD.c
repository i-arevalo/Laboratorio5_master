/*
 * File:   LCD.c
 * Author: Israel Arevalo
 * Created on 28 de febrero de 2020, 03:20 AM
 */

#define _XTAL_FREQ 4000000

#include <xc.h> // include processor files - each processor file is guarded. 
#include <stdint.h>
#include "LCD.h"

void puerto_sal (char num){
    if (num & 0b00000001)
        D0 = 1;
    else
        D0 = 0;
    
    if (num & 0b00000010)
        D1 = 1;
    else
        D1 = 0;
    
    if (num & 0b00000100)
        D2 = 1;
    else
        D2 = 0;
    
    if (num & 0b00001000)
        D3 = 1;
    else
        D3 = 0;
    
    if (num & 0b00010000)
        D4 = 1;
    else
        D4 = 0;
    
    if (num & 0b00100000)
        D5 = 1;
    else
        D5 = 0;
    
    if (num & 0b01000000)
        D6 = 1;
    else
        D6 = 0;
    
    if (num & 0b10000000)
        D7 = 1;
    else
        D7 = 0;
              
}

void conv_lcd (char x){
    RS = 0;
    puerto_sal(x);
    E = 1;
    __delay_ms(4);
    E = 0;
    //__delay_ms(4);
}

void iniciar_lcd(void){
    //puerto_sal (0x000);
    PORTB = 0;
    __delay_ms(25);
    conv_lcd (0x030);
    __delay_ms (5);
    conv_lcd (0x030);
    __delay_us (160);
    conv_lcd (0x030);
    __delay_us(160);
    
    conv_lcd (0x02);
    conv_lcd (0x38);
    conv_lcd (0x0C);
    conv_lcd (0x06);
}

void lcd_cursor (char y, char x){
    char temp;
    if (y == 1){
        temp = 0x80 + x -1;
        conv_lcd (temp);
    }
    else if (y == 2){
        temp = 0xc0 + x - 1;
        conv_lcd (temp);
    }
}

void lcd_escribir_char (char x){
    RS = 1;
    puerto_sal (x);
    E = 1;
    __delay_us (40);
    E = 0;
}

void lcd_escribir_string (char *x){
    char i;
    for (i = 0; x[i] != '\0' ; i++){
        lcd_escribir_char (x[i]);
    }
}

void lcd_clear(void){
    conv_lcd(0b00000001);
}
