/*8. Rehacer el ejercicio 2 desarrollado para listas simplemente enlazadas, modificando su
implementación como:
    a) lista doblemente enlazada.

2. Dada una lista simplemente enlazada de caracteres, escribir una función void que:
    a) muestre su contenido.
    b) devuelva la cantidad de nodos que poseen vocales.
    c) indique si la lista está ordenada.
    d) elimine el elemento ubicado en una posición P (entero) pasada como parámetro.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodoS{
    char dato;
    struct nodoS *sig;} nodoS;

typedef nodoS *TListaS;

typedef struct nodoD{
    char dato;
    struct nodoD *ant,*sig;}nodoD;

typedef nodoD *pnodoD;

typedef struct{
    pnodoD pri,ult;}TListaD;


void armarLS(TListaS *LS);
void mostrarLS(TListaS LS);
void armarLD(TListaS LS,TListaD *LD);
void mostrarLD(TListaD LD);
int vocales(TListaD LD);
int ordenada(TListaD LD);
void elimina(TListaD *LD,int n);


int main()
{
    TListaS LS=NULL;
    TListaD LD;
    int n;

    LD.pri=NULL;
    LD.ult=NULL;

    armarLS(&LS);
    mostrarLS(LS);
    armarLD(LS,&LD);
    mostrarLD(LD);
    printf("la lista tiene %d nodos con vocales\n",vocales(LD));
    if(ordenada(LD))
        printf("la lista esta ordenada\n");
    else
        printf("la lista no esta ordenada\n");
    printf("ingrese posicion a eliminar\n");
    scanf("%d",&n);

    elimina(&LD,n);
    mostrarLD(LD);
    return 0;
}
void armarLS(TListaS *LS){
    FILE *archt;
    char car;
    TListaS aux;

    archt=fopen("DatosG6E2.txt","r");
    if (archt==NULL)
        printf("error\n");
    else{
        fscanf(archt,"%c\n",&car);
        while (!feof(archt)){ //insertamos en la cabeza
            aux=(TListaS)malloc(sizeof(nodoS));
            aux->dato=car;
            aux->sig=*LS;
            *LS=aux;
            fscanf(archt,"%c\n",&car);
        }
        fclose(archt);
    }
}
void mostrarLS(TListaS LS){
    TListaS aux=LS;

    while (aux!=NULL){
        printf("%c",aux->dato);
        aux=aux->sig;
    }
    printf("\n");
}
void armarLD(TListaS LS,TListaD *LD){
    TListaS auxS=LS;
    pnodoD nuevoD;

    while(auxS!=NULL){
        nuevoD=(pnodoD)malloc(sizeof(nodoD));
        nuevoD->dato=auxS->dato;
        if((*LD).pri==NULL){
            nuevoD->ant=nuevoD->sig=NULL;
            (*LD).pri=(*LD).ult=nuevoD;
        }
        else{
            nuevoD->ant=(*LD).ult;
            nuevoD->sig=(*LD).ult->sig;
            (*LD).ult->sig=nuevoD;
            (*LD).ult=nuevoD;
        }
        auxS=auxS->sig;

    }
}
void mostrarLD(TListaD LD){
    pnodoD aux=LD.pri;
    while(aux!=NULL){
        printf("%c",aux->dato);
        aux=aux->sig;
    }
    printf("\n");
}
int vocales(TListaD LD){
    int cont=0;
    pnodoD aux=LD.pri;

    while (aux!=NULL){
        if (aux->dato=='a'||aux->dato=='e'||aux->dato=='i'||aux->dato=='o'||aux->dato=='u')
            cont++;
        aux=aux->sig;
    }
    return cont;
}
int ordenada(TListaD LD){
    pnodoD act=LD.pri;
    int ord =1;
    char ant;

    if (act!=NULL){
        ant=act->dato;
        act=act->sig;
        while (act!=NULL && ant<act->dato){
            ant=act->dato;
            act=act->sig;
        }
        if(act!=NULL)
           ord=0;
    }
    return ord;

}
void elimina(TListaD *LD,int n){
    int i=1;
    pnodoD elim,act;

    if ((*LD).pri!=NULL){
        act=(*LD).pri;
        while (act!=NULL && i!=n){
            i++;
            act=act->sig;
        }
        if (act==NULL)
            printf("no existe el nodo %d\n",n);
        else{
            if(i==n){
                if (act->ant!=NULL && act->sig!=NULL){
                    elim=act;
                    act=act->sig;
                    act->ant=elim->ant;
                    elim->ant->sig=act;
                }
                else{
                    if(act->ant==NULL && act->sig==NULL){
                        (*LD).pri=(*LD).ult=NULL;
                        elim=act;
                    }
                    else{
                        if(act->ant==NULL){
                            elim=act;
                            act=act->sig;
                            act->ant=NULL;
                            (*LD).pri=act;
                        }
                        else{
                            elim=act;
                            act=act->ant;
                            act->sig=NULL;
                            (*LD).ult=act;
                        }
                    }
                }
                free(elim);
            }
        }
   }
    else
        printf("la lista esta vacia\n");
}
