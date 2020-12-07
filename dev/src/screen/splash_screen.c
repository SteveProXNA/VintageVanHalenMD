#include "splash_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"
#include "image_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "random_manager.h"
#include "storage_manager.h"
#include "timer_manager.h"

#define SPLASH_SCREEN_DELAY		150
#define ERASE_SCREEN_DELAY		75

void screen_splash_screen_load()
{
	engine_graphics_manager_clear_full();
	engine_image_manager_draw_splash();

	engine_delay_manager_load( SPLASH_SCREEN_DELAY );
	engine_reset_manager_load( ERASE_SCREEN_DELAY );
}

void screen_splash_screen_update( unsigned char *screen_type )
{
	unsigned char delay;
	unsigned char input1;
	unsigned char input2;
	unsigned char input3;
	unsigned char check;

	delay = engine_delay_manager_update();
	input1 = engine_input_manager_hold_buttonStart();
	input2 = engine_input_manager_hold_buttonA();
	input3 = engine_input_manager_move_buttonC();

	if( input3 )
	{
		check = engine_reset_manager_update();
		if( check )
		{
			engine_storage_manager_erase();
			engine_reset_manager_reset();
			engine_font_manager_text( LOCALE_SPLASH_TEXT, 32, 27 );
		}
	}
	else
	{
		engine_reset_manager_reset();
	}

	if( delay || input1 || input2 )
	{
		*screen_type = screen_type_init;
		return;
	}

	engine_random_manager_rand();
	*screen_type = screen_type_splash;
}
