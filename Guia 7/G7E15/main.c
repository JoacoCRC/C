/*15. Desarrollar una función que compruebe que si un árbol binario es un ABB.*/

#include <stdio.h>
#include <stdlib.h>

typedef int TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *iz;
        struct nodo *der;} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);
int ABB(arbol a,arbol aux);
//void ABBvoid(arbol a,int *ABB,int *raiz);

int main()
{
    arbol a;


    addnodo(&a,8);
    addnodo(&a->iz,6);
    addnodo(&a->der,11);
    addnodo(&a->iz->iz,4);
    addnodo(&a->iz->der,7);
    addnodo(&a->der->der,27);
    addnodo(&a->der->iz,6);

    if(ABB(a,a))
        printf("el arbol es ABB");
    else
        printf("el arbol no es ABB");

    return 0;
}

void addnodo(arbol* a, TElememtoA e){
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->iz = NULL;
    (*a)->der = NULL;
}

/*void ABBvoid(arbol a,int *ABB,int *raiz){
    if(a==NULL)
        *ABB=0;
    else{
        if (a->iz==NULL && a->der==NULL && *ABB!=0)


    }

}*/
int ABB(arbol a,arbol aux){

    if (a==NULL)
        return 0;
    else{
        if(a->iz!=NULL) //&& a->iz!=NULL)// && a->iz->dato<a->dato)


    }

}
