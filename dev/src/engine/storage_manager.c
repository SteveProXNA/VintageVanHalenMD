#include "storage_manager.h"
#include "eddie_manager.h"
#include "enum_manager.h"
#include "game_manager.h"
#include "global_manager.h"
#include "quiz_manager.h"
#include "score_manager.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

void engine_storage_manager_read()
{
	unsigned short sRamOffSet;
	unsigned short word;
	signed char byte;
	unsigned char idx;

	sRamOffSet = 0x0000;
	SYS_disableInts();
	SRAM_enable();


	// Quiz most recent number + difficulty.
	byte = SRAM_readByte( sRamOffSet++ );
	if( INVALID_INDEX == byte )
	{
		byte = 0;
	}
	engine_game_manager_set_riff_select( byte );
	engine_quiz_manager_set_riffs_play( byte );

	byte = SRAM_readByte( sRamOffSet++ );
	if( INVALID_INDEX == byte )
	{
		byte = 0;
	}
	engine_game_manager_set_diff_select( byte );
	engine_quiz_manager_set_difficulty( byte );


	// Quiz summary numbers + difficulties.
	for( idx = 0; idx < MAX_OPTION * MAX_DIFFICULTY; idx++ )
	{
		word = SRAM_readWord( sRamOffSet );
		sRamOffSet++;
		sRamOffSet++;
		if( MAX_INT_VALUE == word )
		{
			word = 0;
		}
		engine_quiz_manager_set_quiz_saved( idx, word );
	}
	word = SRAM_readWord( sRamOffSet );
	sRamOffSet++;
	sRamOffSet++;
	if( MAX_INT_VALUE == word )
	{
		word = 0;
	}
	engine_quiz_manager_set_quiz_ended( word );
	word = SRAM_readWord( sRamOffSet );
	sRamOffSet++;
	sRamOffSet++;
	if( MAX_INT_VALUE == word )
	{
		word = 0;
	}
	engine_quiz_manager_set_quiz_total( word );


	// Padding 10x bytes with Eddie index + images.
	byte = SRAM_readByte( sRamOffSet++ );
	if( INVALID_INDEX == byte )
	{
		byte = 0;
	}
	engine_eddie_manager_set_eddie_index( byte );

	for( idx = 0; idx < EDDIE_IMAGES; idx++ )
	{
		byte = SRAM_readByte( sRamOffSet++ );
		if( INVALID_INDEX == byte )
		{
			byte = 0;
		}

		engine_eddie_manager_set_eddie_image( idx, byte );
	}


	// Score summary correct + answered.
	for( idx = 0; idx < MAX_RIFFS; idx++ )
	{
		word = SRAM_readWord( sRamOffSet );
		sRamOffSet++;
		sRamOffSet++;
		if( MAX_INT_VALUE == word )
		{
			word = 0;
		}
		engine_score_manager_set_score_correct( idx, word );
		word = SRAM_readWord( sRamOffSet );
		sRamOffSet++;
		sRamOffSet++;
		if( MAX_INT_VALUE == word )
		{
			word = 0;
		}
		engine_score_manager_set_score_answerd( idx, word );
	}


	SRAM_disable();
	SYS_enableInts();
}

void engine_storage_manager_write()
{
	struct_quiz_object *qo = &global_quiz_object;
	struct_eddie_object *eo = &global_eddie_object;
	struct_score_object *so = &global_socre_object;

	unsigned short sRamOffSet;
	unsigned short word;
	unsigned char byte;
	unsigned char idx;

	sRamOffSet = 0x0000;
	SYS_disableInts();
	SRAM_enable();


	// Quiz most recent number + difficulty.
	byte = qo->quiz_riff_numbs;
	SRAM_writeByte( sRamOffSet++, byte );
	byte = qo->quiz_difficulty;
	SRAM_writeByte( sRamOffSet++, byte );


	// Quiz summary numbers + difficulties.
	for( idx = 0; idx < MAX_OPTION * MAX_DIFFICULTY; idx++ )
	{
		word = qo->quiz_saved[ idx ];
		SRAM_writeWord( sRamOffSet, word );
		sRamOffSet++;
		sRamOffSet++;
	}
	word = qo->quiz_ended;
	SRAM_writeWord( sRamOffSet, word );
	sRamOffSet++;
	sRamOffSet++;
	word = qo->quiz_total;
	SRAM_writeWord( sRamOffSet, word );
	sRamOffSet++;
	sRamOffSet++;


	// Padding 10x bytes with Eddie index + images.
	byte = eo->eddie_index;
	SRAM_writeByte( sRamOffSet++, byte );
	for( idx = 0; idx < EDDIE_IMAGES; idx++ )
	{
		byte = eo->eddie_images[ idx ];
		SRAM_writeByte( sRamOffSet++, byte );
	}


	// Score summary correct + answered.
	for( idx = 0; idx < MAX_RIFFS; idx++ )
	{
		word = so->saved_correct[ idx ];
		SRAM_writeWord( sRamOffSet, word );
		sRamOffSet++;
		sRamOffSet++;
		word = so->saved_answerd[ idx ];
		SRAM_writeWord( sRamOffSet, word );
		sRamOffSet++;
		sRamOffSet++;
	}


	SRAM_disable();
	SYS_enableInts();
}

void engine_storage_manager_erase()
{
	unsigned long sRamOffSet;
	unsigned char idx;

	sRamOffSet = 0x0000;
	SYS_disableInts();
	SRAM_enable();

	// Quiz most recent number + difficulty.
	SRAM_writeByte( sRamOffSet++, INVALID_INDEX );
	SRAM_writeByte( sRamOffSet++, INVALID_INDEX );


	// Quiz summary numbers + difficulties.
	for( idx = 0; idx < MAX_OPTION * MAX_DIFFICULTY; idx++ )
	{
		SRAM_writeWord( sRamOffSet, INVALID_INDEX );
		sRamOffSet++;
		sRamOffSet++;
	}
	SRAM_writeWord( sRamOffSet, INVALID_INDEX );
	sRamOffSet++;
	sRamOffSet++;
	SRAM_writeWord( sRamOffSet, INVALID_INDEX );
	sRamOffSet++;
	sRamOffSet++;


	// Padding 10x bytes with Eddie index + images.
	SRAM_writeByte( sRamOffSet++, INVALID_INDEX );
	for( idx = 0; idx < EDDIE_IMAGES; idx++ )
	{
		SRAM_writeByte( sRamOffSet++, INVALID_INDEX );
	}


	// Score summary correct + answered.
	for( idx = 0; idx < MAX_RIFFS; idx++ )
	{
		SRAM_writeWord( sRamOffSet, INVALID_INDEX );
		sRamOffSet++;
		sRamOffSet++;
		SRAM_writeWord( sRamOffSet, INVALID_INDEX );
		sRamOffSet++;
		sRamOffSet++;
	}


	SRAM_disable();
	SYS_enableInts();
}