// carry out the test function for ethernet 

void test_ethernet(void);




//********************************************
//		LCD FUNCTION				A
//----------------------------------------- FUNCTION IN  lcd.h
//********************************************

// 1-- void    lcd_cmd(unsigned char c)  	/* send a command to the LCD */

// 2 -- void lcd_data(unsigned char c)   /* send data to the LCD */

// 3 -- void  lcd_puts(const char * s)     /* write a string of chars to the LCD */
 
// 4-- void lcd_init(unsigned char mode)  /* initialize the LCD */

//********************************************
//		LCD FUNCTION				B
//
//********************************************
//1  Both string variables and literals can be passed as a text.
// void lcd_Out(const unsigned char row ,const unsigned char column,const unsigned  char *text);

//2  Print out CHAR to specific row and column
// void lcd_Out_Cp(char row , char column, char cp);
//3 clear the row of lcd
// void lcd_RowClr(unsigned char row);

// 4 Convert integer number to  a set of string, then write to lcd
// void lcd_intToStr(char row, char col,const unsigned int input,char p_offset);


//5 To custom bulid character
// void lcd_CustomLd(char location,const char* logo);
//6 initialise setting to set up 8 logo  
// void bulid_customChar(void);

//7  
//  void display_lcd_Inform(unsigned char display);


//********************************************
//		DELAY FUNCTION
//
//********************************************

//  extern void DelayMs(unsigned char);  /* in delay.h
void DelaybySec(unsigned char cnt);



void main_startUp(void);



