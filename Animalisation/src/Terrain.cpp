#include "Terrain.h"

tile::tile()
{

}
tile::~tile()
{

}

terrain::terrain(int width, int height)
{
	m_height = height;
	m_width = width;

	// resize vector to world size
	m_tiles.resize(m_height * m_width);

	for (size_t i; i < m_tiles.size(); ++i)
	{
		// random assign terrain type to tiles
		m_tiles[i].type(std::rand() % 4);
	}

	for (size_t y; y < m_height; ++y)
	{
		for (size_t x; x < m_width; ++x)
		{
			// random assign terrain type to tiles
			m_tiles[i].tileCenter
		}
	}
}
terrain::~terrain()
{
	// clear vector
	m_tiles.erase();
}
void terrain::draw()
{
	// add code
}