#include "mbed.h"

DigitalIn ButtonA(PG_0); //Button A
DigitalIn ButtonB(PG_1); //button B
DigitalOut redLED(PC_2); //Red Traffic 1

// main() runs in its own thread in the OS
int main()
{
    int btnA;
    int btnB;
    // Turn OFF the red LED
    redLED = 0;

    while (true) {
    
        // Wait for the button to be pressed
        do {
            btnA = ButtonA; //Read button A
            btnB = ButtonB; //read button B
        } while (btnA == 0 || btnB == 0);


        //Toggle the red LED
        redLED = !redLED;

        //Wait for noise to settle
        wait_us(10000);

        // Wait for the button to be released
        do {
            btnA = ButtonA; //Read button A
            btnB = ButtonB; //read button B
        } while (btnA == 1 || btnB == 1);

        //Wait for noise to settle
        wait_us(10000);
    }
}

