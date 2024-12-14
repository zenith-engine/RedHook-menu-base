#ifndef PCH_H
#define PCH_H

// © Copyright K3rhos 2024
// https://discord.gg/8b7NVWnthY



#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define NAME "RedHook Menu"

struct Texture {
	std::string dict;
	std::string id;

	bool isEmpty() { return strcmp(dict.c_str(), "") + strcmp(id.c_str(), "") == 0; }
};


#include <RedHook.h>

#include "invoker/NativesCaller.h"

#include "util/Math.h"
#include "rdr/Enums.h"
#include "invoker/Structs.h"
#include "invoker/Natives.h"

#include "Resources/Includes/RedHook.h"
#endif