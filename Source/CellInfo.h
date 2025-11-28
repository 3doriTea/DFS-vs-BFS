#pragma once

enum DIRECTION
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	MAX
};

struct Cell
{
	bool checked_;
	bool isWall_;
	Cell* pNeighbor[DIRECTION::MAX];
	Vec2Int pos_;
};
