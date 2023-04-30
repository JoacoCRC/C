/*19. Dado un árbol binario que proviene de la transformación de un bosque, determinar qué
cantidad de árboles lo componían. */

#include <stdio.h>
#include <stdlib.h>

typedef int TElementoA;
typedef struct nodo{
    TElementoA dato;
    struct nodo *iz,*der;} nodo;
typedef nodo* TArbol;

void addnodo(TArbol *a, TElementoA e);
int cantarboles(TArbol a);

int main()
{
    TArbol a;

    addnodo(&a,10);
    addnodo(&a->iz,8);
    addnodo(&a->iz->der,9);
    addnodo(&a->iz->iz,1);
    addnodo(&a->der,2);
    addnodo(&a->der->der,4);

    printf("La cantidad de arboles ue componian este bosue es: %d",cantarboles(a));

    return 0;
}

void addnodo(TArbol* a, TElementoA e){
    *a = (TArbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->iz = NULL;
    (*a)->der = NULL;
}

int cantarboles(TArbol a){
    if (a==NULL)
        return 0;
    else{
        return 1+cantarboles(a->der);
    }
}
