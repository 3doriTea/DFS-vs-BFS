#include "MapLoadDungeon.h"
#include <cassert>

MapLoadDungeon::MapLoadDungeon(const MapLoader& _mapLoader) :
	Dungeon{ _mapLoader.GetWidth(), _mapLoader.GetHeight() },
	MAP_LOADER_{ _mapLoader }
{
}

MapLoadDungeon::~MapLoadDungeon()
{
}

void MapLoadDungeon::Generate()
{
	const MapLoader& loader{ MAP_LOADER_ };
	
	for (int y = 0; y < loader.GetHeight(); y++)
	{
		for (int x = 0; x < loader.GetWidth(); x++)
		{
			char c{ loader.TileChar(x, y) };

			switch (c)
			{
			case '#':
				SetTile(Dungeon::TileType::Wall, x, y);
				break;
			case 'S':
				SetTile(Dungeon::TileType::Start, x, y);
				break;
			case 'G':
				SetTile(Dungeon::TileType::Goal, x, y);
				break;
			default:
				assert(false && "未定義のマップタイル文字");
				break;
			}
		}
	}

}
