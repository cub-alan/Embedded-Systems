#include "mbed.h"

// Create a DigitalOut “object” called greenLED. Pass constant LED1 as a “parameter”
DigitalOut greenLED(LED1);

//These are "commented out" and so are not part of the program. You can uncomment them by removing the // characters
//Your task is to make a sequence alternating between Green+Red and just Blue 
DigitalOut blueLED(LED2);
DigitalOut redLED(LED3);

//The main function - all executable C / C++ applications have a main function. This is our entry point in the software
int main() 
{
    // turn blue led on
    blueLED = 1;
    // ALL the repeating code is contained in a  “while loop”
    while(true) 
    { 
        //The code between the { curly braces } is the code that is repeated forever

        // Turn green LED ON  / red led off
        greenLED = 1; 
        redLED = 0;
        // Wait
        wait_us(100000); 

        // Turn green LED OFF / red led on
        greenLED = 0;
        redLED = 1;

        // wait
        wait_us(100000);
    }
}