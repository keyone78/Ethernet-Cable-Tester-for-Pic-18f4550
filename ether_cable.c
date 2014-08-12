#include <htc.h>
#include <pic18.h>

#include "delay.h"
#include "deve_Marco.h"
 

void flash_etherA(void){  // to flash one time at port A 

	entherAA=flash_all_zero;
	DelayMs(5);
    entherAA=all_high;
	

	entherAB=flash_all_zero;
	DelayMs(5);
	entherAB=all_high ;  

}


unsigned char str_Atest_con(void){

   unsigned char num=0;
  while (num<5){    // Test for continualty in all 8 wires (5 times)
	DelayMs(2);
    flash_etherA();
	
    if(PORTB==0xff)   
		num++;
	else
	   return fail;
	   
    }
	return pass;
	
}

void entherA_low(void){

		LATE=flash_all_zero;  
		LATC =flash_all_zero;  
		LATA5=flash_all_zero;
}


void pinToHigh_Test(unsigned char num){
	
	
	entherA_low();        // All pin on enthernet A to  low,   clear all
	
	DelayMs(2);              // delay 2 ms
		                                  
	switch (num){                        // pin to '1' on  indiviual pin 
		
	case 1:entherAA_1=RUN_1; break;
	case 2:entherAA_2=RUN_1; break;
	case 3:entherAA_3=RUN_1; break;
	case 4:entherAA_4=RUN_1; break;
	case 5:entherAA_5=RUN_1; break;
	case 6:entherAA_6=RUN_1; break;
	case 7:entherAA_7=RUN_1; break;
	case 8:entherAA_8=RUN_1; break;
	default: 			     break;
	}
	DelayMs(2);
	
		
}




unsigned char single_modeTest(unsigned char seq_no){                          /** ethernet A (OUT) ---> ethernet B (IN)*/	

	 unsigned char setTestbyte[9]={0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
	
	
	  pinToHigh_Test(seq_no);                        // active high on selected pin for (ethernet port A)

	    if(entherB_test==setTestbyte[seq_no]){     // check for result at enthernet port B
		
	     return pass;}                                    // if port B result is same as setTestbyte  return "P" , pass
			
		else{
		 return fail;                                   // else fail 
 		}
		
}


// for checking wire connect to which pin rather than the correct one
unsigned char connect_error(unsigned char seq_no, unsigned char testno){

unsigned char setTestbyte[9]={0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
    
	pinToHigh_Test(seq_no);                  // active high on selected pin for (ethernet port A)

	
	
	if(entherB_test==setTestbyte[testno])
	
       return testno;
	   
	
	
    else{
   
   
       return 'X';
   }

}


