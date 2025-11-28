#include "DungeonViewer.h"
#include <iostream>
#include "Dungeon.h"
#include "DxLib.h"

int DungeonViewer::WALL_SIZE{ 30 };

DungeonViewer::DungeonViewer(const Dungeon& _dungeon) :
	dungeon_{ _dungeon }
{
}

DungeonViewer::~DungeonViewer()
{
}

void DungeonViewer::View()
{
	for (int y = 0; y < dungeon_.GetHeight(); y++)
	{
		for (int x = 0; x < dungeon_.GetWidth(); x++)
		{
			switch (dungeon_.GetTile(x, y))
			{
			case Dungeon::TileType::Wall:
				DrawBox(x * WALL_SIZE, y * WALL_SIZE, (x + 1) * WALL_SIZE, (y + 1) * WALL_SIZE, 0x00ff00, TRUE);
				break;
			case Dungeon::TileType::None:
			default:
				break;
			}
		}
		std::cout << std::endl;
	}
}

bool DungeonViewer::IsWall(const int _x, const int _y)
{
	return dungeon_.GetTile(_x, _y) == Dungeon::TileType::Wall;
}

Vec2Int DungeonViewer::GetSize() const
{
	return { dungeon_.GetWidth(), dungeon_.GetHeight() };
}
