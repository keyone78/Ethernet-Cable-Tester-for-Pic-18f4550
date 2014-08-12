// FILE INCLUDE  
#include <htc.h>
#include <pic18.h>
#include <math.h>
//#include <stdio.h>
#include <stdlib.h>
//#include <stddef.h>
#include <string.h>


#include "delay.h"

#include  "lcd.h"
#include "deve_Marco.h"
#include "ether_cable.h"

//End OF FILE INCLUDE  



					

 
 


//END of cost variable
//LCD variable


static bit fourbit;		// four or eight bit mode?

unsigned int no_of_rec=0;

unsigned char null=0x00;
//END of Global Variable





//********************************************
//		DELAY FUNCTION
//
//********************************************
void DelaybySec(unsigned char cnt){  
   char n=0;
	for(n=0;n<cnt*4;n++)
      DelayMs(250);

}






void test_ethernet(void){


  
    unsigned char passResult[9]={'>',9,3,0,9,6,7,8};   // array of 8 slot 1 to 8
	unsigned char passNum=0,openline=0;  // passNum indicate the number, openline 
	
	 lcd_clear();                       // LCD clear
     lcd_Out(1,0,"No:");       // display "No:"
	 DelayMs(10);	                // delay for 10 ms
    
	
	for (int n=1;n<9;n++)                           
	 passResult[n]=single_modeTest(n);       // test result load to array slots
    
	
   
	 for(int n=1 ;n<9;n++) {	                     
	
	   if(passResult[n]=='F'){                      // check the error connect to where.
		
		for(int ck_line=1 ;ck_line<9;ck_line++)
		
			if(connect_error(n,ck_line)!='X') {                           
		
			  lcd_Out_Cp(1,n+2, connect_error(n,ck_line) +48); // display the error connect to  which pin
			  DelayMs(2);
			 
			 }   
		    else{
			
			openline++;
		       if(openline==8)     // if no error detect after tested all pin...
		       lcd_Out_Cp(1,n+2,'X'); //....it may be open line   
						
           
		    }
        }
	  else{
	    lcd_Out_Cp(1,n+2, n+48);  // pass just display the pin no to LCD
	  
	   
	  }
	}
	
	
	
	 for(int n=0 ;n<9;n++)  {                   // check for number of  pass
     lcd_Out_Cp(2,n+2, passResult[n] );    // dsiplay to lCD
      if(passResult[n]=='P')
	   passNum++;
	   
	 }
	 
    if(passNum==8)
	  lcd_Out(2,11," Pass");
	  
	else
	   lcd_Out(2,11," Fail");
  
       
  }



void main_startUp(void){

	
	DelayMs(250);
	Gobal_inter =DisEnable; 
  	Keypad_inter=DisEnable;    // RBIE= 0;	
	
	ADIE=0;						/* not interrupt driven */
	ADCON0 = 0;     			
	ADCON1 = 0X0F;  			//All port in digital mode
	CMCON  = 7;      			 //comparators off
	
 TRISD = 0x00;
 TRISC = 0x00;
  TRISA = 0x00;
  TRISB = 0x00;
  TRISE= 0x00;
  PORTA = 0x00;
  PORTD = 0x00;
  PORTE=0x00;
  PORTC= 0x00;
  LATC=0x00;
    // Glcd_init();
 	lcd_init(FOURBIT_MODE);		// LCD  initization 
	lcd_clear();
	
	

	entherAA=flash_all_zero;
	entherAA_dir= dir_out;   // Ethernet A1 to A3
         entherAA=all_high;
	
	entherAB=flash_all_zero;   // all to zero 
	entherAB_dir =dir_out;    // port A output
	entherAB=all_high ;       // clear

	entherB_dir=dir_in;    // port B is input port 
	entherB=flash_all_zero;
      
	
 //	lcd_noCursor();			    // clear off the cursor  
 	//bulid_customChar();			// setup the custom  character
	//LCD_LIGHT=ON;				// turn no lcd light
	
}











