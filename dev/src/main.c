#include "main.h"

int main()
{
	unsigned char open_screen_type = screen_type_splash;
	engine_screen_manager_init( open_screen_type );
	while( 1 )
	{
		engine_input_manager_update();
		engine_screen_manager_update();

		VDP_waitVSync();
	}

	return 0;
}