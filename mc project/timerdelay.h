
/*---- Timerdelay Header File ----*/
void timemdel(unsigned int con) {
    T0CTCR = 0x0; //This sets the Timer 0 Control Register (T0CTCR) to 0x0, which configures Timer 0 to 
	                //use the default timer mode (counting the clock).
                  //This ensures Timer 0 operates normally (not in external event mode or other special modes).
	
    T0PR = 59999; //This sets the Timer 0 Prescale Register (T0PR) to 59999.
                  //This means that Timer 0 will count from 0 to 59999 before triggering an event. 
	                //Essentially, the prescaler divides the system clock frequency by 60,000. 
	                //If the system clock is 60 MHz, this would create a 1 kHz timer (1 ms time period).
	
    T0MR0 = con; //This sets the Match Register 0 (T0MR0) to the value con passed to the function.
                 //T0MR0 determines the timer's countdown limit. 
	               //The timer will count from 0 up to the value in T0MR0, 
	               //and when it reaches that value, it will trigger a match event.
	
    T0MCR |= 1 << 2; //This modifies the Match Control Register (T0MCR), specifically setting the 
	                   //third bit (bit 2) to 1.
                     //This tells the timer to reset the timer when the match occurs (when the timer 
	                   //reaches the value in T0MR0).
	
    T0TCR = 0x02; //This sets the Timer Control Register (T0TCR) to 0x02, which stops the timer.
                  //This is a reset step to make sure the timer is not running before starting it again.
	
    T0TCR = 0x01; //This sets the Timer Control Register (T0TCR) to 0x01, which starts the timer.
                  //This begins counting from 0, and it will trigger a match when it reaches the value in T0MR0.
									
    while (T0TC != T0MR0); //This line waits in a loop until the Timer 0 Counter Register (T0TC) 
		                       //equals the value in T0MR0.
                           //Essentially, the program will pause here until the timer finishes counting.
													 
    T0TC = 0; //This clears the Timer 0 Counter Register (T0TC), resetting the timer counter to 0.
		
    T0TCR = 0; //This stops the timer by setting the Timer Control Register (T0TCR) to 0.
              //The timer is now off and ready to be used again if needed.
}

void timeudel(unsigned int con) { //This function works in the same way as the timemdel function 
	                                //but uses Timer 1 instead of Timer 0.
	
    T1CTCR = 0x0; //This sets the Timer 1 Control Register (T1CTCR) to 0x0, ensuring that 
	                //Timer 1 works in normal mode (not in external event mode).
	
    T1PR = 59; //This sets the Timer 1 Prescale Register (T1PR) to 59.
               //The timer will count from 0 to 59 before triggering a match. 
	             //This makes the timer run at 1 MHz if the system clock is 60 MHz (this is similar to Timer 0).
	
    T1MR0 = con; //This sets the Match Register 0 (T1MR0) to the value of con passed to the function.
                 //This determines when the timer will match and stop counting.
	
    T1MCR |= 1 << 2; //This sets bit 2 of the Match Control Register (T1MCR), which causes the 
	                   //timer to reset when it matches the value in T1MR0.
	
    T1TCR = 0x02; //This stops Timer 1 by writing 0x02 to the Timer Control Register (T1TCR).
	
    T1TCR = 0x01; //This starts Timer 1 by writing 0x01 to the Timer Control Register (T1TCR).
	
    while (T1TC != T1MR0); //This line makes the program wait in a loop until the timer reaches 
	                         //the match value (the value in T1MR0).
													 
    T1TC = 0; //This resets the Timer 1 Counter Register (T1TC) to 0, effectively clearing the counter.
		
    T1TCR = 0; //This stops Timer 1 by setting the Timer Control Register (T1TCR) to 0.
}


//How This is Used in Your Project:
//Both timemdel and timeudel functions are used to create delays in your project using hardware timers. 
//These delays might be required for several tasks such as:

//Keypad Scanning: You may need to introduce small delays between scanning different keys to ensure the correct key is detected.
//LCD Display Control: Some LCD commands require delays (e.g., clearing the screen, moving the cursor) to be processed correctly.
//Timing of Events: Delays might be required in your SOS alert device or Bluetooth speaker system to wait for specific events,such as ensuring enough time passes between sending data or receiving commands.

