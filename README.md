# PIC18F4580 Embedded Practicals

A collection of hands-on **Embedded C practical projects** developed
using the **PIC18F4580 microcontroller** with a **20 MHz crystal
oscillator**.

These practicals are implemented and tested on **PIC18F4580 hardware**
and cover GPIO, 7-segment display, ADC, CCP/PWM, DC motor control,
external interrupts, keypad, LCD, Timer0, and UART.

## About This Repository

The purpose of this repository is to document practical learning and
hands-on implementation of PIC18F4580 peripherals and embedded
programming concepts.

The projects focus on:

-   Embedded C programming
-   PIC18F4580 register-level programming
-   Digital input and output
-   Peripheral interfacing
-   Timers and delays
-   External interrupts
-   ADC
-   CCP/PWM
-   DC motor control
-   7-segment display
-   LCD interfacing
-   Keypad interfacing
-   UART serial communication

## Hardware and Software

### Hardware

-   Microcontroller: **PIC18F4580**
-   Crystal Oscillator: **20 MHz**
-   LEDs
-   Push buttons / switches
-   7-segment display
-   16×2 LCD
-   4×4 keypad
-   Potentiometer
-   DC motor
-   Motor driver
-   UART interface
-   ADC input devices
-   PIC programmer / development board

### Software

-   IDE: **MPLAB**
-   Compiler: **Microchip C18**
-   Programming Language: **Embedded C**
-   Simulation: **Proteus**
-   Version Control: **Git / GitHub**

## Clock Configuration

All timing-related practicals are developed using a **20 MHz crystal
oscillator**.

PIC18F4580 instruction-cycle frequency:

``` text
Fosc = 20 MHz

Instruction Frequency = Fosc / 4
                      = 20 MHz / 4
                      = 5 MHz

Instruction Cycle = 1 / 5 MHz
                  = 0.2 µs
```

This clock configuration is considered for timing calculations involving
Timer0, delays, UART baud rates, PWM, and other time-dependent
peripherals.

## Project Structure

``` text
PIC18F4580-Embedded-Practicals/
│
├── 01_3_LED/
├── 02_3_SW_3_LED/
├── 03_7Segment/
├── 04_ADC/
├── 05_CCP/
├── 06_DC_Motor/
├── 07_Ext_Interrupt_0/
├── 08_Keypad/
├── 09_LCD/
├── 10_Timer0/
├── 11_UART/
│
├── README.md
└── .gitignore
```

## Practical Projects

    No. Project                Main Concepts
  ----- ---------------------- ------------------------------
     01 3 LED                  GPIO, Digital Output
     02 3 Switch 3 LED         Digital Input / Output
     03 7-Segment              Display Interfacing
     04 ADC                    Analog-to-Digital Conversion
     05 CCP                    CCP / PWM
     06 DC Motor               Motor Control, PWM
     07 External Interrupt 0   Interrupt Handling
     08 Keypad                 4×4 Matrix Keypad
     09 LCD                    16×2 LCD Interfacing
     10 Timer0                 Timer, Delay Generation
     11 UART                   Serial Communication

## 01. 3 LED

### Concepts

-   GPIO configuration
-   Digital output
-   TRIS registers
-   PORT registers
-   LED control
-   Software delays

### Objective

To understand GPIO output configuration and control multiple LEDs using
the PIC18F4580.

## 02. 3 Switch 3 LED

### Concepts

-   Digital input
-   Digital output
-   Switch interfacing
-   Pull-up / pull-down concepts
-   Conditional control

### Objective

To read switch inputs and control LEDs according to the input
conditions.

## 03. 7-Segment Display

### Concepts

-   7-segment interfacing
-   Common Cathode
-   Common Anode
-   Digit encoding
-   Multiplexing
-   GPIO control

### Objective

To display numerical values using a 7-segment display.

## 04. ADC

### Concepts

-   Analog input
-   ADC configuration
-   ADCON registers
-   Analog channel selection
-   ADC conversion
-   ADC result reading

### Objective

To convert an analog input voltage into a digital value using the
PIC18F4580 ADC peripheral.

## 05. CCP / PWM

### Concepts

-   CCP module
-   PWM generation
-   Duty cycle
-   PWM frequency
-   Timer2
-   CCP registers

### Objective

To generate PWM using the PIC18F4580 CCP peripheral and understand
duty-cycle control.

## 06. DC Motor

### Concepts

-   DC motor interfacing
-   Motor driver
-   GPIO control
-   PWM
-   Speed control
-   Direction control

### Objective

To control a DC motor using the PIC18F4580.

> A suitable motor driver or transistor/MOSFET driver stage must be
> used. The motor should not be connected directly to a PIC GPIO pin.

## 07. External Interrupt 0

### Concepts

