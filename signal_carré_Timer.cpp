/* 
 * Générer un signal carré à l'aide du timer du la carte
 */

#include "mbed.h"

DigitalOut clk(D7);

int main(void) {

    Timer timer;
    unsigned char lvl = 0;

    timer.start();

    while(true) {
        
        clk = lvl;

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
