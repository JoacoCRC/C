/*14. Generar un arreglo de caracteres con el contenido de las claves de un ABB. Los elementos del
arreglo deben quedar ordenados descendentemente*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 30

typedef char vchar[MAX];
typedef char TElementoA;
typedef struct nodo{
    TElementoA dato;
    struct nodo *iz,*der;}nodo;
typedef nodo *TArbol;

void Inserta (TArbol *A, TElementoA X);
void arreglo(TArbol a,int *i,vchar v);

int main()
{
    TArbol a=NULL;
    vchar v;
    int i,j;


    Inserta(&a,'k');
    Inserta(&a,'n');
    Inserta(&a,'p');
    Inserta(&a,'d');
    Inserta(&a,'z');
    Inserta(&a,'a');
    Inserta(&a,'s');
    Inserta(&a,'b');
    Inserta(&a,'o');
    Inserta(&a,'h');
    Inserta(&a,'y');
    Inserta(&a,'w');
    Inserta(&a,'t');
    Inserta(&a,'c');

    for (i=0;i<MAX;i++)
        v[i]=0;
    i=-1;
    arreglo(a,&i,v);
    for (j=0;j<=i;j++)
        printf("%c ",v[j]);

    return 0;
}

void Inserta (TArbol *A, TElementoA X) {
    if (*A == NULL) {
        *A = (TArbol) malloc (sizeof (struct nodo));
        (*A)->dato = X;
        (*A)->der = NULL;
        (*A)->iz = NULL;
    }
    else
        if (X>(*A)->dato)
            Inserta(&((*A)->der), X);
        else
            Inserta(&((*A)->iz), X);
}

void arreglo(TArbol a,int *i,vchar v){
    if(a!=NULL){
        if (a->der!=NULL)
            arreglo(a->der,i,v);

        v[++(*i)]=a->dato;
        arreglo(a->iz,i,v);
    }
}
