#include <stdio.h>

unsigned char swap_bits(unsigned char octect)
{
	return (octect >> 4 | octect << 4);
}