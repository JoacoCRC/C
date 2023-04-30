/*1. Generar una lista simplemente enlazada a partir del contenido de un arreglo de N enteros no
ordenados:
a) invirtiendo el orden de sus elementos (no se permite recorrer el arreglo comenzando por el
último elemento)
b) manteniendo el orden de sus elementos.
c) de forma ordenada*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 30

typedef struct nodo{
    int dato;
    struct nodo * sig;} nodo;

typedef nodo * TLista;

void armav(int v[], int *n);
void armalistainvertida(TLista *l,int v[],int n);
void insertarcabeza(TLista *l,int x);
void mostrarlista(TLista l);
void armalista(TLista *l,int v[],int n);
void insertafinal(TLista *l, int x);
void armalistaordenada(TLista *l,int v[],int n);
void insertaord(TLista *l, int x);

int main()
{
    int v[MAX]={},n=0;
    TLista La=NULL,Lb=NULL,Lc=NULL;

    armav(v,&n);
    armalistainvertida(&La,v,n);
    mostrarlista(La);
    printf("\n");
    armalista(&Lb,v,n);
    mostrarlista(Lb);
    printf("\n");
    armalistaordenada(&Lc,v,n);
    mostrarlista(Lc);
    printf("\n");

    return 0;
}
void armav(int v[],int *n){
    FILE *archt;
    int x;

    archt=fopen("DatosG6E1.txt","r");
    if (archt==NULL)
        printf("error al leer archivo\n");
    else{
        fscanf(archt,"%d\n",&x);
        while (!feof(archt)){
            v[*n]=x;
            (*n)++;
            fscanf(archt,"%d",&x);
        }
        fclose(archt);
    }
}
void armalistainvertida(TLista *l,int v[],int n){
    int i=0;
    while (i<n){
       insertarcabeza(l,v[i]);
       i++;
    }
}
void insertarcabeza(TLista *l,int x){
    TLista aux;
    aux=(TLista)malloc(sizeof(nodo));
    aux->dato=x;
    //siempre agrego a la cabeza.
    aux->sig=*l;
    *l=aux;
}
void mostrarlista(TLista l){
    TLista aux=l;

    while (aux!=NULL){
       printf("%d\t",aux->dato);
       aux=aux->sig;
    }
}
void armalista(TLista *l,int v[],int n){
    int i;
    for (i=0;i<n;i++)
        insertafinal(l,v[i]);
}
void insertafinal(TLista *l,int x){
    TLista aux,act;
    aux=(TLista)malloc(sizeof(nodo));
    aux->dato=x;
    if(*l==NULL){
        aux->sig=*l;
        *l=aux;
    }
    else{
        act=*l;
        while (act->sig!=NULL)
           act=act->sig;

        aux->sig=NULL;
        act->sig=aux;
    }
}

void armalistaordenada(TLista *l,int v[],int n){
    int i;
    for (i=0;i<n;i++)
        insertaord(l,v[i]);
}
void insertaord(TLista *l, int x){
    TLista aux,act,ant;

    aux=(TLista)malloc(sizeof(nodo));
    aux->dato=x;

    if(*l==NULL || x<(*l)->dato){
        aux->sig=*l;
        *l=aux;
    }
    else{
        ant=NULL;
        act=*l;
        while(act!=NULL && x>act->dato){
            ant=act;
            act=act->sig;
        }
        aux->sig=act;
        ant->sig=aux;
    }

}
