#ifndef __CURSOR_MANAGER_H__
#define __CURSOR_MANAGER_H__

#include "cursor_object.h"

// Global variables.
extern struct_cursor_object global_cursor_object;

void engine_cursor_manager_load_small( unsigned char maximum, unsigned char selects, unsigned char xPos, const unsigned char *yPos, const char **line1, const char **line2 );
void engine_cursor_manager_load_large( unsigned char maximum, unsigned char selects, unsigned char xPos, const unsigned char *yPos, const char **options, const char **line1, const char **line2, const char **line3, const char **line4 );
void engine_cursor_manager_move_up();
void engine_cursor_manager_move_down();
void engine_cursor_manager_action( unsigned char sprite );
void engine_cursor_manager_draw();
void engine_cursor_manager_hide();

#endif//__CURSOR_MANAGER_H__