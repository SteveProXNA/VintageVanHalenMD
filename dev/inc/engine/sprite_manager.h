#ifndef __SPRITE_MANAGER__
#define __SPRITE_MANAGER__

void engine_sprite_manager_init();
void engine_sprite_manager_hide( unsigned char sprite );
void engine_sprite_manager_update();
void engine_sprite_manager_palette();
void engine_sprite_manager_draw( const unsigned char index, unsigned char x, unsigned char y );

#endif//__SPRITE_MANAGER__