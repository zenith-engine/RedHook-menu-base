#pragma once
#include "../../pch.h"


struct key_state
{
	uint64_t Time;
	bool IsWithAlt;
	bool WasDownBefore;
	bool IsUpNow;
};

class inputs_manager
{
public:
	static void initialize();
	static void cleanup();

	static key_state get_key_state(BYTE _ScanCode);
	static void reset_key_state(BYTE _ScanCode);

private:
	static inline key_state s_key_states[0xFF];

	static void keyboard_handler(DWORD _Key, WORD _Repeats, BYTE _ScanCode, BOOL _IsExtended, BOOL _IsWithAlt, BOOL _WasDownBefore, BOOL _IsUpNow);
};

class input
{
public:
	static bool is_key_pressed(KeyCode _KeyCode);
	static bool is_key_released(KeyCode _KeyCode);

	static bool is_key_just_pressed(KeyCode _KeyCode);
	static bool is_key_just_released(KeyCode _KeyCode);
};