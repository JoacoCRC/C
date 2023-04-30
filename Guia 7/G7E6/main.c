/*6. Dado un árbol binario de cadenas de caracteres retornar el nivel en el que se encuentra la
cadena más larga que comienza con A */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 20

typedef char TElememtoA[MAX];
typedef struct nodo{
        TElememtoA dato;
        struct nodo *iz;
        struct nodo *der;} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);
void nivcadmax(arbol a,int nivact,int *niv,int *cadmax);

int main()
{
    arbol a;
    int niv=0,cadmax=0;

    addnodo(&a,"hola");
    addnodo(&a->iz,"camion");
    addnodo(&a->der,"helicoptero");
    addnodo(&a->iz->iz,"bauto");
    addnodo(&a->iz->der,"bmbulancia");
    addnodo(&a->iz->der->iz,"bavion");
    addnodo(&a->der->der,"baaaaaaa");
    addnodo(&a->der->der->der,"baaaaaaa");
    addnodo(&a->der->der->der->der,"baaaaaaaaaaaaaaaaaaaa");

    nivcadmax(a,0,&niv,&cadmax);
    if(niv)
        printf("la cadena mas larga ue comienza con a del arbol esta en el nivel %d\n",niv);
    else
        printf("no se encontro cadena ue comienze con a en el arbol\n");
    return 0;
}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    strcpy((*a)->dato , e);
    (*a)->iz = NULL;
    (*a)->der = NULL;
}


void nivcadmax(arbol a,int nivact,int *niv,int *cadmax){

    if (a!=NULL){
        nivcadmax(a->iz,nivact+1,niv,cadmax);
        nivcadmax(a->der,nivact+1,niv,cadmax);
        if(a->dato[0]=='a'&& strlen(a->dato)>*cadmax){
            (*niv)=nivact+1;
            *cadmax=strlen(a->dato);
        }
    }
}

