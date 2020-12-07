#ifndef __TIMER_MANAGER_H__
#define __TIMER_MANAGER_H__

#include "timer_object.h"

// Global variables.
extern struct_delay_object global_delay_object;
extern struct_reset_object global_reset_object;


// Delay Manager.
void engine_delay_manager_load( unsigned int delay );
unsigned char engine_delay_manager_update();


// Reset Manager.
void engine_reset_manager_load( unsigned char frame );
unsigned char engine_reset_manager_update();
void engine_reset_manager_reset();

#endif//__TIMER_MANAGER_H__