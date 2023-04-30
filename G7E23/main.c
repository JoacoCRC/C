/*23. Dado un árbol binario proveniente de la conversión de un árbol general, determinar el grado de
este último. */

#include <stdio.h>
#include <stdlib.h>

typedef int TElementoA;
typedef struct nodo{
    TElementoA dato;
    struct nodo *iz,*der;} nodo;
typedef nodo* TArbol;

void addnodo(TArbol *a, TElementoA e);
int gradoarbol(TArbol a);


int main(){
    TArbol a;

    addnodo(&a,19);
    addnodo(&a->iz,5);
    addnodo(&a->iz->der,20);
    addnodo(&a->iz->iz,1);
    addnodo(&a->iz->iz->der,13);
    addnodo(&a->iz->iz->der->iz,31);
    addnodo(&a->iz->iz->der->iz->der,17);
    addnodo(&a->iz->der->der,24);
    addnodo(&a->iz->der->der->iz,6);
    addnodo(&a->iz->der->der->iz->der,8);
    addnodo(&a->iz->der->der->iz->der->der,40);
    addnodo(&a->iz->der->der->iz->der->der->der,54);

    printf("El grado del arbol era %d\n",gradoarbol(a));

    return 0;
}

void addnodo(TArbol* a, TElementoA e){
    *a = (TArbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->iz = NULL;
    (*a)->der = NULL;
}

int gradoarbol(TArbol a){
    TArbol aux;
    int gract;

    if (a==NULL)
        return -1;
    else{
        aux=a->iz;
        gract=0;
        while(aux!=NULL){
            gract++;
            aux=aux->der;
        }

    }
}
