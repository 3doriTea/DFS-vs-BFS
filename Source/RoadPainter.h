#pragma once
#include <vector>
#include "Vec2Int.h"

enum PaintType
{
	PT_CHECKED,
	PT_NEXT,
};

class RoadPainter
{
private:
	struct PaintCell
	{
		Vec2Int pos;
		int color;
	};

public:
	RoadPainter();
	~RoadPainter();

	void Draw();
	void Add(const Vec2Int _pos, const PaintType _paintType = PaintType::PT_CHECKED);

private:
	std::vector<PaintCell> history_;
};
