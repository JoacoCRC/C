/*2. Dada una lista simplemente enlazada de caracteres, escribir una función void que:
a) muestre su contenido.
b) devuelva la cantidad de nodos que poseen vocales.
c) indique si la lista está ordenada.
d) elimine el elemento ubicado en una posición P (entero) pasada como parámetro.*/

#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
    char dato;
    struct nodo *sig;} nodo;

typedef nodo *TLista;


void armalista(TLista *l);
void insertafinal(TLista *l,char car);
void muestralista(TLista l);
int nodosvocales(TLista l);
int ordenada(TLista l);
void eliminanodo(TLista*l,int n);


int main()
{
    TLista l=NULL;
    int pos;

    armalista(&l);

    muestralista(l);
    printf("hay %d nodos con vocales\n",nodosvocales(l));
    if (ordenada(l))
        printf("La lista esta ordenada\n");
    else
        printf("La lista no esta ordenada\n");
    printf("ingrese posicion de nodo a eliminar\n");
    scanf("%d",&pos);
    eliminanodo(&l,pos);
    muestralista(l);

    return 0;
}

void armalista(TLista *l){
    FILE* archt;
    char car;
    archt=fopen("DatosG6E2.txt","r");
    if (archt==NULL)
        printf("error al leer archivo\n");
    else{
        fscanf(archt,"%c\n",&car);
        while(!feof(archt)){
            insertafinal(l,car);
            fscanf(archt,"%c\n",&car);
        }
        fclose(archt);
    }
}
void insertafinal(TLista *l, char car){
    TLista aux,ant;

    aux=(TLista)malloc(sizeof(nodo));
    aux->dato=car;
    aux->sig=NULL;
    if (*l==NULL)
        *l=aux;
    else{
       ant=*l;
       while(ant->sig!=NULL)
            ant=ant->sig;

       ant->sig=aux;
    }
}
void muestralista(TLista l){
    TLista aux;

    aux=l;
    while (aux!=NULL){
        printf("%c",aux->dato);
        aux=aux->sig;
    }
    printf("\n");
}
int nodosvocales(TLista l){
    int i=0;
    TLista aux;

    aux=l;
    while(aux!=NULL){
        if(aux->dato=='a'||aux->dato=='e'||aux->dato=='i'||aux->dato=='o'||aux->dato=='u')
            i++;
        aux=aux->sig;
    }
    return i;
}
int ordenada(TLista l){
    int i=1;
    TLista aux=l;
    char ant;

    if(aux!=NULL ){
        ant=aux->dato;
        aux=aux->sig;
        while (aux!=NULL && ant<aux->dato){
            ant=aux->dato;
            aux=aux->sig;
        }
        if (aux!=NULL)
            i=0;
    }
    return i;
}
void eliminanodo(TLista *l,int n){
    TLista elim=*l,ant=*l;
    int pos=1;

    if(elim!=NULL){
        if(pos==n){//elimino cabeza
           *l=elim->sig;
           free(elim);
        }
        else{
            elim=elim->sig;
            pos++;
            while(elim!=NULL && pos!=n){
                elim=elim->sig;
                ant=ant->sig;
                pos++;
            }
            if(elim==NULL)
                printf("no hay tantos nodos\n");
            else{
               if (pos==n){
                    ant->sig=elim->sig;
                    free(elim);
               }
            }
        }
    }

}
