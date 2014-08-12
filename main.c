
#include <stdio.h>

#include <htc.h>
#include <pic18.h>
#include "delay.h"

#include "deve_lib.h"
#include "lcd.h"
#include "deve_Marco.h" 
#include "ether_cable.h"




void main(void){
	Gobal_inter =DisEnable;   // disabled gobal interrupt
  	Keypad_inter=DisEnable;    // RBIE= 0;	

    main_startUp();      // initial pin port
	 DelayMs(250);	
	
while (1){


    test_ethernet();          
    DelayMs(250);
    DelayMs(250);
      }

  
    
	   
	   
	   
	   
	   
}


void interrupt isr(void)	 {

 

}
