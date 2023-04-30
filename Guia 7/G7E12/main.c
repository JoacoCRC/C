/*12. Retornar el valor mínimo de un ABB. */

#include <stdio.h>
#include <stdlib.h>

typedef int TElementoA;
typedef struct nodo{
    TElementoA dato;
    struct nodo *iz,*der;}nodo;
typedef nodo *TArbol;

void Inserta (TArbol *A, TElementoA X);
int minimo(TArbol a);

int main()
{
    TArbol a=NULL;

    Inserta(&a,10);
    Inserta(&a,8);
    Inserta(&a,14);
    Inserta(&a,24);
    Inserta(&a,11);
    Inserta(&a,1);
    Inserta(&a,33);
    Inserta(&a,40);
    Inserta(&a,5);
    Inserta(&a,32);
    Inserta(&a,3);
    Inserta(&a,7);
    Inserta(&a,9);
    Inserta(&a,25);

    printf("El elemento minimo del ABB es %d\n",minimo(a));

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

int minimo(TArbol a){
    if(a==NULL)
        return 0;
    else
        if (a->iz!=NULL)
            return minimo(a->iz);
        else
            return a->dato;

}
