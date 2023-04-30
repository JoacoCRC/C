/*24. Dado un árbol binario que proviene de la transformación de un bosque, hallar la cantidad de
árboles del bosque que tenían altura al menos K (dato de entrada)*/

#include <stdio.h>
#include <stdlib.h>

typedef int TElementoA;
typedef struct nodo{
    TElementoA dato;
    struct nodo *iz,*der;} nodo;
typedef nodo* TArbol;

void addnodo(TArbol *a, TElementoA e);
int altura(TArbol a);
int cont(TArbol a,int k);

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
    printf("ingrese grado\n");
    scanf("%d",&k);
    printf("La cantidad de arboles con altura menos a %d es %d\n",k,cont(a,k));

    return 0;
}

void addnodo(TArbol* a, TElementoA e){
    *a = (TArbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->iz = NULL;
    (*a)->der = NULL;
}

int altura(TArbol a){
    int i,d;
    if(a==NULL)
        return 0; //para altura uso -1, para nivel 0
    else{
        i=altura(a->iz)+1;
        d=altura(a->der);
        if (i>d)
            return i;
        else
            return d;
    }
}

int cont(TArbol a,int k){
    if(a==NULL)
        return 0;
    else{
        if (altura(a->iz)+1<k)
            return 1+cont(a->der,k);
        else
            return cont(a->der,k);
    }

}
