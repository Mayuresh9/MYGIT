

/**
 * main.c
 */
#include "stdint.h"
#include "stdbool.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

int main(void)
{
    int k=0;

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_1);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE,GPIO_PIN_4);
    GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
   // k=GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
    GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,0x00);
    while(1)
    {
        k=GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
    if(k!=GPIO_PIN_4)
    {
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,0xFF);
        SysCtlDelay(1000000);
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,0x00);
        SysCtlDelay(1000000);
    }
    //GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,0x00);
    }

}
