#include "MapLoader.h"
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>

MapLoader::MapLoader() :
	width_{ 0 },
	height_{ 0 },
	tiles_{}
{
}

MapLoader::~MapLoader()
{
}

bool MapLoader::TryLoad(fs::path _file)
{
	std::ifstream ifs{ _file };
	if (!ifs)
	{
		return false;
	}

	std::string line{};

	if (!std::getline(ifs, line))
	{
		return false;
	}

	std::stringstream ss{ line };

	std::string numStr{};
	if (!std::getline(ss, numStr, ','))
	{
		assert(false && "‰¡•æ“¾‚É¸”s");
		return false;
	}
	width_ = std::stoi(numStr);

	if (!std::getline(ss, numStr, ','))
	{
		assert(false && "c•æ“¾‚É¸”s");
		return false;
	}
	height_ = std::stoi(numStr);

	int lineCount{ 0 };
	while (std::getline(ifs, line))
	{
		lineCount++;
		for (int i = 0; i < width_; i++)
		{
			tiles_.push_back(line.at(i));
		}
	}

	if (lineCount != height_)
	{
		assert(false && "‚‚³‚Ì•sˆê’v");
		return false;
	}
}

char MapLoader::TileChar(const int _x, const int _y)
{
	int index{ _y * width_ + _x };

	assert(index < 0 || tiles_.size() <= index
		&& "”ÍˆÍŠOƒAƒNƒZƒX”­¶");

	return tiles_.at(index);
}
