#include "Declaraciones.h"
#include "Funciones.h"

char* GetClipboardText()
{
    if (! OpenClipboard(0))
        return 0;
    HANDLE hData = GetClipboardData(CF_TEXT);
    if (!hData)
        return 0;
    char* text = static_cast<char*>( GlobalLock(hData) );
    if (!*text)
        return 0;
    GlobalUnlock( hData );
    CloseClipboard();
    return text;
}

void Buscar_archivos_y_carpetas()
{
    string dir, filepath;
    DIR *dp;
    struct dirent *dirp;
    system("cls");
    dir=getenv("OneDrive");
    dir+="\\Musica\\";
    dp = opendir( dir.c_str() );
    if (dp == NULL)
        cout << "Error(" << errno << ") opening " << dir << endl;
    while ((dirp = readdir( dp )))
        if((strcmp(dirp->d_name,".")&&strcmp(dirp->d_name,"Alarma.m3u8")&&strcmp(dirp->d_name,"..")&&strcmp(dirp->d_name,".iTunes Preferences.plist")&&strcmp(dirp->d_name,"desktop.ini")&&strcmp(dirp->d_name,"1Probando")))
        {
            string comando = "PowerShell.exe -NoProfile -Command \"Invoke-WebRequest https://www.google.com.ar/search?q=";
            char* aux=dirp->d_name;
            comando+=*aux;
            while(*++aux)
                if(*aux!=' ')
                    comando+=*aux;
                else
                    comando+='+';
            comando += "+Albums | Set-Clipboard\"";
            printf("%s\n",dirp->d_name);
            system(comando.c_str());
            char cad[100];
            sprintf(cad,"%s%s\0",dir.c_str(),dirp->d_name);
             Buscar_archivos_y_carpetas2(cad);
        }

    closedir( dp );
}

void Buscar_archivos_y_carpetas2( const char* folder2)
{
    string folder = folder2;
    DIR *dp;
    struct dirent *dirp;
    dp = opendir( folder.c_str() );
    if (dp == NULL)
        return;
    string discos;
    while ((dirp = readdir( dp )))
        if(!strstr(dirp->d_name,"."))
        {
            discos+=dirp->d_name;
            discos+=" ; ";
        }
    closedir( dp );
    char aux2[2000];
//    strncpy(aux,strstr(copiado.c_str(),"<DIV class=_wvh>Álbumes</DIV>")+29,2000);
    char *cad2= new char [6000];
    strncpy(cad2,GetClipboardText(),6000);
    cad2=strstr(cad2,"<DIV class=_wvh>")+29;
    strncpy(aux2,cad2,1000);
    char disco[50]={0};
    char *aux=aux2;
    while((aux=strstr(aux,"<DIV title=\"")))
    {
        aux+=12;
        int tam=aux-strstr(aux,"(")-2;
        sprintf(disco,"%*s\0",tam,aux);
        if(!strstr( discos.c_str(),disco))
        {
            cout << "   No se encontro el disco "<< dirp->d_name << endl;
        }
    }
}

