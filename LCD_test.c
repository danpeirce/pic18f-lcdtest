//***************************************************************************************
// 
// APSC1299 first project. Note 2x8 LCD must be connected to 
// 3pi robot.  
// adapted from LCD_test.c for sparkfun serial LCD 2x16 
// on May 29, 2019 which was
// adapted from helloWorld.c Nov. 30, 2010 by Dan Peirce
// helloWorld.c was by
// Mike Coombes, 25 May 2007 
//
//***************************************************************************************
 
#include <xc.h>
#include <stdio.h>          // library containing printf() function
#include <delays.h>
#include "osc.h"            // library for set_osc_32MHz()
#include "configureUSART.h" // library for configureUSART(baud)

char buffer[] = { 0xB7, 0xB8, 0x03, 'K', 'P', 'U', 0xB9, 0x00, 0x01, 0xB8, 0x08, 'A', 'P', 'S', 'C', '1', '2', '9', '9','\0'};

void main(void)  // a C project can only have one main() function
{
	
	set_osc_32MHz(); // set MCU to run at 32 MHz
					 // fOSC = 32 000 000 Hz
                     // TOSC = 1/32 000 000 s = 31.25 ns
                     // TCY = 4*TOSC = 125 ns 	
	configureUSART(115200); // configure MCU serial communication module to run at 9600 baud 
                          // defined in configureUSART.c
                          // 9600 is default
                          // other choices 2 400, 4 800, 19 200, 38 400, 57 600, 115 200, 500 000, and 1 000 000  

    //wait for splash screen to finish just over 1 second

    Delay10KTCYx(200); // wait 10 000 * 200 * TCY = 0.250 seconds 
//    printf("%c",0x12); // reset to 9600 bps

//   printf("%c%c",0xFE   ,0x0C);    // turn cursor off   
    Delay10KTCYx(200); // Delay10KTCYx(num), num can only range from 1 to 255 
    Delay10KTCYx(200); 
    Delay10KTCYx(200);     
    Delay10KTCYx(190);  
    Delay10KTCYx(190);
    Delay10KTCYx(200); // Delay10KTCYx(num), num can only range from 1 to 255 
    Delay10KTCYx(200); 
    Delay10KTCYx(200);     
    Delay10KTCYx(190);  
    Delay10KTCYx(190);
    
    //putch(0xB7);
    //Delay10KTCYx(19); 
    //putch(0xB8);
    //Delay10KTCYx(1);
    //putch(0x03);
    //Delay10KTCYx(1);
    //printf("K");
    //Delay10KTCYx(1); 
    //printf("P");
    //Delay10KTCYx(1); 
    //printf("U");
    //Delay10KTCYx(1);
    //putch(0xB9);  // place cursor
    //Delay10KTCYx(1);
    //putch(0x00);  // column zero
    //Delay10KTCYx(1);
                   // note cannot include null in a string!
    //putch(0x01); // second row
    //Delay10KTCYx(1);
    //putch(0xB8); // send string to LCD
    //Delay10KTCYx(1);
    //putch(0x08); // eight characters 
    //Delay10KTCYx(1);
    //printf("APSC1299");
    { 
        char i=0;
        int wait = 0;
        while(i<19)
        {
            if(TRMT)  //TXIF
            {
                TXREG = buffer[i];
                i++;
                //wait = 3;
            }
            //if(TRMT && wait) wait--;
        }
     }
	while(1)
	{
        
		  // MCUs run continuouslly so an endless loop is required.
	}
}	

