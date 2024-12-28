/*----Keypad Header File------*/
#define c1 (1<<20)  //c1, c2, c3 represent the columns of the keypad (connected to pins 20, 21, 22).
#define c2 (1<<21)
#define c3 (1<<22)
#define r1 (1<<16)  //r1, r2, r3, r4 represent the rows of the keypad (connected to pins 16, 17, 18, 19).
#define r2 (1<<17)
#define r3 (1<<18)
#define r4 (1<<19)

char get_key(void)  //This function will scan the keypad and return the key pressed by the user.
{
 IO1DIR=0x0f<<16;  //This sets the direction of the pins for rows (pins 16-19). 
	                 //It configures the first 4 pins (16-19) to output (for rows) and leaves the 
	                 //rest of the pins as input. 
	                 //IO1DIR is the direction register of Port 1.
	
  IO1CLR|=0xFF<<16;  //This clears the output pins connected to the rows (pins 16-19), setting them to low.
 IO1SET|=0xFF<<16;  //This sets the output pins connected to the rows (pins 16-19) to high.
	
	
 while(1)  //This is an infinite loop to continuously scan the keypad until a key is pressed.
 {
	 
	 
   IO1CLR|=r1; //IO1CLR|=r1 clears (sets low) the row r1 (pin 16).
  IO1SET|=0x0E<16; //IO1SET|=0x0E<<16 sets the columns c1, c2, c3 (pins 20, 21, 22) to high.
   if((IO1PIN&c1)==0)  //(IO1PIN&c1)==0 checks if the c1 (pin 20) is low (meaning the key is pressed).
                   		 //If yes, it returns the key '1'.
   {
     while((IO1PIN&c1)==0);
  return '1';
   }
   else if((IO1PIN&c2)==0) //Similarly, if c2 or c3 (pins 21 or 22) are low, it returns '2' or '3'.
   {
     while((IO1PIN&c2)==0);
  return '2';
   }
   else if((IO1PIN&c3)==0)
   {
     while((IO1PIN&c3)==0);
  return '3';
   }
	 
//This block checks the columns to return '4', '5', or '6' depending on which column is pressed.	 
    IO1CLR|=r2;  //IO1CLR|=r2 clears row r2 (pin 17).
  IO1SET|=0x0D<<16;  //IO1SET|=0x0D<<16 sets the columns c1, c2, c3 (pins 20, 21, 22) to high.
    if((IO1PIN&c1)==0)
   {
     while((IO1PIN&c1)==0);
  return '4';
   }
  else if((IO1PIN&c2)==0)
   {
     while((IO1PIN&c2)==0);
  return '5';
   }
  else if((IO1PIN&c3)==0)
   {
     while((IO1PIN&c3)==0);
  return '6';
   }
	 
	
//This block checks the columns to return '7', '8', or '9' depending on which column is pressed.	 
   IO1CLR|=r3;  //IO1CLR|=r3 clears row r3 (pin 18).
  IO1SET|=0X0B<<16; //IO1SET|=0x0B<<16 sets the columns c1, c2, c3 (pins 20, 21, 22) to high.
    if((IO1PIN&c1)==0)
   {
     while((IO1PIN&c1)==0);
  return '7';
   }
  else if((IO1PIN&c2)==0)
   {
     while((IO1PIN&c2)==0);
  return '8';
   }
  else if((IO1PIN&c3)==0)
   {
     while((IO1PIN&c3)==0);
  return '9';
   }
	 
	
//This block checks the columns to return '*', '0', or '#' depending on which column is pressed.	 
  IO1CLR|=r4; //IO1CLR|=r4 clears row r4 (pin 19).
   IO1SET|=0X07<<16; //IO1SET|=0x07<<16 sets the columns c1, c2, c3 (pins 20, 21, 22) to high.
       if((IO1PIN&c1)==0)
   {
     while((IO1PIN&c1)==0);
  return '*';
   }
  else if((IO1PIN&c2)==0)
   {
     while((IO1PIN&c2)==0);
  return '0';
   }
  else if((IO1PIN&c3)==0)
   {
     while((IO1PIN&c3)==0);
  return '#';
   }
 }
}
