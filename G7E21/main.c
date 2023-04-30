/*21. Dado un árbol binario proveniente de la conversión de un árbol general, obtener el promedio
de las claves cuyo grado era K (dato de entrada). */

#include <stdio.h>
#include <stdlib.h>

typedef int TElementoA;
typedef struct nodo{
    TElementoA dato;
    struct nodo *iz,*der;} nodo;
typedef nodo* TArbol;

void addnodo(TArbol *a, TElementoA e);
void promgradok(TArbol a,int k,int *sum,int *cont);


int main()
{
    TArbol a;
    int k,sum=0,cont=0;

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

    printf("ingrese grado\n");
    scanf("%d",&k);
    promgradok(a,k,&sum,&cont);

    if (cont)
        printf("el promedio de los nodos con grado %d es: %3.2f \n",k,(float)sum/cont);
    return 0;
}

void addnodo(TArbol* a, TElementoA e){
    *a = (TArbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->iz = NULL;
    (*a)->der = NULL;
}

void promgradok(TArbol a,int k, int *sum,int *cont){
    TArbol aux;
    int gr;

    if(a!=NULL){
        aux=a->iz;
        gr=0;
        while(aux!=NULL){
            gr++;
            aux=aux->der;
        }
        if (gr==k){
            *sum+=a->dato;
            (*cont)++;
        }
        promgradok(a->iz,k,sum,cont);
        promgradok(a->der,k,sum,cont);
    }
}

