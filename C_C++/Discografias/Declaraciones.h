#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <dir.h>
#include <dirent.h>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <tchar.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <io.h>
#include <fcntl.h>

using namespace std;

typedef struct qwe
{
    char Nombre[99];
    struct qwe* Siguiente;
}Albums;

typedef Albums* PunteroAlbums;

typedef struct qwe2
{
    char Artista[99];
    Albums *Albumes;
    struct qwe2* Siguiente;
}Artistas;

typedef Artistas* PunteroArtistas;





#endif // DECLARACIONES_H_INCLUDED
