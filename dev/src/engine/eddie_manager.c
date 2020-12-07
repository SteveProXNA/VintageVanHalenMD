#include "eddie_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "random_manager.h"

// Global variables.
struct_eddie_object global_eddie_object;

void engine_eddie_manager_init()
{
	struct_eddie_object *eo = &global_eddie_object;
	unsigned char idx;

	if( 0 != eo->eddie_index )
	{
		return;
	}

	// Free slots still available so pick one.
	for( idx = 0; idx < EDDIE_IMAGES; idx++ )
	{
		eo->eddie_images[ idx ] = 0;
	}
}

void engine_eddie_manager_save()
{
	struct_eddie_object *eo = &global_eddie_object;
	unsigned char idx;

	for( idx = 0; idx < EDDIE_IMAGES; idx++ )
	{
		if( 0 == eo->eddie_images[ idx ] )
		{
			eo->eddie_index = idx;
			break;
		}
	}
}

unsigned char engine_eddie_manager_next()
{
	struct_eddie_object *eo = &global_eddie_object;
	unsigned char eddie_image = 0;

	while( 1 )
	{
		// Displace Eddie images from 1-22 as 0 index is young Eddie!
		eddie_image = engine_random_manager_data( ( MAX_EDDIES - 1 ) );
		eddie_image += 1;

		if(
			( eddie_image != eo->eddie_images[ 0 ] ) &&
			( eddie_image != eo->eddie_images[ 1 ] ) &&
			( eddie_image != eo->eddie_images[ 2 ] ) &&
			( eddie_image != eo->eddie_images[ 3 ] ) &&
			( eddie_image != eo->eddie_images[ 4 ] ) &&
			( eddie_image != eo->eddie_images[ 5 ] ) &&
			( eddie_image != eo->eddie_images[ 6 ] ) &&
			( eddie_image != eo->eddie_images[ 7 ] ) &&
			( eddie_image != eo->eddie_images[ 8 ] )
			)
		{
			eo->eddie_images[ eo->eddie_index ] = eddie_image;
			break;
		}
	}

	eo->eddie_index++;
	if( eo->eddie_index >= EDDIE_IMAGES )
	{
		eo->eddie_index = 0;
	}

	return eddie_image;
}

void engine_eddie_manager_set_eddie_index( unsigned char eddie_index )
{
	struct_eddie_object *eo = &global_eddie_object;
	eo->eddie_index = eddie_index;
}
void engine_eddie_manager_set_eddie_image( unsigned char index, unsigned char eddie_image )
{
	struct_eddie_object *eo = &global_eddie_object;
	eo->eddie_images[ index ] = eddie_image;
}