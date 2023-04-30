/*26. Dado un árbol binario de números naturales que proviene de la transformación de un bosque,
verificar que todos los árboles contengan al menos un nodo de grado K (dato de entrada).*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int TElementoA;
typedef struct nodo{
    TElementoA dato;
    struct nodo *iz,*der;} nodo;
typedef nodo* TArbol;

void addnodo(TArbol *a, TElementoA e);
int congradok(TArbol a, int k);
int gradok(TArbol a,int k);


int main()
{
    TArbol a;
    int k;

    ////////// arbol 1 ///////////
    addnodo(&a,19);
    addnodo(&a->iz,5);
    addnodo(&a->iz->der,20);
    addnodo(&a->iz->iz,1);
    addnodo(&a->iz->iz->der,13);
    addnodo(&a->iz->iz->der->iz,31);
    addnodo(&a->iz->iz->der->iz->der,17);
    //addnodo(&a->iz->iz->der->iz->der->der,55);//para tener nodo grado 3
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
    //addnodo(&a->der->der->iz->der->der,81);//para tener nodo grado 3
    addnodo(&a->der->der->iz->iz->der,26);

    printf("ingrese grado\n");
    scanf("%d",&k);
    if (gradok(a,k))
        printf("todos los arboles tienen un nodo con grado %d",k);
    else
        printf("no todos los arboles tienen un nodo con grado %d",k);

    return 0;
}

void addnodo(TArbol* a, TElementoA e){
    *a = (TArbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->iz = NULL;
    (*a)->der = NULL;
}

int gradok(TArbol a,int k){
    int cond=1;

    if (a==NULL)
        return 0;
    else{
        while(a!=NULL && cond){
            cond=congradok(a->iz,k);
            a=a->der;
        }
        if(cond==0)
            return 0;
        else
            return 1;
    }
}

int congradok(TArbol a,int k){
    int gr;
    TArbol aux;

    if (a==NULL)
        return (k==0)?1:0;
    else{
        gr=0;
        aux=a;
        while(aux!=NULL){
            gr++;
            aux=aux->der;
        }
        if (gr==k)
            return 1;
        else
            return congradok(a->iz,k)||congradok(a->der,k);

    }
}
