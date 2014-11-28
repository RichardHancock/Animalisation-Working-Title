#pragma once
#include "Textures.h"
#include "Window.h"
#include "Vec2.h"

// the type of terrain each tile is
enum terrainType
{
	tGrass,
	tHills,
	tTown,
	tWater,
};

///\brief A tile that will make up the world
class tile
{
public:
	///\brief Constr
	tile();
	///\brief Destr
	~tile();

	///\brief set the texture for the tile
	///\prama SDL_Texture* texture
	inline void bindTexture(SDL_Texture* tileTexture)
	{
		m_texture = tileTexture;
	}

	///\brief get the texture
	///\return SDL_Texture* texture
	inline SDL_Texture* getTitetexture()
	{
		return m_texture;
	}
	///\brief set the type of terrian
	///\prama int terrain type
	inline void type(int terrianType)
	{
		m_terrainType = terrianType;
	}
	///\brief get the terrain type
	///\prama int terrain type
	inline int getType()
	{
		return m_terrainType;
	}


	///\brief set center of the tile
	///\prama float x
	///\prama float y
	inline void tileCenter(float x, float y)
	{
		m_tileCenter.x = x;
		m_tileCenter.y = y;
	}
	///\brief get top of the tile
	///\return float 
	inline Vec2 getTitleTop()
	{
		Vec2 r;
		r.y = m_tileCenter.y + 75.0f;
		r.x = m_tileCenter.x;
		return r;
	}
	///\brief get right of the tile
	///\return float 
	inline Vec2 getTitleRight()
	{
		Vec2 r;
		r.x = m_tileCenter.x + 75.0f;
		r.y = m_tileCenter.y;
		return r;
	}
	///\brief get bottom of the tile
	///\return float 
	inline Vec2 getTitleBottom()
	{
		Vec2 r;
		r.y = m_tileCenter.y - 75.0f;
		r.x = m_tileCenter.x;
		return r;
	}
	///\brief get left of the tile
	///\return float 
	inline Vec2 getTitleLeft()
	{
		Vec2 r;
		r.x = m_tileCenter.x - 75.0f;
		r.y = m_tileCenter.y;
		return r;
	}

private:
	int m_terrainType; ///< terrain type
	SDL_Texture* m_texture; ///< texture pointer
	Vec2 m_tileCenter; ///< center of the tile
};

///\brief All the terrain in the world
class terrain
{
public:
	///\brief Constr
	///\prama int width of the world
	///\prama int height of the world
	terrain(int width, int height);
	///\brief Destr
	~terrain();

	///\brief draw terrain
	void draw();

	///\brief get the height of the world
	///\return int height
	inline int getHeight()
	{
		return m_height;
	}
	///\brief get the width of the world
	///\return int width
	inline int getWidth()
	{
		return m_width;
	}
	///\brief get a tile type 
	///\prama int index of tile
	///\return int tile type
	inline int getTileType(int tileIndex)
	{
		return m_tiles[tileIndex].getType();
	}
	///\brief set a tile type
	///\prama int index of tile
	///\prama int terrain type
	inline void tileType(int tileIndex, int terrainType)
	{
		m_tiles[tileIndex].type(terrainType);
	}

private:
	int m_height; ///< world height
	int m_width; ///< world width
	std::vector<tile> m_tiles; ///< vector of tiles
};
