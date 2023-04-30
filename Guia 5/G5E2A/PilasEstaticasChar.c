#include "PilasEstaticasChar.h"


void iniciaP (TPila * P){
    (*P).tope=-1;
}

void poneP (TPila * P, TElementoP x){
    if ((*P).tope!=MAX-1){
        (*P).tope++;
        (*P).datos[(*P).tope]=x;
    }
}

void sacaP (TPila * P, TElementoP * x){
    if((*P).tope!=-1){
        *x=(*P).datos[(*P).tope];
        (*P).tope--;
    }
}

TElementoP consultaP(TPila P){
   if(P.tope!=0)
    return P.datos[P.tope];
}

int VaciaP (TPila P){
   return (P.tope==-1) ;
}
