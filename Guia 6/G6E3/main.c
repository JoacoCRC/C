/*3. Escribir un programa que lea desde un archivo un texto que contiene una cantidad desconocida
de palabras (una en cada línea) y genere una lista ordenada de todas las palabras existentes en
el texto con su frecuencia de aparición.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    char dato[15];
    int frec;
    struct nodo *sig;}nodo;

typedef nodo *TLista;

void armarlista(TLista *l);
void insertaord(TLista *l,char palabra[]);
void mostrarlista(TLista l);

int main()
{
    TLista l=NULL;

    armarlista(&l);
    mostrarlista(l);

    return 0;
}

void armarlista(TLista *l){
    FILE *archt;
    char palabra[15];

    archt=fopen("DatosG6E3.txt","r");
    if (archt==NULL)
        printf("error al leer archivo\n");
    else{
        fscanf(archt,"%s\n",palabra);
        while(!feof(archt)){
            insertaord(l,palabra);
            fscanf(archt,"%s\n",palabra);
        }
        fclose(archt);
    }
}

void insertaord(TLista *l,char palabra[]){
    TLista aux,ant,act;

    aux=(TLista)malloc(sizeof(nodo));
    strcpy(aux->dato,palabra);
    if(*l==NULL || strcmp(palabra,(*l)->dato)<=0){
        if (*l!=NULL && strcmp(palabra,(*l)->dato)==0){
            (*l)->frec ++;
            free(aux);
        }
        else{
            aux->frec=1;
            aux->sig=(*l);
            (*l)=aux;
        }
    }
    else{
        ant=NULL;
        act= *l;
        while (act!=NULL && strcmp(palabra,act->dato)>0){//la palabra ya esta en la lista(=0)  la palabra es mayor a la analizada
            ant=act;
            act=act->sig;
        }
        if (act==NULL || (act!=NULL && strcmp(palabra,act->dato)<0)){ //agrego aux al final de la lista
            aux->sig=act;
            aux->frec=1;
            ant->sig=aux;
        }
        else{
            //if(strcmp(palabra,act->dato)=0){ //ya existe la palabra, aumento su frec y libero aux
            act->frec ++;
            free(aux);
            //}
        }
    }
}

void mostrarlista(TLista l){
    TLista aux=l;
    int i=1;

    while (aux!=NULL){
        printf("%d. %s con %d ocurrencias\n",i,aux->dato,aux->frec);
        aux= aux->sig;
        i++;
    }

}


