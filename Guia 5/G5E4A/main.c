/*4. Ingresar en una cola los números almacenados (uno por línea) en un archivo de texto. Mostrar
el contenido de la cola.
a. Utilizar la implementación estática no circular.*/

#include <stdio.h>
#include <stdlib.h>
#include "colas.h"

void leercola(TCola *c);
void mostrarcola(TCola *c);

int main()
{
    TCola c;

    leercola(&c);
    mostrarcola(&c);

    return 0;
}

void leercola(TCola *c){
    FILE* archt;
    int num;
    archt=fopen("DatosG5E4.txt","r");
    if (archt==NULL)
        printf("error al leer archivo\n");
    else{
        IniciaC(c);
        while (!feof(archt)){
            fscanf(archt,"%d\n",&num);
            poneC(c,num);

        }
        fclose(archt);
    }

}

void mostrarcola(TCola *c){
    TElementoC x;
    printf("cola:\n");
    while(!VaciaC(*c)){
        sacaC(c,&x);
        printf("%d\t",x);
    }
}
