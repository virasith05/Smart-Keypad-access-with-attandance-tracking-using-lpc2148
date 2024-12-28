#include<lpc214x.h>
#include<string.h>
#include"timerdelay.h"
#include"lcd.h"
#include"keypad.h"

char flag=0; //This variable keeps track of whether a new password is being set. 
             //It starts as 0 (no new password).
						 
char pwd[]="1234"; //This is the default password. It's set to "1234", 
                   //but the user can change it by entering a new password.
void lock(void);

int main(void)
{
 char key[5]; //This array is used to store the keys entered by the user (the password).
 int con=0; //This is a counter used in loops for entering and comparing the password.
 lcd_init(); //This initializes the LCD to display messages.
 lcd_cmd(0x01); //This clears the LCD screen.
 lcd_string("press password"); //This displays the message "press password" on the LCD 
	                             //to prompt the user.
	
 flag=get_key(); //This waits for a key to be pressed on the keypad.
	               //If the key pressed is #, it enters a new password mode.
	
 if(flag=='#') //If the key pressed is #, the program proceeds to set a new password.
 { 
  lcd_cmd(0x01); //Clears the LCD again to show the new message.
  lcd_string("New pwd : "); //Displays the message "New pwd : " on the LCD.
  for(con=0;con<4;con++){ //This loop allows the user to enter a 4-digit new password.
  pwd[con]=get_key(); //This stores each key pressed by the user in the pwd array.
  lcd_string("*");} //Displays * on the LCD for each key entered (to hide the 
	                  //password input).
     pwd[con]=0; //Adds a null character at the end of the password to 
	               //terminate the string.
   }
 
  while(1){ //This starts an infinite loop that constantly checks for user input.
 lcd_cmd(0x01); //Clears the LCD screen.
 lcd_string("password:"); //Displays the message "password:" to prompt the user to 
		                      //enter the password.
 for(con=0;con<4;con++){ //This loop allows the user to enter a 4-digit password.
	 if (IO0PIN & bit(21)) { //This checks if the button connected to GPIO pin 21 is pressed.
               		         //If it is, the lock() function is called.
          lock();
	 }
  key[con]=get_key(); //This stores the key pressed by the user in the key array.
  lcd_string("*");} //Displays * on the LCD for each key entered.
  key[con]=0; //Adds a null character to the end of the entered password to terminate 
	            //the string.
	
  if(strcmp(key,pwd)!=0) //This compares the entered password (key) with the stored 
		                     //password (pwd).
		                     //If the passwords don't match, the following message is 
	                       //shown: Wrong Password
  {
  lcd_cmd(0x20); //This clears the LCD screen and prepares to display the message.
    lcd_cmd(0x01);
  lcd_string("Wrong password"); ///Displays the message "Wrong password" 
		                            //if the entered password doesn't match the stored password.
  }
  else { //If the entered password is correct, it calls the lock() 
		     //function to open the lock.
		lock();
  }
}
}


void lock(void)
{
 IO0DIR|=bit(19)|bit(20); //Sets GPIO pins 19 and 20 as output pins.  
	                        //These pins control the lock mechanism.
	
 lcd_cmd(0x01); //Clears the LCD screen.
 lcd_string("lock is opening"); //Displays the message "lock is opening".
 IO0SET|=bit(19); //Sets GPIO pin 19 high, activating the mechanism to open the lock.
 timemdel(50); //Creates a small delay using the timemdel function to keep the 
	             //lock open for a short time.
	
 IO0CLR|=bit(19); //Sets GPIO pin 19 low, deactivating the lock.
 timemdel(100); //Creates a longer delay.
 lcd_cmd(0x01); //Clears the LCD again.
 lcd_string("lock is closing"); //Displays the message "lock is closing".
 IO0SET|=bit(20); //Sets GPIO pin 20 high, activating the mechanism to close the lock.
 timemdel(50); //Creates a small delay.
 IO0CLR|=bit(20); //Sets GPIO pin 20 low, deactivating the lock.
}
