/*1. Dadas dos listas simplemente enlazadas de enteros L1 y L2:
a) verificar si son iguales. Considerar que están ordenadas.
b) añadir L2 al final de L1, en el caso de que el primer elemento de L2 sea mayor al último de
L1. En otro caso, añadir L1 al final de L2.
c) eliminar de L1 los nodos cuyas posiciones se encuentran en L2, la cual está ordenada*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *sig;}nodo;
typedef nodo *TListaS;

void armaL(TListaS *L,FILE *archt);
void mostrarL(TListaS L);
int iguales(TListaS L1,TListaS L2);
void aniadir(TListaS *L1,TListaS *L2);
void eliminar(TListaS *L1,TListaS L2);

int main()
{
    TListaS L1=NULL,L2=NULL;
    FILE *archt;

    archt=fopen("DatosE1L1.txt","r");
    armaL(&L1,archt);
    mostrarL(L1);
    archt=fopen("DatosE1L2.txt","r");
    armaL(&L2,archt);
    mostrarL(L2);

    if(iguales(L1,L2))
        printf("son iguales\n");
    else
        printf("no son iguales\n");
    //aniadir(&L1,&L2);
    mostrarL(L1);
    mostrarL(L2);

    eliminar(&L1,L2);  //para probar eliminar() comento funcion aniadir()
    mostrarL(L1);
    mostrarL(L2);
    return 0;
}

void armaL(TListaS *L,FILE *archt){

    int x;
    TListaS nuevo,ant,act;


    if(archt==NULL)
        printf("Error al leer archivo\n");
    else{
        fscanf(archt,"%d\n",&x);
        while (!feof(archt)){
            nuevo=(TListaS)malloc(sizeof(nodo));
            nuevo->dato=x;
            if(*L==NULL || x<(*L)->dato){
                nuevo->sig=*L;
                *L=nuevo;
            }
            else{
               ant=NULL;
               act=*L;
               while(act!=NULL && x>act->dato){
                    ant=act;
                    act=act->sig;
               }
               nuevo->sig=act;
               ant->sig=nuevo;
            }
            fscanf(archt,"%d\n",&x);
        }
    }
}
void mostrarL(TListaS L){
    TListaS aux=L;
    while (aux!=NULL){
        printf("%d\t",aux->dato);
        aux=aux->sig;
    }
    printf("\n");
}
int iguales(TListaS L1,TListaS L2){
    TListaS aux1=L1,aux2=L2;
    int cond=1;

    while(aux1!=NULL && aux2!=NULL && aux1->dato==aux2->dato){
        aux1=aux1->sig;
        aux2=aux2->sig;
    }
    if(aux1==NULL && aux2==NULL)
        cond=1;
    else
        cond=0;

    return cond;

}
void aniadir(TListaS *L1,TListaS *L2){
    TListaS aux;

    if (*L1!=NULL){
        aux=*L1;
        while(aux->sig!=NULL)
            aux=aux->sig;

        if (*L2!=NULL){
            if(aux->dato<(*L2)->dato)
                aux->sig=*L2;
            else{
                aux=*L2;
                while(aux->sig!=NULL)
                    aux=aux->sig;
                aux->sig=*L1;
            }
        }
    }
}
void eliminar(TListaS *L1,TListaS L2){
    TListaS ant,act,aux2,elim;
    int i=1;

    if (*L1!=NULL && L2!=NULL){
        act=*L1;
        ant=NULL;
        aux2=L2;
        while(act!=NULL && aux2!=NULL){
            if(aux2->dato<i)
                aux2=aux2->sig;
            else{
                if (aux2->dato>i){
                    ant=act;
                    act=act->sig;
                    i++;
                }
                else{
                    elim=act;
                    if(*L1==act)
                        *L1=act->sig;

                    else{
                        ant->sig=act->sig;
                    }
                    i++;
                    act=act->sig;
                    free(elim);
                    aux2=aux2->sig;
                }
            }
        }
    }
}
