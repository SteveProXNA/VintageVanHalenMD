#include "intro_screen.h"
#include "audio_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"
#include "image_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "random_manager.h"
#include "text_manager.h"
#include "timer_manager.h"

#define INTRO_SCREEN_DELAY		350
#define INTRO_MUSICS_DELAY		100
#define ROTATE_EDDIES			2

static void print_text( unsigned char index );
static unsigned char audio;
static unsigned char eddie;
static unsigned short frame;

void screen_intro_screen_load()
{
	engine_graphics_manager_clear_full();

	engine_image_manager_draw_banner();
	engine_image_manager_draw_eddie( 0, 14, 6 );

	engine_font_manager_text( LOCALE_EDWARD_TITLE, 12, 4 );
	engine_font_manager_text( LOCALE_BIRTH_DEATH, 14, 22 );

	engine_delay_manager_load( INTRO_SCREEN_DELAY );
	audio = 0;
	eddie = 0;
	print_text( eddie );
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	unsigned char delay;
	unsigned char input;
	unsigned char input2;

	// Play audio intro riff.
	if( 0 == audio )
	{
		frame++;
		if( 0 == frame % INTRO_MUSICS_DELAY )
		{
			audio = 1;
			frame = 0;
			engine_audio_manager_play_intro( intros_type_dream );
		}
	}

	delay = engine_delay_manager_update();
	if( delay )
	{
		engine_delay_manager_load( INTRO_SCREEN_DELAY );
		eddie++;
		if( eddie > ROTATE_EDDIES )
		{
			*screen_type = screen_type_title;
			return;
		}

		print_text( eddie );
	}

	input = engine_input_manager_hold_buttonA();
	input2 = engine_input_manager_hold_buttonStart();
	if( input || input2 )
	{
		engine_audio_manager_stop();
		*screen_type = screen_type_title;
		return;
	}

	engine_random_manager_rand();
	*screen_type = screen_type_intro;
}

static void print_text( unsigned char index )
{
	const unsigned char start = 18 + index * 4;
	const unsigned char lines = 4;

	engine_graphics_manager_clear_bottom();
	engine_text_manager_draw_lines( start, lines );

	if( ROTATE_EDDIES != index )
	{
		engine_font_manager_text( LOCALE_BUILD_VERSION, 36, 27 );
	}
}
