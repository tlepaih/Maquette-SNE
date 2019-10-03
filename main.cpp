#include "mbed.h"

/* Ce programme génère un signal PWM sur une sortie numérique.
 * Le but étant de tester les limites en fréquence et en rapport cyclique.
 */

int main()
{
    PwmOut myPWM(PC_8);
    myPWM.period_us(75); // On set la période

    while(true)
    {
        myPWM.write(0.2); // Rapport cyclique entre 0 et 1
    }
}
