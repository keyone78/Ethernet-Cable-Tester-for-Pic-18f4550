




//history define  flag
#define clearall 1



//GOBAL INTERRUPT
#define Keypad_inter  RBIE   	  // PortB interrupt Enable bit
#define Gobal_inter   GIE		  // GIE- Global Interrupt Enable bit
#define Peri_inter    PEIE		  //	PEIE - Peripheral Interrupt Enable bit
	
#define DisEnable		0
#define Enable		   !DisEnable



// ethernet port cable define
#define entherAA     LATE    // Ethernet A1 to A3
#define entherAA_dir TRISE
#define entherAB     LATC    // Port D use by LCD
#define entherAB_dir TRISC	  // Ethernet A4 - A8 RC4 and RC5 mend for usb

#define entherB     LATB
#define entherB_dir TRISB
#define entherB_test PORTB

#define entherAA_1     LATE0
#define entherAA_2     LATE1
#define entherAA_3     LATE2
#define entherAA_4     LATC0
#define entherAA_5     LATC1
#define entherAA_6     LATC2
#define entherAA_7     LATA5
#define entherAA_8     LATC7



#define entherAB_1     LATB0
#define entherAB_2     LATB1
#define entherAB_3     LATB2
#define entherAB_4     LATB3
#define entherAB_5     LATB4
#define entherAB_6     LATB5
#define entherAB_7     LATB6
#define entherAB_8     LATB7



#define flash_all_zero 0x00

#define dir_out 0x00
#define dir_in 0xFF
#define all_high dir_in

#define pass 'P';  //  indicate Pass 
#define fail 'F';    // indicate fail

// end of ethernet port cable define
#define True  1
#define FALSE 0


//
#define RUN_1 1
#define Reset_0 0




#define TopDisplay 2
#define DownDisplay 8

// SHORTCUT OPERATOR
#define _INVERTER(A) ((!A))      // TO INVERTER  OxFF >> OxOO
#define bitset(var,bitno) ((var) |= (1 << (bitno)))    //  set that bit
#define bitclr(var,bitno) ((var) &= ~( 1 << bitno))   // clear that bit
#define bittst(var,bitno) (var & (1 << (bitno)))     // test bit is '1'
#define charToBcd_Up(var)   (var=((var-48 )<< 4) & 0xF0) // convert char to bcd - lower nipple shift to upper nipple
#define charToBcd_Lo(var)	(var=(var-48) & 0x0F) // 

#define UpBcdToLo(varA,varB)  varA=(((varB & 0xF0)>>4)& 0x0F)
#define takeBcdLo(varA,varB)  varA=(varB & 0x0F)


#define flash_charIII(var)  (var=var & 0x0FFF)

// UPDATE FLAG


#define Offset 0		// use for offset col 
#define noOffset 1
