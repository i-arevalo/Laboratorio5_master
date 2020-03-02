/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#ifndef __LCD_H_
#define	__LCD_H_

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 4000000
#endif

#ifndef D0
#define D0 RB0
#endif

#ifndef D1
#define D1 RB1
#endif

#ifndef D2
#define D2 RB2
#endif

#ifndef D3
#define D3 RB3
#endif

#ifndef D4
#define D4 RB4
#endif

#ifndef D5
#define D5 RB5
#endif

#ifndef D6
#define D6 RB6
#endif

#ifndef D7
#define D7 RB7
#endif

#ifndef RS
#define RS RD5
#endif

#ifndef E
#define E RD7
#endif

#include <xc.h> // include processor files - each processor file is guarded. 
#include <stdint.h>

//void LCD_conf(uint8_t con1, uint8_t con0);
void puerto_sal(char num);
void iniciar_lcd (void);
void conv_lcd (char x);
void lcd_cursor (char y, char x);
void lcd_escribir_char (char x);
void lcd_escribir_string (char *x);
void lcd_clear(void);

#endif	/* XC_HEADER_TEMPLATE_H */