-   External interrupt
-   INT0
-   Interrupt enable
-   Interrupt flag
-   Interrupt service routine
-   Edge detection

### Objective

To understand interrupt-driven programming using the PIC18F4580 INT0
external interrupt.

## 08. Keypad

### Concepts

-   4×4 matrix keypad
-   Row and column scanning
-   Digital input/output
-   Key detection
-   Debouncing

### Objective

To interface a matrix keypad with the PIC18F4580 and detect individual
key presses.

## 09. LCD

### Concepts

-   16×2 LCD
-   8-bit interfacing
-   LCD commands
-   LCD data
-   RS, RW and Enable control
-   Character and string display

### Common LCD Commands

``` text
0x38  -> 8-bit mode, 2-line display
0x0E  -> Display ON, cursor ON
0x01  -> Clear display
0x06  -> Increment cursor
0x80  -> First-line starting position
```

### Objective

To initialize and control a 16×2 character LCD using the PIC18F4580.

## 10. Timer0

### Concepts

-   Timer0 configuration
-   Timer mode
-   Prescaler
-   Timer registers
-   Overflow
-   Delay generation
-   Timer interrupts

### Objective

To generate accurate time delays and periodic events using Timer0.

Timing calculations are based on:

``` text
Crystal = 20 MHz
Fosc / 4 = 5 MHz
Instruction cycle = 0.2 µs
```

## 11. UART

### Concepts

-   UART / USART
-   Serial communication
-   TX
-   RX
-   Baud rate
-   SPBRG
-   TXSTA
-   RCSTA
-   Transmit
-   Receive

### Objective

To implement asynchronous serial communication using the PIC18F4580
USART peripheral.

## Development Workflow

``` text
Write Embedded C Program
          ↓
Configure PIC18F4580 Registers
          ↓
Compile Using Microchip C18
          ↓
Generate HEX File
          ↓
Program PIC18F4580
          ↓
Connect Hardware
          ↓
Test Practical
          ↓
Debug and Improve
```

Proteus can be used for circuit simulation and verification where
applicable.

## Hardware Implementation

These projects are primarily focused on **hands-on hardware
implementation**.

The typical workflow is:

1.  Write the Embedded C program.
2.  Configure the required PIC18F4580 registers.
3.  Compile using Microchip C18.
4.  Generate the HEX file.
5.  Program the PIC18F4580.
6.  Connect the required peripheral circuit.
7.  Power and test the circuit.
8.  Debug hardware and software as required.

## Simulation

Proteus may be used as an additional development and debugging tool for:

-   Circuit verification
-   Peripheral testing
-   Program debugging
-   Timing verification
-   Understanding circuit connections

The primary focus of this repository is **practical hardware
implementation**, not simulation alone.

## Learning Outcomes

Through these practicals, the following concepts are practiced:

-   Microcontroller GPIO programming
-   Register-level programming
-   Embedded C
-   Peripheral configuration
-   Hardware interfacing
-   Timing calculations
-   Interrupt-driven programming
-   ADC operation
-   PWM generation
-   Motor control
-   LCD interfacing
-   Keypad scanning
-   UART communication
-   Embedded hardware/software debugging

## Future Improvements

Additional PIC18F4580 practicals can be added, including:

-   Timer1
-   Timer2
-   CCP Capture Mode
-   CCP Compare Mode
-   EEPROM
-   I²C
-   SPI
-   RTC interfacing
-   Temperature sensor interfacing
-   GSM interfacing
-   Bluetooth interfacing
-   Sensor-based projects
-   ADC-based measurement systems
-   Advanced PWM motor-control projects

## Hardware Safety

When working with the PIC18F4580:

-   Do not connect motors directly to GPIO pins.
-   Use suitable driver circuitry for motors and high-current loads.
-   Use current-limiting resistors with LEDs.
-   Verify the power supply before connecting the microcontroller.
-   Check pin configuration before applying power.
-   Use the correct crystal and oscillator capacitor configuration.
-   Avoid short circuits on GPIO pins.
-   Verify all hardware connections before powering the circuit.

## Author

**Raju Malekar**

Electronics Engineer \| Embedded Systems Enthusiast

### Areas of Interest

-   Embedded Systems
-   Microcontrollers
-   Embedded C / C++
-   Electronics
-   Hardware Interfacing
-   Real-Time Systems

## Technologies Used

``` text
Microcontroller : PIC18F4580
Clock           : 20 MHz
Language        : Embedded C
Compiler        : Microchip C18
IDE             : MPLAB
Simulation      : Proteus
Version Control : Git / GitHub
```

## License

This repository is intended primarily for educational and learning
purposes.

Feel free to explore the source code and use the projects as a reference
for learning PIC18F4580 Embedded C programming.
