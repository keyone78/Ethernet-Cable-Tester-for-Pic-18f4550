*
 *	LCD interface example
 *	Uses routines from delay.c
 *	This code will interface to a standard LCD controller
 *	like the Hitachi HD44780. It uses it in 4 or 8 bit mode
 *	
 */

#include	<htc.h>
#include	"lcd.h"
#include	"delay.h"
 

static bit fourbit;		// four or eight bit mode?

#ifdef CHECKBUSY

unsigned char 
lcd_read_cmd_nowait(void) {
	unsigned char c, readc;

	LCD_DATA_TRIS	 = INPUT_DATA;

	LCD_RW = 1; // Read LCD
	asm("nop"); // short propagation delay
	asm("nop"); // short propagation delay

	if (fourbit) {
		LCD_STROBE_READ(readc); // Read high nibble
		// Move 4 bits to high nibble while zeroing low nibble
		c = ( ( readc << 4 ) & 0xF0 ); 
		LCD_STROBE_READ(readc); // Read low nibble
    	c |= ( readc & 0x0F ); // Or in 4 more bits to low nibble
	} else {
		LCD_STROBE_READ(readc); 
		c = readc;
	}
	LCD_RW = 0; // Return to default mode of writing LCD
	LCD_DATA_TRIS	 = OUTPUT_DATA; // Return to default mode of writing LCD

	return(c);
}

// Return when the LCD is no longer busy, or we've waiting long enough!
void
lcd_check_busy(void) {
	// To avoid hanging forever in event there's a bad or 
	// missing LCD on hardware.  Will just run SLOW, but still run.
	unsigned int retry; 
	unsigned char c;

	for (retry=1000; retry-- > 0; ) {
		c = lcd_read_cmd_nowait();
		if (0==(c&0x80)) break; // Check busy bit.  If zero, no longer busy
	}
}

#endif

/* send a command to the LCD */
void
lcd_cmd(unsigned char c)
{
	LCD_WAIT; // may check LCD busy flag, or just delay a little, depending on lcd.h

	if (fourbit) {
		LCD_DATA = ( c & 0xF0 );
		LCD_STROBE();
    		LCD_DATA =  ( ( c << 4 ) & 0xF0 );  
		LCD_STROBE();
	} else {
		LCD_DATA = c;
		LCD_STROBE();
	}
}
  
/* send data to the LCD */
void
lcd_data(unsigned char c) {
	LCD_WAIT; // may check LCD busy flag, or just delay a little, depending on lcd.h

	LCD_DATA = 0;
	LCD_RS = 1;
	if (fourbit) {
    	LCD_DATA = ( c & 0xF0 );
		LCD_STROBE();
		LCD_DATA &= 0x0F;
		LCD_DATA =  ( ( c << 4 ) & 0xF0 );  
		LCD_STROBE();
	} else {
		LCD_DATA = c;
		LCD_STROBE();
	}
	LCD_RS = 0;
}

/* write a string of chars to the LCD */

void
lcd_puts(const char * s) {
	while(*s)
		lcd_data(*s++);
}

/* initialize the LCD */
void
lcd_init(unsigned char mode) {
	char init_value;

	fourbit		= 0;
	if (mode == FOURBIT_MODE){
		fourbit = 1;
		init_value = 0x03;
	}else{
		init_value = 0x3F;
	}
	LCD_RS = 0;
	LCD_EN = 0;
	LCD_RW = 0;
	LCD_RS_TRIS	 = OUTPUT_PIN;
	LCD_EN_TRIS	 = OUTPUT_PIN;
	LCD_RW_TRIS	 = OUTPUT_PIN;
	LCD_DATA_TRIS	 = OUTPUT_DATA;
	DelayMs(15);
	LCD_DATA	 = init_value;
	LCD_STROBE();
	DelayMs(5);
	LCD_DATA	 = init_value;
	LCD_STROBE();
	DelayUs(200);
	LCD_DATA	 = init_value;
	LCD_STROBE();
	
	if (fourbit){
		LCD_WAIT; //may check LCD busy flag, or just delay a little, depending on lcd.h
		LCD_DATA = 0x2; // Set 4-bit mode
		LCD_STROBE();

		lcd_cmd(0x28); // Function Set
	}else{
		lcd_cmd(0x38);
	}
	lcd_cmd(0xF); //Display On, Cursor On, Cursor Blink
	lcd_cmd(0x1); //Display Clear
	lcd_cmd(0x6); //Entry Mode
	//lcd_cmd(0x80); //Initialize DDRAM address to zero
}

//********************************************
//		LCD FUNCTION				B
//
//********************************************

//1 Prints text on Lcd starting from specified position. 
//  Both string variables and literals can be passed as a text.
void lcd_Out(const unsigned char row ,const unsigned char column, const unsigned char *text){
/*
* Purpose: which row , column to be print

* Description:Prints text on Lcd starting from specified position. 
 Both string variables and literals can be passed as a text.
*
* Returns: NIL
*
* Requires:  lcd_Init(), lcd_write(*s++)


*  input :

* Example:  Lcd_Out(1,2,"Hello You");
*
**************************************************
*/

  if(row==1)				// 1st row 
    { lcd_goto(0x00 +column);}
 else if (row==2)			// 2nd row 
	{ lcd_goto(0x040 +column);}
 
 else  if (row==3)			// 3rd row
	{ lcd_goto(0x10 + column);}
 else  if (row==4) 		   	// 4th row 
	{ lcd_goto(0x50 + column);}
	 	
		
	LCD_RS = 1;				
   while(*text)				// print the string out 
		lcd_write(*text++); 
		


}




//2  Print out CHAR to specific row and column
void lcd_Out_Cp(char row , char column,  char cp){

/*Project water flow checker v0.1
* Date : 18th Feb 2011
*
*/
/************void lcd_Out_Cp(char row , char column,  char cp)***************************
*
* Purpose:  Print out CHAR to specific row and column
* Description: print out  char 
*
* Returns: NIL
*
* Requires: lcd_inti()

*  input : NIL

* Example:			cp='A';
*				lcd_Out_Cp(1,2,cp);
**************************************************
*/

	if(row==1)				// 1st row 
    {lcd_goto(0x00 +column);}
  else if (row==2)			// 2nd row 
	{lcd_goto(0x040 +column);}
  else if (row==3)			// 3rd row
	{lcd_goto(0x010 + column);}
  else if (row==4) 		   	// 4th row 
	{lcd_goto(0x50 + column);}
	 	
	LCD_RS = 1;				
  			
		lcd_write(cp); // print the char out 

}







//3 clear the row of lcd
void  lcd_RowClr(char row){

   
    lcd_Out(row,0,"                ");

}
