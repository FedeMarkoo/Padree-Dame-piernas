#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED
#include "Declaraciones.h"

void chrome(char *YaUsado);/// Abre el chrome y copia todo
void getalbumes(Faltantes **Falta, char *EnUso,PunteroAlbums Album);/// Obtiene los nombres y compara contra la lista enviada
void Buscar_archivos_y_carpetas(PunteroArtistas *);
void mostrarlista(Artistas *lista);
void BuscarAlbums(char * flaco, Albums **Agregar);
void compraralbum(char * Cadena, PunteroAlbums Album, char *nombre);
#endif // PROTOTIPOS_H_INCLUDED
