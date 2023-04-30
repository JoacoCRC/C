/*2. A partir de una lista ordenada de enteros, generar dos listas de salida: una conteniendo los
valores impares ordenados descendentemente, y la segunda con los valores pares ordenados
de manera ascendente. No se deberá crear nuevos nodos, sino utilizar los de la lista original
generando nuevos enlaces.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *sig;}nodo;
typedef nodo *TListaS;


void armaL(TListaS *L);
void generalistas(TListaS *L,TListaS *LP,TListaS *LI);
void mostrarL(TListaS L);

int main()
{
    TListaS L=NULL,LP=NULL,LI=NULL;
    armaL(&L);
    printf("LISTA:\n");
    mostrarL(L);

    generalistas(&L,&LP,&LI);
    printf("LISTA PARES:\n");
    mostrarL(LP);
    printf("LISTA IMPARES:\n");
    mostrarL(LI);
    return 0;
}
void armaL(TListaS *L){
    FILE *archt;
    int x;
    TListaS nuevo,ant,act;

    archt=fopen("DatosE2.txt","r");
    if(archt==NULL)
        printf("error al leer archivo\n");
    else{
        fscanf(archt,"%d\n",&x);
        while(!feof(archt)){
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
        fclose(archt);
    }
}
void generalistas(TListaS *L,TListaS *LP,TListaS *LI){
    TListaS aux=*L,auxp;

    while(aux!=NULL){
        *L=aux->sig;
        if(aux->dato%2){//impar SIEMPRE AGREGO EN LA CABEZA
            aux->sig=*LI;
            *LI=aux;
        }
        else{//par SIEMPRE AGREGO AL FINAL
            if(*LP==NULL){
                aux->sig=*LP;
                *LP=aux;
            }
            else{
                auxp=*LP;
                while(auxp->sig!=NULL)
                    auxp=auxp->sig;
                aux->sig=NULL;
                auxp->sig=aux;
            }
        }
        aux=*L;
    }
}
void mostrarL(TListaS L){
    TListaS aux=L;

    while(aux!=NULL){
        printf("%d\t",aux->dato);
        aux=aux->sig;
    }
    printf("\n");
}
