/*2. Ingresar en una pila los caracteres almacenados (uno por línea) en un archivo de texto. Mostrar
el contenido de la pila.
b. Utilizar la implementación dinámica.*/

#include <stdio.h>
#include <stdlib.h>
#include "PilasDinamicasChar.h"
int main()
{
    FILE*archt;
    char car;
    TPila p;

    archt=fopen("DatosG5E2A.txt","r");
    if (archt==NULL)
        printf("error al leer archivo\n");
    else {
        iniciaP(&p);
        //fscanf(archt,"%c\n",&car);
        while (!feof(archt)){
            fscanf(archt,"%c\n",&car);
            poneP(&p,car);
            //fscanf(archt,"%c\n",&car);
        }
        while (!VaciaP(p)){
            sacaP(&p,&car);
            printf("%c\t",car);
        }
        fclose(archt);
    }
    return 0;
}
