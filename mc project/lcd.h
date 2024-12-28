/*----LCD Header File------*/
#define RS (1<<16)  //RS (Register Select): Pin 16
#define E (1<<17)   //E (Enable): Pin 17
#define D4 (1<<10)  //D4, D5, D6, D7: Data pins for the LCD (Pins 10, 11, 12, 13)
#define D5 (1<<11)
#define D6 (1<<12)
#define D7 (1<<13)


//void delay(void);
void lcd_init(void);
void lcd_cmd(int );
void lcd_string(char *str);
void lcd_conv(char );


void lcd_cmd(int cmd) //This function sends a command to the LCD (e.g., clear display, set cursor position).
{
 IOCLR0|=RS;  //Clears the RS pin (sets it to 0). This is necessary because RS should be low 
	            //for sending commands to the LCD.
	
 lcd_conv(cmd); // Calls the lcd_conv function to send the command.
 IOCLR0|=RS;
 timeudel(1000); //This function creates a delay to give the LCD enough time to 
	               //process the command (typically a microsecond delay).
}

void lcd_init(void) //This function initializes the LCD
{
 IODIR0|=D4|D5|D6|D7; // Configures the data pins D4, D5, D6, D7 as output.
  IODIR0|=RS|E; //Configures the control pins RS and E as output.
  IOCLR0|=D4|D5|D6|D7; //Clears (sets to 0) the data pins D4 to D7.
  IOCLR0|=RS|E; // Clears the control pins RS and E.
 lcd_cmd(0x02); //Initializes the LCD in 4-bit mode.
 lcd_cmd(0x28); //Sets the LCD to use 2 lines and 5x8 font.
 lcd_cmd(0x0E); //Turns the display on and enables the cursor.
 lcd_cmd(0x01); // Clears the display.
 lcd_cmd(0x06); //Sets the cursor to move to the right automatically.
}


void lcd_string(char *str) //This function displays a string on the LCD
{
 while(*str!=0) //Loops through each character in the string str until the null-terminator (\0) is reached.
 {
  IOSET0|=RS; //Sets the RS pin high, which tells the LCD to interpret the data as characters.
  lcd_conv(*str); //Converts the current character (*str) into its 4-bit representation and 
	                //sends it to the LCD.
  str++; //Moves to the next character in the string.
 }
 timeudel(1000); //Creates a small delay after the entire string is displayed.
}


void lcd_conv(char data) //This function converts the character data into two 4-bit nibbles (
	                       //high and low) and sends them to the LCD
{
 int recv;
 IOCLR0|=D4|D5|D6|D7;
 recv=data>>4; //Takes the high nibble (the top 4 bits) of the character data.
 IOSET0=recv<<10; //Sends the high nibble to the LCD via data pins D4 to D7.
 IOSET0|=E; //Enables the LCD to read the data.
 timeudel(1000); //Waits for the LCD to process the data.
 IOCLR0|=E; //Disables the LCD after sending the data.
 timeudel(1000);
	
 IOCLR0|=D4|D5|D6|D7;
 recv=data; //for low nibble(no need for shifting in this case as it's already the low nibble).
 IOSET0|=(recv<<10);
 IOSET0|=E;
 timeudel(1000);
 IOCLR0|=E;
 IOCLR0|=D4|D5|D6|D7;
}


