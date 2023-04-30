/*5. Una lista contiene en cada nodo una cola de números enteros. Desarrollar un programa que
genere una pila con los elementos máximos de cada cola de la lista. (Utilizar TDA pila dinámica
y TDA cola circular).*/

#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"
#include "colas.h"

void generapila(TLista l,TPila *p);
int maximocola(TCola c);

int main()
{
    TLista l;  //supongo la lista ya cargada
    TPila p;

    generapila(l,&p);

    return 0;
}
void generapila(TLista l,TPila *p){
    TLista aux;

    iniciaP(p);
    aux=l;
    while (aux!=NULL){
        poneP(p,maximocola(aux->dato));
        aux=aux->sig;
    }
}
int maximocola(TCola c){
    TElementoC x;
    int max=-99999;

    while(!VaciaC(c)){
        sacaC(&c,&x);
        if (x>max)
            max=x;
    }
    return max;
}
