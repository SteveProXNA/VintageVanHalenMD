#include "screen_manager.h"
#include "global_manager.h"
#include "enum_manager.h"

// Screens
#include "none_screen.h"
#include "splash_screen.h"
#include "init_screen.h"
#include "begin_screen.h"
#include "intro_screen.h"
#include "title_screen.h"
#include "start_screen.h"
#include "riff_screen.h"
#include "diff_screen.h"
#include "ready_screen.h"
#include "load_screen.h"
#include "part_screen.h"
#include "play_screen.h"
#include "quiz_screen.h"
#include "score_screen.h"
#include "stats_screen.h"
#include "over_screen.h"

static unsigned char curr_screen_type;
static unsigned char next_screen_type;

static void( *load_method[ MAX_SCREEENS ] )( );
static void( *update_method[ MAX_SCREEENS ] )( unsigned char *screen_type );

void engine_screen_manager_init( unsigned char open_screen_type )
{
	next_screen_type = open_screen_type;
	curr_screen_type = screen_type_none;

	// Set load methods.
	load_method[ screen_type_none ] = screen_none_screen_load;
	load_method[ screen_type_splash ] = screen_splash_screen_load;
	load_method[ screen_type_init ] = screen_init_screen_load;
	load_method[ screen_type_begin ] = screen_begin_screen_load;
	load_method[ screen_type_intro ] = screen_intro_screen_load;
	load_method[ screen_type_title ] = screen_title_screen_load;
	load_method[ screen_type_start ] = screen_start_screen_load;
	load_method[ screen_type_riff ] = screen_riff_screen_load;
	load_method[ screen_type_diff ] = screen_diff_screen_load;
	load_method[ screen_type_ready ] = screen_ready_screen_load;
	load_method[ screen_type_load ] = screen_load_screen_load;
	load_method[ screen_type_part ] = screen_part_screen_load;
	load_method[ screen_type_play ] = screen_play_screen_load;
	load_method[ screen_type_quiz ] = screen_quiz_screen_load;
	load_method[ screen_type_score ] = screen_score_screen_load;
	load_method[ screen_type_stats ] = screen_stats_screen_load;
	load_method[ screen_type_over ] = screen_over_screen_load;

	// Set update methods.
	update_method[ screen_type_none ] = screen_none_screen_update;
	update_method[ screen_type_splash ] = screen_splash_screen_update;
	update_method[ screen_type_init ] = screen_init_screen_update;
	update_method[ screen_type_begin ] = screen_begin_screen_update;
	update_method[ screen_type_intro ] = screen_intro_screen_update;
	update_method[ screen_type_title ] = screen_title_screen_update;
	update_method[ screen_type_start ] = screen_start_screen_update;
	update_method[ screen_type_riff ] = screen_riff_screen_update;
	update_method[ screen_type_diff ] = screen_diff_screen_update;
	update_method[ screen_type_ready ] = screen_ready_screen_update;
	update_method[ screen_type_load ] = screen_load_screen_update;
	update_method[ screen_type_part ] = screen_part_screen_update;
	update_method[ screen_type_play ] = screen_play_screen_update;
	update_method[ screen_type_quiz ] = screen_quiz_screen_update;
	update_method[ screen_type_score ] = screen_score_screen_update;
	update_method[ screen_type_stats ] = screen_stats_screen_update;
	update_method[ screen_type_over ] = screen_over_screen_update;
}

void engine_screen_manager_update()
{
	if( curr_screen_type != next_screen_type )
	{
		curr_screen_type = next_screen_type;
		load_method[ curr_screen_type ]();
	}

	update_method[ curr_screen_type ]( &next_screen_type );
}
