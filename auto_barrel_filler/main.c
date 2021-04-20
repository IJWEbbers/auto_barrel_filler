#define F_CPU 16000000

#include <avr/io.h>

void floatSwitchInit(void)
{
	DDRD &= ~(1<<0);	//set pinD0 as input
	PORTD |= (1<<0); //use pull-up resistor on pinD0
	
	DDRD &= ~(1<<1);	//set pinD1 as input
	PORTD |= (1<<1); //use pull-up resistor on pinD1
}

void relayInit(void)
{
	DDRB |= (1<<1); //set pinB1 as output
	PORTB &= ~(1<<1); //set portB1 low
}

int main(void)
{
	//Initialize the components
    floatSwitchInit();
    relayInit();
	
    	while (1)
	{			
		//if water is above required level, turn off pump
		uint8_t floatSwitchState = PIND & (1<<0);
		if (floatSwitchState == 0)
		{
			PORTB &= ~(1<<PORTB1);
			
		}
		//else turn on pump
		else
		{
			PORTB |= (1<<PORTB1);
		}
	}
}

