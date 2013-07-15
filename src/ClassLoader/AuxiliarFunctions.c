#include <math.h>
#include "AuxiliarFunctions.h"

float convertU4ToFloat(u4 u4input)
{
	float convertedU4;
	int s;
	int e;
	int m;

	if(u4input == 0x7f800000)
	{
		/*infinito positivo*/
	}
	else if(u4input == 0xff800000)
	{
		/*infinito negativo*/
	}
	else if(((u4input >= 0x7f800001) && (u4input <= 0x7fffffff)) || ((u4input >= 0xff800001) && (u4input <= 0xffffffff)))
	{
		/*nan*/
	}
	else
	{
		s = ((u4input >> 31) == 0) ? 1 : -1;
		e = ((u4input >> 23) & 0xff);
		m = (e == 0) ? (u4input & 0x7fffff) << 1 : (u4input & 0x7fffff) | 0x800000;

		convertedU4 = s*m*(pow(2, (e - 150)));
	}
	
	return convertedU4;
}