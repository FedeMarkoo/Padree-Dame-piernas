#include <stdio.h>
#include <stdlib.h>

char* itoa_(int num, int base)
{
    char* cad = 0;
    int neg=0;
    if(num<0)
    {
        neg=1;
        num*=-1;
    }
    char dic[base];
    /// /// /// /// /// /// /// /// FUNCION PARA EL LARGO DE LA CADENA /// /// /// /// /// /// /// /// /// /// /// ///
    int tam=1;
    {
        int temp = num;
        while(temp/=base)
            tam++;
        cad = (char*) malloc(tam+1+neg);
        *(cad+tam+neg)=0;
    }
    /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// //// /// /// /// /// /// /// /// /// /// /// /// ///

    /// /// /// /// /// /// /// ///FUNCION DE DICCIONARIO// /// //// /// /// /// /// /// /// /// /// /// /// /// ///
    {
        int temp=-1;
        while(++temp!=base)
            if(temp<10)
                dic[temp]=temp+'0';
            else
                dic[temp]=temp+'A'-10;

    }
    /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// //// /// /// /// /// /// /// /// /// /// /// /// ///
    if(neg)
    {
        *cad=dic[base-1];
    }
    while(tam--)
    {
        if(neg)
            *(cad+tam+neg) = dic[base-(num%base)-1];
        else
            *(cad+tam) = dic[num%base];
        num/=base;
    }

    return cad;
}

void main()
{
    printf("%s\n",itoa_(127 ,2));
    printf("%s",itoa_(-127 ,2));
    return;
}
