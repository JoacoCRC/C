/*8. El draw de un torneo de tenis se representa mediante un árbol binario invertido. Desarrollar
subprogramas que muestren:
a) el nombre del ganador.
b) los nombres de los 2 finalistas.
c) los nombres de los 4 semifinalistas.
d) los nombres de todos los competidores y la cantidad.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef char TElementoA[MAX];
typedef struct nodo{
    TElementoA dato;
    struct nodo *iz,*der;} nodo;
typedef nodo* TArbol;

void addnodo(TArbol* a, TElementoA e);
void resultados(TArbol a);
void mostrarhijos(TArbol a);
void participantes(TArbol a, int *cont);

int main(){
    TArbol a;
    int cont=0;

    addnodo(&a,"ricardo");
    addnodo(&a->iz,"ricardo");
    addnodo(&a->iz->iz,"julian");
    addnodo(&a->iz->iz->iz,"santiago");
    addnodo(&a->iz->iz->der,"julian");
    addnodo(&a->iz->der,"ricardo");
    addnodo(&a->iz->der->iz,"ricardo");
    addnodo(&a->iz->der->der,"juan");
    addnodo(&a->der,"felipe");
    addnodo(&a->der->iz,"felipe");
    addnodo(&a->der->der,"ramiro");
    addnodo(&a->der->der->der,"esteban");
    addnodo(&a->der->der->iz,"ramiro");
    addnodo(&a->der->iz->der,"felipe");
    addnodo(&a->der->iz->iz,"roberto");

    resultados(a);
    printf("Los participantes son\n");
    participantes(a,&cont);
    printf("y son %d\n",cont);

    return 0;
}

void addnodo(TArbol* a, TElementoA e){
    *a = (TArbol)malloc(sizeof(nodo));
    strcpy((*a)->dato , e);
    (*a)->iz = NULL;
    (*a)->der = NULL;
}
void resultados(TArbol a){  //si hay un ganador, al menos hay dos participantes
    if (a!=NULL){
        printf("El ganador es \n-%s\n",a->dato);
        printf("\nLos finalistas fueron: \n");
        mostrarhijos(a);
        if (a->iz->iz!=NULL){
            printf("\nLos semifinalistas fueron: \n");
            mostrarhijos(a->iz);
            mostrarhijos(a->der);
        }
    }
}
void mostrarhijos(TArbol a){

    if (a->iz!=NULL)
        printf("-%s\n-%s\n",a->iz->dato,a->der->dato);

}

void participantes(TArbol a,int *cont){
    if(a!=NULL){
        if(a->iz==NULL && a->der==NULL){
            printf("%s\n",a->dato);
            (*cont)++;
        }
        else{
            participantes(a->iz,cont);
            participantes(a->der,cont);
        }
    }
}

