/*3. Desarrollar funciones para:
a) devolver la suma de los elementos múltiplos de 3 de un árbol binario.
b) retornar la cantidad de hojas de un árbol binario.
c) informar si un valor recibido como parámetro se encuentra en un árbol binario. */

#include <stdio.h>
#include <stdlib.h>

typedef int TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *iz;
        struct nodo *der;} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);
void summul3void(arbol a,int *sum);
int summul3int(arbol a);
void conthojasvoid(arbol a, int *cont);
int conthojasint(arbol a);
void estaxvoid(arbol a, int x, int *res);
int estaxint(arbol a, int x);

int main()
{
    arbol a;
    int sum=0,cont=0,x,res;
    addnodo(&a,8);
    addnodo(&a->iz,6);
    addnodo(&a->der,5);
    addnodo(&a->iz->iz,4);
    addnodo(&a->iz->der,3);
    addnodo(&a->iz->der->der,9);
    addnodo(&a->der->der,27);
    addnodo(&a->der->iz,4);

    summul3void(a,&sum);
    printf("la suma de los multiplos de 3 es: %d\n",sum);

    printf("la suma de los multiplos de 3 es: %d\n",summul3int(a));

    conthojasvoid(a,&cont);
    printf("la cantidad de hojas del arbol es: %d\n",cont);

    printf("la cantidad de hojas del arbol es: %d\n",conthojasint(a));

    printf("ingrese valor buscado\n");
    scanf("%d",&x);
    if (estaxint(a,x))
        printf("se encontro x\n");
    else
        printf("no se encontro x\n");

    estaxvoid(a,x,&res);
    if (res)
        printf("se encontro x\n");
    else
        printf("no se encontro x\n");

    return 0;
}

void addnodo(arbol* a, TElememtoA e){
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->iz = NULL;
    (*a)->der = NULL;
}
void summul3void(arbol a,int *sum){

    if (a!=NULL){
        if (a->dato%3==0)
            (*sum)+=a->dato;
        summul3void(a->iz,sum);
        summul3void(a->der,sum);
    }
}
int summul3int(arbol a){
    if(a==NULL)
        return 0;
    else{
        if(a->dato%3==0)
            return a->dato+summul3int(a->iz)+summul3int(a->der);
        else
            return summul3int(a->iz)+summul3int(a->der);
    }
}
void conthojasvoid(arbol a, int *cont){
    if(a!=NULL){
        if(a->iz==NULL && a->der==NULL)
            (*cont)++;
        conthojasvoid(a->iz,cont);
        conthojasvoid(a->der,cont);
    }
}
int conthojasint(arbol a){
   if (a==NULL)
        return 0;
   else{
        if(a->iz==NULL && a->der==NULL)
            return 1;
        else
            return conthojasint(a->iz)+conthojasint(a->der);
   }
}

int estaxint(arbol a, int x){
    if(a==NULL)
        return 0;
    else
        if (a->dato==x)
            return 1;
        else{
            return estaxint(a->iz,x)|| estaxint(a->der,x);
        }
}

void estaxvoid(arbol a, int x, int *res){
    if(a==NULL)
        *res=0 ;
    else
        if(a->dato==x)
            *res=1;
        else{
            estaxvoid(a->iz,x,res);
            if (*res==0)
                estaxvoid(a->der,x,res);
        }
}

