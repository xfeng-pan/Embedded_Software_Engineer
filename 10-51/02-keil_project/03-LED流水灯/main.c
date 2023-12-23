#include <REG51.H>
#include <INTRINS.H>

void Delay1ms(void)	//@12.000MHz
{
	unsigned char data i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}

void delay_ms(int x)
{
	while(x)
	{
		Delay1ms();
		x--;
	}
}



void main()
{
	while(1)
	{
		P0 = 0xF0;
		delay_ms(100);
		P0 = 0x0F;
		delay_ms(100);
	}
}