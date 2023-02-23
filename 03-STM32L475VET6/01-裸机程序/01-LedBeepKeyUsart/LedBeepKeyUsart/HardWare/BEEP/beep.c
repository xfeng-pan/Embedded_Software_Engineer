#include "beep.h"

void BeepBlink(void)
{
	BEE_O(1);

	HAL_Delay(200);
	
	BEE_O(0);


}
