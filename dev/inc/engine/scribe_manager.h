#ifndef __SCRIBE_MANAGER__
#define __SCRIBE_MANAGER__

void engine_scribe_manager_load_lines( unsigned char cursor, unsigned char maximum, const char **options, const char **line1, const char **line2, const char **line3, const char **line4 );
void engine_scribe_manager_draw_line( unsigned char cursor, unsigned char index, unsigned char x, unsigned char y );
void engine_scribe_manager_draw_line_palette( unsigned char cursor, unsigned char palette, unsigned char index, unsigned char x, unsigned char y );
void engine_scribe_manager_draw_options( unsigned char cursor, const char *option, unsigned char x, unsigned char y );
void engine_scribe_manager_draw_option( unsigned char cursor, unsigned char index, unsigned char x, unsigned char y );

#endif//__SCRIBE_MANAGER__