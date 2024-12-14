#include "inputs_manager.h"


void inputs_manager::initialize()
{
	KeyboardHandlerRegister(keyboard_handler);
}



void inputs_manager::cleanup()
{
	KeyboardHandlerUnregister(keyboard_handler);
}



key_state inputs_manager::get_key_state(BYTE _ScanCode)
{
	return s_key_states[_ScanCode];
}



void inputs_manager::reset_key_state(BYTE _ScanCode)
{
	memset(&s_key_states[_ScanCode], 0, sizeof(s_key_states[0]));
}



void inputs_manager::keyboard_handler(DWORD _Key, WORD _Repeats, BYTE _ScanCode, BOOL _IsExtended, BOOL _IsWithAlt, BOOL _WasDownBefore, BOOL _IsUpNow)
{
	if (_ScanCode >= 0xFF)
		return;

	s_key_states[_ScanCode].Time = GetTickCount64();
	s_key_states[_ScanCode].IsWithAlt = _IsWithAlt;
	s_key_states[_ScanCode].WasDownBefore = _WasDownBefore;
	s_key_states[_ScanCode].IsUpNow = _IsUpNow;
}



bool input::is_key_pressed(KeyCode _KeyCode)
{
	key_state keyState = inputs_manager::get_key_state(_KeyCode);

	return keyState.Time > 0 && !keyState.IsUpNow;
}



bool input::is_key_released(KeyCode _KeyCode)
{
	key_state keyState = inputs_manager::get_key_state(_KeyCode);

	return keyState.Time > 0 && keyState.IsUpNow;
}



bool input::is_key_just_pressed(KeyCode _KeyCode)
{
	key_state keyState = inputs_manager::get_key_state(_KeyCode);

	bool isPressed = keyState.Time > 0 && !keyState.WasDownBefore && !keyState.IsUpNow;

	if (isPressed)
	{
		inputs_manager::reset_key_state(_KeyCode);

		return true;
	}

	return false;
}



bool input::is_key_just_released(KeyCode _KeyCode)
{
	key_state keyState = inputs_manager::get_key_state(_KeyCode);

	bool isReleased = keyState.Time > 0 && keyState.WasDownBefore && keyState.IsUpNow;

	if (isReleased)
	{
		inputs_manager::reset_key_state(_KeyCode);

		return true;
	}

	return false;
}