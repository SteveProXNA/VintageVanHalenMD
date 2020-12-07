#include "random_manager.h"

#ifdef _CONSOLE
#include <stdlib.h>
#else
#include <genesis.h>
#endif

void engine_random_manager_rand()
{
#ifdef _CONSOLE
	rand();
#else
	random();
#endif
}

unsigned char engine_random_manager_data( unsigned char max )
{
#ifdef _CONSOLE
	return rand() % max;
#else
	return random() % max;
#endif
}