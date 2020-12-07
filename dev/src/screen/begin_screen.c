#include "begin_screen.h"
#include "audio_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"
#include "image_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "random_manager.h"
#include "timer_manager.h"

#ifdef _CONSOLE
#include <string.h>
#else
#include <genesis.h>
#endif

#define BEGIN_SCREEN_DELAY		600

static void draw_texter();

void screen_begin_screen_load()
{
	engine_graphics_manager_clear_full();
	draw_texter();
	engine_font_manager_text( LOCALE_BUILD_VERSION, 36, 27 );

	engine_image_manager_draw_header();
	engine_delay_manager_load( BEGIN_SCREEN_DELAY );

	engine_audio_manager_play_intro( intros_type_jumps );
}

void screen_begin_screen_update( unsigned char *screen_type )
{
	unsigned char delay;
	unsigned char input1;
	unsigned char input2;

	delay = engine_delay_manager_update();
	input1 = engine_input_manager_hold_buttonA();
	input2 = engine_input_manager_hold_buttonStart();

	if( delay || input1 || input2 )
	{
		engine_audio_manager_stop();
		*screen_type = screen_type_intro;
		return;
	}

	engine_random_manager_rand();
	*screen_type = screen_type_begin;
}

static void draw_texter()
{
	unsigned short length;
	unsigned char index;
	const unsigned char start = 8;
	const unsigned char step = 4;
	const unsigned char y = 6;

	length = strlen( LOCALE_TITLE_VINTAGE );
	for( index = 0; index < length; index++ )
	{
		engine_font_manager_char( LOCALE_TITLE_VINTAGE[ index ], start + ( index * step ), y );
	}
}
