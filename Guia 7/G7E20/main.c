/*20. Dado un árbol binario proveniente de la conversión de un árbol general, hallar la cantidad de
nodos que habia en niveles impares.  */

#include <stdio.h>
#include <stdlib.h>

typedef int TElementoA;
typedef struct nodo{
    TElementoA dato;
    struct nodo *iz,*der;} nodo;
typedef nodo* TArbol;

void addnodo(TArbol *a, TElementoA e);
int nodosnivelpar(TArbol a,int na);

int main()
{
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

    printf("La cantidad de nodos en niveles impares es: %d",nodosnivelpar(a,1));

    return 0;
}

void addnodo(TArbol* a, TElementoA e){
    *a = (TArbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->iz = NULL;
    (*a)->der = NULL;
}

int nodosnivelpar(TArbol a,int na){
    if (a==NULL)
        return 0;
    else{
        if(na%2 != 0)//nivel impar
            return 1+nodosnivelpar(a->der,na)+nodosnivelpar(a->iz,na+1);
        else
            return nodosnivelpar(a->der,na)+nodosnivelpar(a->iz,na+1);
    }

}




