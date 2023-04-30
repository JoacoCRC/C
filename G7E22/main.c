/*22. Dado un árbol binario que proviene de la transformación de un árbol general, obtener la altura
del árbol original */

#include <stdio.h>
#include <stdlib.h>

typedef int TElementoA;
typedef struct nodo{
    TElementoA dato;
    struct nodo *iz,*der;} nodo;
typedef nodo* TArbol;

void addnodo(TArbol *a, TElementoA e);
int altura(TArbol a);

int main(){
    TArbol a;
    int alt;

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
    alt=altura(a);
    if(alt>=0)
        printf("La altura del arbol era %d\n",alt);


    return 0;
}

void addnodo(TArbol* a, TElementoA e){
    *a = (TArbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->iz = NULL;
    (*a)->der = NULL;
}

int altura(TArbol a){
    int i,d;
    if(a==NULL)
        return -1; //para altura uso -1, para nivel 0
    else{
        i=altura(a->iz)+1;
        d=altura(a->der);
        if (i>d)
            return i;
        else
            return d;
    }
}
