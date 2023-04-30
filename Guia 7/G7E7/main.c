/*7. Desarrollar una función que retorne la suma del contenido de aquellos nodos de un árbol
binario que tengan grado 1 y se encuentren en un nivel X que es dato.*/

#include <stdio.h>
#include <stdlib.h>

typedef int TElementoA;
typedef struct nodo{
    TElementoA dato;
    struct nodo *iz,*der;} nodo;
typedef nodo* TArbol;

void addnodo(TArbol* a, TElementoA e);
int suma(TArbol a,int niv,int nivact);

int main(){
    TArbol a;
    int niv;

    addnodo(&a,5);
    addnodo(&a->iz,7);
    addnodo(&a->iz->iz,8);
    addnodo(&a->iz->der,9);
    addnodo(&a->iz->der->iz,6);
    addnodo(&a->der,3);
    addnodo(&a->der->der,1);
    addnodo(&a->der->der->iz,2);
    addnodo(&a->der->der->iz->der,12);

    printf("ingrese nivel\n");
    scanf("%d",&niv);
    printf("la suma de los nodos de grado uno en el nivel %d es %d\n",niv,suma(a,niv,1));

    return 0;
}

void addnodo(TArbol* a, TElementoA e){
    *a = (TArbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->iz = NULL;
    (*a)->der = NULL;
}

int suma(TArbol a,int niv,int nivact){

    if(a==NULL)
        return 0;
    else
        if (nivact<niv)
            return suma(a->iz,niv,nivact+1)+suma(a->der,niv,nivact+1);
        else
            if((a->iz!=NULL && a->der==NULL) || (a->iz==NULL &&a->der!=NULL))
                return a->dato;
            else
                return 0;

}
