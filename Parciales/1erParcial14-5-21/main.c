#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"
#include "colas.h"


typedef struct nodito{
    char tipo[3];
    int disp;
    struct nodito *sig;}nodito;
typedef nodito *SubLista;

typedef struct nodo{
    int numero;
    SubLista sub;
    struct nodo *sig;}nodo;
typedef nodo *TLista;

void distribucion(TLista L,TCola *c);
void eliminarTC(TLista L);

int main(){
    TCola c;
    TLista L=NULL;

    armacola(&c); //inicio y armo la cola
    armalista(&L); //inicia y arma la lista


    distribucion(L,&c);

    eliminarTC(L);

    return 0;
}

void distribucion(TLista L,TCola *c){
    TLista auxL,enuso;
    TElementoC x;
    SubLista antS,actS;
    int despacho=0,cont=0;

    auxL=L;
    while (!VaciaC(*c)){
        sacaC(c,&x);

        if (auxL!=NULL){
            despacho=0;
            while (auxL!=NULL && !despacho){

                    antS=NULL;
                    actS=auxL->sub;
                    while (actS!=NULL && strcmp(actS->tipo,x.tipo)<0){
                        antS=actS;
                        actS=actS->sig;
                    }
                    if (actS!=NULL && strcmp(actS->tipo,x.tipo) ==0 && actS->disp>=x.litros ){
                        actS->disp-=x.litros;
                        despacho=1;
                    }
                    auxL=auxL->sig;

            }
            if (auxL==NULL)
                cont++;
        }
    }
    printf("La catnidad de autos no atendidos es %d\n",cont);
}

void eliminarTC(TLista L){
    TLista auxL;
    int faltan=0,extraido=0;
    SubLista act, ant;

    if (L!=NULL){
        auxL=L;
        while(auxL!=NULL){
            while (auxL!=NULL && auxL->numero %2)
                auxL=auxL->sig;
            if (auxL!=NULL){ //surtidor par
                if (auxL->sub!=NULL){
                    ant=NULL;
                    act=auxL->sub;
                    while (act!=NULL && strcmp(act->tipo,'TC')<0){
                        ant=act;
                        act=act->sig;
                    }
                    if (act!=NULL && strcmp(act->tipo,'TC')==0 && act->disp!=0)){
                        if(ant!=NULL)
                            ant->sig=act->sig;
                        else
                            auxL=auxL->sig;

                        extraido+=act->disp;
                        free(act);
                    }
                    else
                        //if (act!=NULL && strcmp(act->tipo,'TC')>0))
                            falta++;
                }
                else{ // no hay sublista
                    falta++;
                }
                auxL=auxL->sig;
            }

        }
    }
    printf("se extrajeron %d litros y se encontro %d depositos sin el combustible\n ",extraido,faltan);
}
