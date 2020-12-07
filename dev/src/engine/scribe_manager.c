#include "scribe_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "scribe_object.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

void engine_scribe_manager_load_lines( unsigned char cursor, unsigned char maximum, const char **options, const char **line1, const char **line2, const char **line3, const char **line4 )
{
	unsigned char idx;
	for( idx = 0; idx < maximum; idx++ )
	{
		scribe_options[ idx ] = cursor_type_small == cursor ? options[ 0 ] : options[ idx ];

		scribe_line1[ idx ] = line1[ idx ];
		scribe_line2[ idx ] = line2[ idx ];
		if( cursor_type_small == cursor )
		{
			continue;
		}

		scribe_line3[ idx ] = line3[ idx ];
		scribe_line4[ idx ] = line4[ idx ];
	}
}

void engine_scribe_manager_draw_line( unsigned char cursor, unsigned char index, unsigned char x, unsigned char y )
{
	engine_font_manager_text( scribe_line1[ index ], x, y + 0 );
	engine_font_manager_text( scribe_line2[ index ], x, y + 1 );
	if( cursor_type_small == cursor )
	{
		return;
	}

	engine_font_manager_text( scribe_line3[ index ], x, y + 2 );
	engine_font_manager_text( scribe_line4[ index ], x, y + 3 );
}

void engine_scribe_manager_draw_line_palette( unsigned char cursor, unsigned char palette, unsigned char index, unsigned char x, unsigned char y )
{
	VDP_setTextPalette( palette );
	engine_scribe_manager_draw_line( cursor, index, x, y );
}

void engine_scribe_manager_draw_options( unsigned char cursor, const char *option, unsigned char x, unsigned char y )
{
	engine_font_manager_char( option[ 0 ], x, y + 0 );
	engine_font_manager_char( option[ 1 ], x, y + 1 );

	if( cursor_type_small == cursor )
	{
		return;
	}

	engine_font_manager_char( option[ 2 ], x, y + 2 );
	engine_font_manager_char( option[ 3 ], x, y + 3 );
}

void engine_scribe_manager_draw_option( unsigned char cursor, unsigned char index, unsigned char x, unsigned char y )
{
	const char *option = scribe_options[ index ];
	engine_scribe_manager_draw_options( cursor, option, x, y );
}