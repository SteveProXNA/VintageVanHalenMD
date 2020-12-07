#include "quiz_screen.h"
#include "cursor_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "quiz_manager.h"
#include "sprite_manager.h"
#include "timer_manager.h"

#define QUIZ_SCREEN_DELAY		100
#define QUIZ_SCREEN_PAUSE		20

static unsigned char stage;

void screen_quiz_screen_load()
{
	engine_delay_manager_load( QUIZ_SCREEN_DELAY );
	stage = event_stage_start;
}

void screen_quiz_screen_update( unsigned char *screen_type )
{
	struct_cursor_object *co = &global_cursor_object;
	unsigned char delay;
	unsigned char enter;

	engine_sprite_manager_update();
	if( event_stage_pause == stage )
	{
		delay = engine_delay_manager_update();
		if( delay )
		{
			enter = engine_quiz_manager_increment( co->selects );
			*screen_type = enter ? screen_type_over : screen_type_part;
		}

		return;
	}
	
	delay = engine_delay_manager_update();
	if( delay )
	{
		engine_cursor_manager_hide();
		engine_delay_manager_load( QUIZ_SCREEN_PAUSE );
		stage = event_stage_pause;
		return;
	}

	engine_sprite_manager_update();
	*screen_type = screen_type_quiz;
}