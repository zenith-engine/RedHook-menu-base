#pragma once

// © Copyright K3rhos 2024
// https://discord.gg/8b7NVWnthY

class math
{
public:
	inline static int clamp(int val, int min, int max) {
		return val < min ? min : val > max ? max : val;
	}
	inline static float clamp(float val, float min, float max) {
		return val < min ? min : val > max ? max : val;
	}
	inline static void clamp(int* val, int min, int max) {
		*val = *val < min ? min : *val > max ? max : *val;
	}
	inline static bool clamp(float* val, float min, float max) {
		*val = *val < min ? min : *val > max ? max : *val;
		return *val == min || *val == max;
	}
};