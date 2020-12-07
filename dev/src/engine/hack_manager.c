#include "hack_manager.h"
#include "enum_manager.h"
#include "global_manager.h"
#include "game_manager.h"
#include "quiz_manager.h"

// Global variable.
struct_hack_object global_hack_object;

#define PEEK( addr)			(* ( unsigned char *)( addr ) )
#define POKE( addr, data )	(* ( unsigned char *)( addr ) = ( data ) )

#define HACKER_START		0x01E0
#define HACKER_SPACE		32

void engine_hack_manager_init()
{
	struct_hack_object *ho = &global_hack_object;

	ho->hack_delayspeed = 0;
	ho->hack_invincible = 0;
	ho->hack_riffselect = 0;
	ho->hack_diffselect = 0;
}

void engine_hack_manager_load()
{
	struct_hack_object *ho = &global_hack_object;

#ifndef _CONSOLE

	ho->hack_delayspeed = PEEK( HACKER_START - 2 );			// 0x01DE		// Used to speed through any game delay.
	ho->hack_invincible = PEEK( HACKER_START - 1 );			// 0x01DF		// Non-zero value enables always cheats.
	ho->hack_riffselect = PEEK( HACKER_START + 1 );			// 0x01E0		// Set value to 2,3,4 index otherwise 1.
	ho->hack_diffselect = PEEK( HACKER_START + 2 );			// 0x01E1		// Set value to 1=Easy otherwise 2=Hard.

#endif
}

void engine_hack_manager_save()
{
	struct_hack_object *ho = &global_hack_object;
	unsigned char index = 0;

	// Workaround spaces in ROM for the line I check for ROM hacks.
	if( ho->hack_delayspeed && HACKER_SPACE == ho->hack_delayspeed )
	{
		ho->hack_delayspeed = 0;
	}
	if( ho->hack_invincible && HACKER_SPACE == ho->hack_invincible )
	{
		ho->hack_invincible = 0;
	}

	// Set riffs play.
	if( ho->hack_riffselect && HACKER_SPACE != ho->hack_riffselect )
	{
		if( ho->hack_riffselect >= 1 && ho->hack_riffselect <= MAX_OPTION )
		{
			index = ho->hack_riffselect - 1;
			engine_game_manager_set_riff_select( index );
			engine_quiz_manager_set_riffs_play( index );
		}
	}

	// Set difficulty.
	if( ho->hack_diffselect && HACKER_SPACE != ho->hack_diffselect )
	{
		index = ( difficulty_type_hard + 1 ) == ho->hack_diffselect ? difficulty_type_hard : difficulty_type_easy;
		engine_game_manager_set_diff_select( index );
		engine_quiz_manager_set_difficulty( index );
	}
}