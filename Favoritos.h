#pragma once
#include <vector>
#include "Album.h"
class Favoritos
{

	private: std::vector<Album> AlbumFavs;

	public: void AddFavoritos(const Album& album);
	public:void Exibir();

};


