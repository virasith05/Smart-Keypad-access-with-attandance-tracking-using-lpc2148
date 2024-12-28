# Smart Keypad Access with Attendance Tracking Using LPC2148  

This project is a comprehensive implementation of a secure access control system integrated with an attendance tracking mechanism, built using the LPC2148 microcontroller. It includes hardware simulations (Proteus), source codes, and a detailed project report, all organized within a project folder.

---

## **System Overview**

### 1. **User Authentication and Door Access**  
   - The system initializes by displaying a welcome message on the LCD, prompting users to enter the password via the keypad.  
   - The LPC2148 microcontroller verifies the entered password against the stored credentials.  
   - Upon a successful match:  
     - The door is opened by rotating the motor in the clockwise direction.  
     - The Seven-Segment Display increments the attendance count by 1.  
   - After a short delay, the door automatically closes with the motor rotating in the anticlockwise direction.  

### 2. **Attendance Tracking**  
   - Every successful password entry updates the attendance count.  
   - The LPC2148 sends a pulse signal to increment the attendance count, which is displayed in real time on the Seven-Segment Display.  
   - The system ensures a seamless combination of access control and attendance management.

---

## **Project Folder Contents**

1. **Proteus Simulation**  
   - Contains circuit diagrams for the hardware setup, including LCD, keypad, motor, Seven-Segment Display, and the LPC2148 microcontroller.  
   - The simulation file allows real-time testing of the design without requiring physical components.

2. **Source Code**  
   - Complete C code for the LPC2148 microcontroller, written and compiled using Keil µVision IDE.  
   - Well-commented and modular code for easy understanding and troubleshooting.  

3. **Project Report**  
   - A detailed document explaining the system design, hardware components, software implementation, and testing methodology.  
   - Includes schematics, flowcharts, and step-by-step explanations of the project functionality.  

---

## **Features**
- **Secure Access**: Only users with the correct password can access the system.  
- **Automated Attendance**: Attendance tracking is seamlessly integrated into the access control process.  
- **Real-Time Display**: Updates are shown instantly on the Seven-Segment Display.  
- **Simulation-Ready**: Proteus files make testing and experimentation easy for learners and developers.  

---

## **Contact Information**  
For queries, suggestions, or collaboration:  
- **Email**: virasith1234@gmail.com  
- **Mobile**: +91 8555053321 
