/*7. Transformar, mediante un subprograma recursivo, una pila de manera que tenga los mismos
datos pero cambiados de signo.*/

#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

void armarpila(TPila *p);
void mostrarpila(TPila *p);
void cambiasigno(TPila *p);

int main()
{
    TPila p;

    armarpila(&p);
    mostrarpila(&p);
    cambiasigno(&p);
    printf("\n");
    mostrarpila(&p);
    return 0;
}
void armarpila(TPila *p){
    int x,res;
    iniciaP(p);
    printf("si uiere ingresar valor a la pila ingrese 1 \n");
    scanf("%d",&res);
    while (res==1){
        printf("ingrese numero\n");
        scanf("%d",&x);
        poneP(p,x);
        printf("si uiere ingresar valor a la pila ingrese 1 \n");
        scanf("%d",&res);
    }
}

void mostrarpila(TPila *p){
    TPila aux;
    TElementoP x;

    iniciaP(&aux);
    while (!VaciaP(*p)){
        sacaP(p,&x);
        printf("%d\t",x);
        poneP(&aux,x);
    }
    printf("\n");
    while (!VaciaP(aux)){
        sacaP(&aux,&x);
        poneP(p,x);
    }
}
void cambiasigno(TPila *p){
    int x;
    if (!VaciaP(*p)){
        sacaP(p,&x);
        if (!VaciaP(*p)){
            cambiasigno(p);
        }
        poneP(p,-x);
    }
}




