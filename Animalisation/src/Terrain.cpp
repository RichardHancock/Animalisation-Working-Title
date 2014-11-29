#include "Terrain.h"

tile::tile()
{

}
tile::~tile()
{

}
void tile::draw()
{
	SDL_QueryTexture(m_texture, NULL, NULL, 0, 0);
}

terrain::terrain(int width, int height)
{
	m_height = height;
	m_width = width;

	// resize vector to world size
	m_tiles.resize(m_height * m_width);
	m_rect.resize(m_height * m_width);

	for (size_t i = 0; i < m_tiles.size(); ++i)
	{
		// random assign terrain type to tiles
		m_tiles[i].type(std::rand() % 4);
	}

	for (size_t y = 0; y < m_height; ++y)
	{
		for (size_t x = 0; x < m_width; ++x)
		{
			// compute a index 
			int index = y * m_height + x;

			// random assign terrain type to tiles
			m_tiles[index].tileCenter(x, y);

			m_rect[index].x += (m_rect[0].x * x) + 150;
			m_rect[index].y += (m_rect[0].y * y) + 150;
		}
	}

	for (size_t y = 0; y < m_height; ++y)
	{
		for (size_t x = 0; x < m_width; ++x)
		{
			// compute a index 
			int index = y * m_height + x;

			m_rect[index].x -= 150;
			m_rect[index].y -= 150;
		}
	}
}
terrain::~terrain()
{
	// clear vector
	m_tiles.clear();
}
void terrain::draw()
{
	// draw all tiles
	for (int i = 0; i < m_tiles.size(); ++i)
	{
		m_tiles[i].draw();
	}
}