/*25. Dado un árbol binario de números naturales que proviene de la transformación de un bosque,
devolver un arreglo con la clave mayor de cada uno de los árboles que conforman el bosque.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int TElementoA;
typedef struct nodo{
    TElementoA dato;
    struct nodo *iz,*der;} nodo;
typedef nodo* TArbol;

void addnodo(TArbol *a, TElementoA e);
int mayor(TArbol a);
void mayoresporarbol(TArbol a,int *i,int v[]);


int main()
{
    TArbol a;
    int i=0,j,v[MAX];

    ////////// arbol 1 ///////////
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
    ////////// arbol 2 ///////////
    addnodo(&a->der,15);
    addnodo(&a->der->iz,3);
    addnodo(&a->der->iz->der,30);
    addnodo(&a->der->iz->der->der,27);
    addnodo(&a->der->iz->der->iz,41);
    ////////// arbol 3 ///////////
    addnodo(&a->der->der,22);
    addnodo(&a->der->der->iz,61);
    addnodo(&a->der->der->iz->iz,11);
    addnodo(&a->der->der->iz->der,9);
    addnodo(&a->der->der->iz->iz->der,26);
    mayoresporarbol(a,&i,v);
    //printf("\n");
    for(j=0;j<i;j++)
        printf("En el arbol numero %d del bosue la clave maxima es %d\n",j+1,v[j]);
    return 0;
}

void addnodo(TArbol* a, TElementoA e){
    *a = (TArbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->iz = NULL;
    (*a)->der = NULL;
}

void mayoresporarbol(TArbol a,int *i,int v[]){
    int max;
    if (a==NULL)
        printf("el arbol esta vacio\n");
    else
        while(a!=NULL){
            max=mayor(a->iz);
            max=(a->dato > max)?a->dato:max;
            v[*i]=max;
            //printf("En el arbol numero %d del bosue la clave maxima es %d\n",++(*i),max);
            (*i)++;
            a=a->der;
        }
}

int mayor(TArbol a){
    int i,d;
    if (a==NULL)
        return -9999;
    else{
        i=mayor(a->iz);
        d=mayor(a->der);
        if (i>d)
            return (a->dato>i)?a->dato:i;
        else
            return (a->dato>d)?a->dato:d;
    }
}
