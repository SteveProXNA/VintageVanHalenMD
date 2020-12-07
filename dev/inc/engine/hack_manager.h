#ifndef __HACK_MANAGER_H__
#define __HACK_MANAGER_H__

#include "hack_object.h"

// Global variable.
extern struct_hack_object global_hack_object;

void engine_hack_manager_init();
void engine_hack_manager_load();
void engine_hack_manager_save();

#endif//__HACK_MANAGER_H__