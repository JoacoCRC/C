/*13. Determinar cuántos elementos de un ABB son mayores que A y menores que B. A y B son
parámetros de entrada.*/

#include <stdio.h>
#include <stdlib.h>

typedef int TElementoA;
typedef struct nodo{
    TElementoA dato;
    struct nodo *iz,*der;}nodo;
typedef nodo *TArbol;

void Inserta (TArbol *A, TElementoA X);
int entre(TArbol a,int x,int y);

int main()
{
    TArbol a=NULL;
    int x,y;

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
    printf("ingrese  cota inferior y cota superior\n");
    scanf("%d %d",&x,&y);

    printf("La cantidad de nodos mayores a %d y menores a %d es: %d\n",x,y,entre(a,x,y));

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

int entre(TArbol a,int x,int y){

    if(a==NULL)
        return 0;
    else{
        if(a->dato>x && a->dato<y)
            return 1+entre(a->iz,x,y)+entre(a->der,x,y);
        else{
            if(a->dato<=x)
                return entre(a->der,x,y);
            else
                return entre(a->iz,x,y);
        }
    }
}
