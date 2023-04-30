/*6. Rehacer los ejercicios 2 y de 3 de pilas mediante subprogramas recursivos. Las pilas no deben
perder su información.
 2. Ingresar en una pila los caracteres almacenados (uno por línea) en un archivo de texto. Mostrar
el contenido de la pila.
a. Utilizar la implementación estática.*/

#include <stdio.h>
#include <stdlib.h>
#include "PilasEstaticasChar.h"

void leerpila(TPila *p);
void mostrarpila(TPila *p);

int main()
{
    TPila p;

    leerpila(&p);
    if (!VaciaP(p)){
        mostrarpila(&p);
        printf("\n");
    }
    if (!VaciaP(p)){
        mostrarpila(&p);
        printf("\n");
    }
    else
        printf("la pila esta vacia\n");

    return 0;
}

void leerpila(TPila *p){
    FILE* archt;
    TElementoP x;

    archt=fopen("DatosG5E2A.txt","r");
    if (archt==NULL)
        printf("error al leer archivo\n");
    else{
        iniciaP(p);
        while (!feof(archt)){
            fscanf(archt,"%c\n",&x);
            poneP(p,x);
        }
        fclose(archt);
    }
}

void mostrarpila(TPila *p){
    TElementoP x;
    if (!VaciaP(*p)){
        sacaP(p,&x);
        printf("%c\t",x);
        if (!VaciaP(*p))
            mostrarpila(p);
        poneP(p,x);
    }
}
