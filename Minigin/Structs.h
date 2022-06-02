#pragma once
#include <cstdint>

struct Color
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a{ 255 };
};

struct Vector2f
{
	int x;
	int y;
};

enum class Event
{
	LivesChanged,
	ScoreChanged,
	PlayerDied,

};

enum class GameMode
{
	Solo,
	CoOp,
	Versus
};
