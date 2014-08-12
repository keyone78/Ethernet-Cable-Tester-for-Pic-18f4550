#ifndef _LCD_H_
#define _LCD_H_

/*
 *	LCD interface header file
 */

/* 	Defining CHECKBUSY will check if the LCD is busy. The RW bit of the 
 * 	LCD must connected to a port of the processor for the check busy
 * 	process to work.
 * 
 * 	If CHECKBUSY is not defined it will instead use a delay loop.
 * 	The RW bit of the LCD does not need to connected in this case.
 */

// #define CHECKBUSY	1
//static volatile bit	LB7	@ (unsigned)&LATB*8+7;
//static volatile bit	LB6 	@ (unsigned)&LATB*8+6;
//static volatile bit	LB5  	@ (unsigned)&LATB*8+5;

#ifdef CHECKBUSY
	#define	LCD_WAIT lcd_check_busy()
#else
	#define LCD_WAIT DelayMs(5)

#endif

#define MESSAGE_LINE		0x0

#define LCD_RS	LATA0
#define LCD_EN	LATA2
#define LCD_RW	LATA1 
#define LCD_DATA	LATD
#define LCD_DATA_PORT	PORTD 
#define LCD_RS_TRIS	TRISA0
#define LCD_EN_TRIS	TRISA2
#define LCD_RW_TRIS	TRISA1 
#define LCD_DATA_TRIS	TRISD


#define FOURBIT_MODE	0x0
#define EIGHTBIT_MODE	0x1
#define OUTPUT_PIN      0x0	
#define INPUT_PIN       0x1	
#define OUTPUT_DATA     0x0F	
#define INPUT_DATA      0xFF	

#define LCD_STROBE()	LCD_EN = 1; asm("nop"); asm("nop"); LCD_EN = 0

#define LCD_STROBE_READ(value)	LCD_EN = 1; \
				asm("nop"); asm("nop"); \
				value=LCD_DATA_PORT; \
				LCD_EN = 0; 

#define	lcd_cursor(x)			lcd_cmd(((x)&0x7F)|0x80)
#define lcd_clear()			lcd_cmd(0x1)
#define lcd_putch(x)			lcd_data(x)
#define lcd_goto(x)			lcd_cmd(0x80+(x));
#define lcd_cursor_right()		lcd_cmd(0x14)
#define lcd_cursor_left()		lcd_cmd(0x10)
#define lcd_display_shift()		lcd_cmd(0x1C)
#define lcd_home()			lcd_cmd(0x2)
#define lcd_write(x)		lcd_data(x)
extern void lcd_cmd(unsigned char);
extern void lcd_data(unsigned char);
extern void lcd_puts(const char * s);
extern void lcd_init(unsigned char);
//********************************************
//		LCD FUNCTION				B
//
//********************************************

//1 Prints text on Lcd starting from specified position. 
//  Both string variables and literals can be passed as a text.
extern void lcd_Out(const unsigned char row ,const unsigned char column, const unsigned char *text);

//2  Print out CHAR to specific row and column
extern void lcd_Out_Cp(char row , char column,  char cp);


//3 clear the row of lcd
extern void  lcd_RowClr(char row);
// 4 Convert integer number to  a set of string, then write to lcd
extern void lcd_intToStr(char row, char col,const unsigned int input,char p_offset);

//5 To custom bulid character
extern void lcd_CustomLd(char location,const char* logo);





#endif

