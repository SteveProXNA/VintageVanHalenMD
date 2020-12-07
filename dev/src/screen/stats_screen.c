#include "stats_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "function_manager.h"
#include "graphics_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "quiz_manager.h"
#include "text_manager.h"

#define START_X		2
#define START_Y		7
#define DELTA_Y		7

void screen_stats_screen_load()
{
	struct_quiz_object *qo = &global_quiz_object;
	unsigned short numerator;
	unsigned short denominator;
	unsigned short percent;
	unsigned char diff;
	unsigned char opt;
	unsigned char idx;
	unsigned char y;

	engine_graphics_manager_clear_half();
	engine_font_manager_text( LOCALE_STATS_TITLES, START_X + 3, START_Y + 0 );
	engine_font_manager_text( LOCALE_STATS_FINISH, START_X + 2, START_Y + 3 );
	engine_font_manager_text( LOCALE_BULLET_POINT, START_X + 0, START_Y + 3 );
	engine_font_manager_text( LOCALE_PERCENT_SYM, START_X + 17, START_Y + 3 );

	numerator = qo->quiz_ended;
	denominator = qo->quiz_total;
	percent = engine_function_manager_calculate_percentage( numerator, denominator );
	engine_font_manager_data( percent, START_X + 14, START_Y + 3 );

	engine_font_manager_text( diff_line1[ 0 ], START_X + 2, START_Y + 6 );
	engine_font_manager_text( diff_line1[ 1 ], START_X + 2, START_Y + 13 );

	engine_text_manager_draw_lines_extra( 5, 1, 1 );
	engine_text_manager_draw_lines( 15, 1 );

	for( diff = 0; diff < MAX_DIFFICULTY; diff++ )
	{
		for( opt = 0; opt < MAX_OPTION; opt++ )
		{
			y = START_Y + ( diff * DELTA_Y ) + DELTA_Y + opt;
			engine_font_manager_text( LOCALE_BULLET_POINT, START_X + 0, y );
			engine_font_manager_zero( quiz_number[ opt ], START_X + 2, y );
			engine_font_manager_text( LOCALE_STATS_RIFFS, START_X + 5, y );
			engine_font_manager_text( LOCALE_PERCENT_SYM, START_X + 17, y );

			idx = diff * MAX_OPTION + opt;
			numerator = qo->quiz_saved[ idx ];
			percent = engine_function_manager_calculate_percentage( numerator, denominator );
			engine_font_manager_data( percent, START_X + 14, y );
		}
	}
}

void screen_stats_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	input = engine_input_manager_hold_buttonB();
	if( input )
	{
		*screen_type = screen_type_start;
		return;
	}

	*screen_type = screen_type_stats;
}
