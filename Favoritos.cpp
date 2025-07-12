#include "Favoritos.h"
void Favoritos::AddFavoritos(const Album& album)
{
	if(AlbumFavs.size() < 4)
	{
		AlbumFavs.push_back(album);
	}
}
void Favoritos::Exibir()
{

}

