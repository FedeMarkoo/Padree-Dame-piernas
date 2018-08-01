#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <wchar.h>


int main()
{
    system("xcopy D:\\Escritorio\\Proyectos\\Ventacelulares\\TextoDeComentario.txt D:\\Escritorio\\Proyectos\\Ventacelulares\\BackUp_TextoDeComentario.txt /Y");
    system("xcopy \"D:\\Escritorio\\Proyectos\\Ventacelulares\\URL a compartir.txt\" \"D:\\Escritorio\\Proyectos\\Ventacelulares\\BackUp_URL a compartir.txt\" /Y");
    do
    {
        {
            FILE *pf = _wfopen(L"D:\\Escritorio\\Proyectos\\Ventacelulares\\TextoDeComentario.txt",L"rt,ccs=UNICODE");
            wchar_t temp = fgetwc(pf);
            wchar_t cad[pf->_cnt]= {0};
            *cad=temp;
            while(*pf->_ptr != ';' && pf->_cnt)
                fgetwc(pf);

            fgetwc(pf);
            fgetwc(pf);

            int i = -1;
            while(pf->_cnt)
                cad[++i]=fgetwc(pf);

            cad[++i]=L'\n';
            cad[++i]=L';';
            cad[++i]=L'\n';

            rewind(pf);
            cad[++i]=fgetwc(pf);
            while(*pf->_ptr != ';' && pf->_cnt)
                cad[++i]=fgetwc(pf);

            wchar_t *aux=cad,*aux2;
            while((aux=wcschr(aux,L'\n')))
            {
                aux2=aux;
                aux++;
            }
            *aux2=L'\0';
            fclose(pf);
            pf = _wfopen(L"D:\\Escritorio\\Proyectos\\Ventacelulares\\TextoDeComentario.txt",L"wt,ccs=UNICODE");
            fputws(cad,pf);
            fclose(pf);
            _putws(cad);
        }
        {
            FILE *pf = fopen("D:\\Escritorio\\Proyectos\\Ventacelulares\\URL a compartir.txt","r");
            char temp = fgetc(pf);
            char cad[pf->_cnt]= {0};
            *cad=temp;
            while(*pf->_ptr != ';' && pf->_cnt)
                fgetc(pf);

            fgetc(pf);
            fgetc(pf);

            int i = -1;
            while(pf->_cnt)
                cad[++i]=fgetc(pf);

            cad[++i]='\n';
            cad[++i]=';';
            cad[++i]='\n';

            rewind(pf);
            cad[++i]=fgetc(pf);
            while(*pf->_ptr != ';' && pf->_cnt)
                cad[++i]=fgetc(pf);

            char *aux=cad,*aux2;
            while((aux=strchr(aux,'\n')))
            {
                aux2=aux;
                aux++;
            }
            *aux2=0;
            fclose(pf);
            pf = fopen("D:\\Escritorio\\Proyectos\\Ventacelulares\\URL a compartir.txt","w");
            fputs(cad,pf);
            fclose(pf);
            puts(cad);
        }
        puts("Desea cambiar el orden? (S/N)");
    }
    while(getch()=='S');
}
