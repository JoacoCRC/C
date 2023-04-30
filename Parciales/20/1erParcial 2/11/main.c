#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct {
    char comercio[4];
    int pedido;
    char estado;
    float importe;}TElementoP;

typedef  struct {
    TElementoP datos[MAX];
    int tope;}TPila;

typedef struct nodito{
    int pedido;
    float importe;
    struct nodito *sig;}nodito;
typedef nodito *SubLista;

typedef struct nodo{
    char comercio[4];
    float importetot;
    SubLista Sub;
    struct nodo *sig;}nodo;
typedef nodo *TLista;

void tomapedidos(TLista *l,TPila *p);


int main()
{
    TPila p;
    TLista l;
    int rinf,rsup;

    armapila(&p); //se inicia la pila y se cargan los pedidos
    armalista(&l); //se crea la lista

    tomapedidos(&l,&p);
    printf("ingrese rango inferior y rango superior de pedidos a eliminar\n");
    scanf("%d %d",&rinf,&rsup);
    eliminarpedidos(l,rinf,rsup);
    return 0;
}

void tomapedidos(TLista *l,TPila *p){
    TPila auxp;
    TElementoP x;
    SubLista nuevopedido;
    TLista actcomercios=*l,nuevocomercio,antcomercio;;

    iniciaP(&auxp);
    while (!VaciaP(*p)){
        sacaP(p,&x);
        if (x.estado=='P') //estado autorizado agrego pedido a la lista
            poneP(&auxp,x);
        else{
            nuevopedido=(SubLista)malloc(sizeof(nodito));
            nuevopedido->pedido=x.pedido;
            nuevopedido->importe=x.importe;
            nuevopedido->sig=NULL;

            nuevocomercio=(TLista)malloc(sizeof(nodo));
            strcpy(nuevocomercio->comercio,x.comercio);
            nuevocomercio->importetot=0.05*x.importe;
            nuevocomercio->Sub=nuevopedido;


            if ((*l)==NULL || strcmp((*l)->comercio,x.comercio)>0){
                nuevocomercio->sig=(*l);
                (*l)=nuevocomercio;
            }
            else{
                antcomercio=NULL;
                actcomercios=(*l);
                while(actcomercios!=NULL && strcmp(actcomercios->comercio,x.comercio)<0){
                    antcomercio=actcomercios;
                    actcomercios=actcomercios->sig;
                }
                if(actcomercios==NULL || strcmp(actcomercios->comercio,x.comercio)>0) {
                    nuevocomercio->sig=actcomercios;
                    antcomercio->sig=nuevocomercio;
                }
                else{ //act no es NULL y act->com=x.com
                    actcomercios->importetot+=nuevocomercio->importetot;
                    free(nuevocomercio);
                    nuevopedido->sig=actcomercios->Sub;
                    actcomercios->Sub=nuevopedido;
                }
            }
        }
    }
    while(!VaciaP(auxp)){
        sacaP(&auxp,&x);
        poneP(p,x);
    }
}

void eliminapedidos(TLista l,int rinf,int rsup){
    TLista auxcomercios=l;
    SubLista ant,act,elim;
    float nuevoimporte;

    while (auxcomercios!=NULL){
        if(auxcomercios->Sub!=NULL){
            nuevoimporte=0;
            ant=NULL;
            act=auxcomercios->Sub;
            while(act!=NULL){
                if (act->pedido<rinf || act->pedido>rsup){
                    nuevoimporte+=0.05*act->importe;
                    ant=act;
                    act=act->sig;
                }
                else{
                    elim=act;
                    act=act->sig;
                    if (ant==NULL)
                        auxcomercios->Sub=act;
                    else
                       ant->sig=act;
                    free(elim);
                }
                if (auxcomercios->Sub==NULL)
                    printf("no uedaron pedidos en el comercio %s",auxcomercios->comercio);

            }
            auxcomercios->importetot=nuevoimporte;
            auxcomercios=auxcomercios->sig;
        }
        else
            printf("el comercio %s no tiene pedidos\n",auxcomercios->comercio);

    }
}
