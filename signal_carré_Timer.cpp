/* 
 * Générer un signal carré à l'aide du timer du la carte
 */

#include "mbed.h"

AnalogOut Aout(PA_4);

int main(void) {

    Timer timer;
    unsigned char lvl = 0;

    timer.start();

    while(true) {
        
        Aout = (float)lvl;

        if(timer.read_us() >= 1) {
            
            // Inversion du niveau de la sortie
            lvl ^= 1;

            // Reset du timer
            timer.stop();
            timer.reset();
            timer.start();
        }   
    }
}
