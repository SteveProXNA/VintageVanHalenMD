#include "start_screen.h"
#include "audio_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "graphics_manager.h"
#include "hack_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "random_manager.h"
#include "sprite_manager.h"
#include "text_manager.h"
#include "timer_manager.h"
#include "music_object.h"

#define START_FLASH_DELAY		50
#define START_SCREEN_DELAY		100
#define STATS_SCREEN_DELAY		75
#define SAMPLE_ROTATE_DELAY		150
#define LOCAL_CHEAT_TOTAL		5

static void randomize_intro();

static unsigned char intro_riffs[ MAX_SAMPLES ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static unsigned char intro_index;
static unsigned char event_stage;
static unsigned char flash_count;
static unsigned char cheat_count;
static unsigned char stage;
static unsigned short frame;

void screen_start_screen_load()
{
	struct_hack_object *ho = &global_hack_object;
	engine_graphics_manager_clear_half();

	engine_font_manager_text( LOCALE_TITLE_VINTAGE, 7, 7 );
	engine_font_manager_text( LOCALE_TITLE_VANHALEN, 6, 8 );
	engine_text_manager_draw_lines( 30, 8 );

	engine_game_manager_set_local_cheat( completion_type_nop );
	if( ho->hack_invincible )
	{
		engine_font_manager_text( LOCALE_CHEAT_MARKER, 18, 27 );
		engine_game_manager_set_local_cheat( completion_type_yes );
	}

	engine_font_manager_text( LOCALE_TITLE_START, 5, 24 );
	engine_delay_manager_load( START_FLASH_DELAY );
	engine_reset_manager_load( STATS_SCREEN_DELAY );

	randomize_intro();
	intro_index = 0;

	event_stage = event_stage_start;
	flash_count = 0;
	cheat_count = 0;
	stage = event_stage_start;
	frame = 0;
}

void screen_start_screen_update( unsigned char *screen_type )
{
	struct_game_object *go = &global_game_object;
	struct_hack_object *ho = &global_hack_object;
	unsigned char delay;
	unsigned char input;
	unsigned char input2;
	unsigned char check;
	unsigned char audio;

	engine_sprite_manager_update();
	if( event_stage_pause == stage )
	{
		delay = engine_delay_manager_update();
		if( delay )
		{
			*screen_type = screen_type_riff;
		}

		return;
	}

	// Play random audio riff.
	audio = engine_audio_manager_is_playing();
	if( !audio )
	{
		frame++;
		if( 0 == frame % SAMPLE_ROTATE_DELAY )
		{
			frame = 0;
			check = intro_riffs[ intro_index ];
			engine_audio_manager_play_riff( music_intro[ check ] );

			intro_index++;
			if( intro_index >= MAX_SAMPLES )
			{
				intro_index = 0;
			}
		}
	}

	delay = engine_delay_manager_update();
	if( delay )
	{
		if( !ho->hack_delayspeed )
		{
			flash_count = 1 - flash_count;
		}

		if( flash_count )
		{
			engine_font_manager_text( LOCALE_BLANK_SIZE18, 2, 24 );
		}
		else
		{
			engine_font_manager_text( LOCALE_TITLE_START, 5, 24 );
		}
	}

	input = engine_input_manager_hold_buttonA();
	input2 = engine_input_manager_hold_buttonStart();
	if( input || input2 )
	{
		engine_audio_manager_play_effect( effects_type_right );
		engine_font_manager_text( LOCALE_TITLE_START, 5, 24 );

		engine_delay_manager_load( START_SCREEN_DELAY );
		stage = event_stage_pause;
		return;
	}

	if( !ho->hack_invincible && !go->game_localcheat )
	{
		input = engine_input_manager_hold_buttonC();
		if( input )
		{
			cheat_count++;
			if( cheat_count >= LOCAL_CHEAT_TOTAL )
			{
				engine_audio_manager_play_effect( effects_type_cheat );

				engine_game_manager_set_local_cheat( completion_type_yes );
				engine_game_manager_draw_cheat();
			}
		}
	}

	input = engine_input_manager_move_buttonB();
	if( input )
	{
		check = engine_reset_manager_update();
		if( check )
		{
			input2 = engine_input_manager_move_down();
			if( input2 )
			{
				*screen_type = screen_type_stats;
				return;
			}
		}
	}
	else
	{
		engine_reset_manager_reset();
	}

	engine_random_manager_rand();
	engine_sprite_manager_update();
	*screen_type = screen_type_start;
}

static void randomize_intro()
{
	unsigned char idx;
	unsigned char rnd;

	for( idx = 0; idx < MAX_SAMPLES; idx++ )
	{
		intro_riffs[ idx ] = 0;
	}

	for( idx = 0; idx < MAX_SAMPLES; idx++ )
	{
		while( 1 )
		{
			rnd = engine_random_manager_data( MAX_SAMPLES );
			if( 0 == intro_riffs[ rnd ] )
			{
				intro_riffs[ rnd ] = idx;
				break;
			}
		}
	}
}
