# Smart Keypad Access with Attendance Tracking Using LPC2148

This project features a secure access control system integrated with attendance tracking, built using the LPC2148 microcontroller. The system utilizes an LCD display, a keypad for password entry, a motor for door control, and a Seven-Segment Display for real-time attendance updates.

### System Overview

1. **User Authentication and Door Access**:  
   - Upon initialization, the LCD display welcomes the user and prompts for password entry via the keypad.  
   - The LPC2148 microcontroller verifies the entered password against the stored one.  
   - On a successful match, the system grants access, and the motor rotates clockwise to open the door.  
   - Simultaneously, the Seven-Segment Display increments by 1 to reflect successful attendance tracking.  
   - After a short delay, the door automatically closes by rotating the motor in the anticlockwise direction.

2. **Attendance Tracking**:  
   - The system keeps track of attendance for each entry into the premises.  
   - After successful authentication, the LPC2148 sends a pulse signal to update the attendance count.  
   - The Seven-Segment Display shows the latest incremented attendance count in real-time.

### Features
- **Secure Access Control**: Password-protected entry ensures only authorized access.  
- **Automatic Attendance Tracking**: The system updates attendance instantly upon successful access.  
- **Real-Time Updates**: The Seven-Segment Display provides live feedback on attendance count.  
- **Automated Door Mechanism**: The motor ensures smooth door operation with automatic open/close functionality.

### Contact Information  
For any queries or issues related to the project:  
- **Email**: virasith1234@gmail.com  
- **Mobile**: +91 8555053321
