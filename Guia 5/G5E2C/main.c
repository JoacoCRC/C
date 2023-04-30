/*2. Ingresar en una pila los caracteres almacenados (uno por línea) en un archivo de texto. Mostrar
el contenido de la pila.
c. Mantener la información en la pila.  */

#include <stdio.h>
#include <stdlib.h>
#include "PilasEstaticasChar.h"

int main()
{
    FILE* archt;
    char car;
    TPila p,aux;


    archt=fopen("DatosG5E2A.txt","r");
    if (archt==NULL)
        printf("no se abrio archivo\n");
    else
        {
        //fscanf(archt,"%c\n",&car);
        iniciaP(&p);
        while (!feof(archt)){
            fscanf(archt,"%c\n",&car);
            poneP(&p,car);
            //(archt,"%c\n",&car);
        }
        fclose(archt);
    }
    iniciaP(&aux);
    while (!VaciaP(p)){
       sacaP(&p,&car);
       printf("%c\t",car);
       poneP(&aux,car);
    }
    while (!VaciaP(aux)){
        sacaP(&aux,&car);
        poneP(&p,car);
    }
    /*printf("\n");
    while (!VaciaP(p)){
       sacaP(&p,&car);
       printf("%c\t",car);
    }*/
    return 0;
}


