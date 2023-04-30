/*6. Rehacer los ejercicios 2 y de 3 de pilas mediante subprogramas recursivos. Las pilas no deben
perder su información.
 3. Ingresar los números de DNI de los votantes de una mesa a medida que van votando y mostrar
los últimos N (es dato) votantes
a. en orden inverso, comenzando por el último votante.
b. en el orden que sufragaron.*/

#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

void cargarpila(TPila *p);
void mostrarpila(TPila *p);
void mostrarpilarecu(TPila *p);
void mostrarpilainversrecu(TPila *p);

int main()
{
    TPila p;
    cargarpila(&p);
    mostrarpilarecu(&p);
    printf("\n\n");
    //mostrarpila(&p);
    mostrarpilainversrecu(&p);

    return 0;
}
void cargarpila(TPila *p){
    FILE*archt;
    TElementoP x;

    archt=fopen("DatosG5E3.txt","r");
    if (archt==NULL)
        printf("error\n");
    else{
        iniciaP(p);
        while (!feof(archt)){
            fscanf(archt,"%s %s %s",x.nombre,x.apellido,x.dni);
            poneP(p,x);
        }
        fclose(archt);
    }
}
void mostrarpila(TPila *p){
    TPila aux;
    TElementoP x;
    iniciaP(&aux);
    while(!VaciaP(*p)){
        sacaP(p,&x);
        poneP(&aux,x);
        printf("%s %s\n",x.nombre,x.apellido);
    }
    while (!VaciaP(aux)){
        sacaP(&aux,&x);
        poneP(p,x);
    }


}
void mostrarpilarecu(TPila *p){
    TElementoP x;
    if (!VaciaP(*p)){
       sacaP(p,&x);
       printf("%s %s\n",x.nombre,x.apellido);
       if (!VaciaP(*p)){
            mostrarpilarecu(p);
       }
       poneP(p,x);
    }
}
void mostrarpilainversrecu(TPila *p){
    TElementoP x;
    if (!VaciaP(*p)){
       sacaP(p,&x);

       if (!VaciaP(*p)){
            mostrarpilainversrecu(p);
       }
       printf("%s %s\n",x.nombre,x.apellido);
       poneP(p,x);
    }
}
