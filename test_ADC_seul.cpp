#include "mbed.h"

AnalogIn signal(PA_3);

Serial pc(USBTX, USBRX, 9600);

int main() {
    
    Timer timer;
    
    float data;
    unsigned char i;
    float duree, Fe;
    
    while(1) {
        
        i=100;
        
        timer.start();
        
        do {
            data = signal.read();
            i--;
        } while( i != 0 );
        
        timer.stop();
        
        duree = timer.read_us();
        duree /= 100;
        Fe = 1/duree;
        
        timer.reset();
        
        pc.printf("Periode echantillonnage : %.2f us --- Fe = %.6f MHz\n\r", duree, Fe);
        
        wait(1.0f);  
    }
}
