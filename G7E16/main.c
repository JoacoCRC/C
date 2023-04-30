/*16. Implementar una función iterativa que inserte un elemento en un ABB.*/

#include <stdio.h>
#include <stdlib.h>

typedef int TElementoA;
typedef struct nodo{
    TElementoA dato;
    struct nodo *iz,*der;}nodo;
typedef nodo *TArbol;

void Inserta (TArbol *A, TElementoA X);
void insertait(TArbol *A,TElementoA X);

int main()
{
    TArbol a=NULL;

    Inserta(&a,10);
    Inserta(&a,8);
    Inserta(&a,14);
    Inserta(&a,24);
    Inserta(&a,11);
    Inserta(&a,1);
    Inserta(&a,33);
    Inserta(&a,40);
    Inserta(&a,5);
    Inserta(&a,32);
    Inserta(&a,3);
    Inserta(&a,7);
    Inserta(&a,9);
    Inserta(&a,25);

    insertait(&a,13);

    return 0;
}

void Inserta (TArbol *A, TElementoA X) {
    if (*A == NULL) {
        *A = (TArbol) malloc (sizeof (struct nodo));
        (*A)->dato = X;
        (*A)->der = NULL;
        (*A)->iz = NULL;
    }
    else
        if (X>(*A)->dato)
            Inserta(&((*A)->der), X);
        else
            Inserta(&((*A)->iz), X);
}

void insertait(TArbol *A,TElementoA X){
    TArbol aux,aux1;
    int insertado=0;

    *aux = (TArbol) malloc (sizeof (struct nodo));
    (*aux)->dato = X;
    if (*A==NULL){
        (*aux)->iz=NULL;
        (*aux)->der=NULL;
        *A=aux;
    }
    else{
        aux1=*A;
        while(!insertado){
            if(aux1->dato<X){
                aux1=aux1->der;
            }
        }




        while(aux1->dato<X){
            aux1=aux1->der;
        }
        while(aux1->dato>X){
            aux1=aux1->iz;
        }
    }
}
