/*5. Desarrollar funciones para:
a) calcular la profundidad de un árbol binario.
b) retornar la longitud de la cadena más larga de un árbol binario de cadenas.
c) devolver la cantidad de hijos derechos que contiene un árbol binario*/

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
int prof(arbol a);
int loncadmax(arbol a);
int hijosder(arbol a);

int main()
{
    arbol a;

    addnodo(&a,"hola");
    addnodo(&a->iz,"camion");
    addnodo(&a->der,"helicoptero");
    addnodo(&a->iz->iz,"auto");
    addnodo(&a->iz->der,"ambulancia");
    addnodo(&a->iz->der->iz,"avion");

    printf("la profundidad del arbol es: %d\n",prof(a));
    printf("la longitud de la cadena mas larga del arbol es: %d\n",loncadmax(a));
    printf("la cantidad de hijos derechos del arbol es: %d\n",hijosder(a));

    return 0;
}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    strcpy((*a)->dato , e);
    (*a)->iz = NULL;
    (*a)->der = NULL;
}

int prof(arbol a){
    int i,d;

    if (a==NULL)
        return 0;
    else{
        i=prof(a->iz)+1;
        d=prof(a->der)+1;
        if (i>d)
            return i;
        else
            return d;
    }
}

int loncadmax(arbol a){
    int loni,lond;

    if(a==NULL)
        return 0;
    else{
        loni=loncadmax(a->iz);
        lond=loncadmax(a->der);
        if (strlen(a->dato)>loni && strlen(a->dato)>lond)
            return strlen(a->dato);
        else
            return (loni>lond)?loni:lond;
    }

}

int hijosder(arbol a){

    if (a==NULL)
        return 0;
    else{
        if(a->der!=NULL)
            return 1+hijosder(a->iz)+hijosder(a->der);
        else
            return hijosder(a->iz)/*+hijosder(a->der)*/;
    }
}
