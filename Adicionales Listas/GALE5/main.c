/*5. Resolver mediante subprogramas las siguientes operaciones sobre una lista doblemente
enlazada:
a) insertar un elemento en la posición media. Si la cantidad de elementos de la lista es impar
insertar en la posición media más uno. Considerar la inserción en una lista vacía (único
nodo)
b) eliminar un elemento conociendo la posición (puntero) del anterior, nulo para eliminar el
primer elemento.
c) eliminar todas las ocurrencias del elemento X (recibido como parámetro)*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *ant,*sig;}nodo;
typedef nodo *pnodo;
typedef struct{
    pnodo pri,ult;}TListaD;

void armalista(TListaD *LD);
void mostrar(TListaD LD);
void insertarmedio(TListaD *LD,int x);
int cantnodos(TListaD LD);
void eliminasig(TListaD *LD, pnodo ant);
void eliminaX(TListaD *LD,int x);

int main()
{
    TListaD LD;
    pnodo ant;
    int x;

    armalista(&LD);
    mostrar(LD);
    printf("ingrese valor a insertar\t");
    scanf("%d",&x);
    insertarmedio(&LD,x);
    mostrar(LD);

    ant=LD.ult; //paso el nodo ue uiera
    eliminasig(&LD,ant);
    mostrar(LD);

    printf("ingrese elemento a eliminar de la lista \n");
    scanf("%d",&x);
    eliminaX(&LD,x);
    mostrar(LD);
    return 0;
}
void armalista(TListaD *LD){
    pnodo nuevo;
    FILE*archt;
    int x;

    (*LD).pri=NULL;
    (*LD).ult=NULL;
    archt=fopen("DatosE5.txt","r");
    if(archt==NULL)
        printf("error al leer archivo\n");
    else{
        fscanf(archt,"%d\n",&x);
        while (!feof(archt)){
            nuevo=(pnodo)malloc(sizeof(nodo));
            nuevo->dato=x;
            if ((*LD).pri==NULL){
                nuevo->ant=nuevo->sig=NULL;
                (*LD).pri=(*LD).ult=nuevo;
            }
            else{
                nuevo->ant=(*LD).ult;
                (*LD).ult->sig=nuevo;
                (*LD).ult=nuevo;
            }

            fscanf(archt,"%d\n",&x);
        }
        fclose(archt);
    }
}

void mostrar(TListaD LD){
    pnodo aux=LD.pri;

    while (aux!=NULL){
        printf("%d\t",aux->dato);
        aux=aux->sig;
    }
    printf("\n");
}

void insertarmedio(TListaD *LD,int x){
    pnodo nuevo,inicio,fin;
    int i=1;

    nuevo=(pnodo)malloc(sizeof(nodo));
    nuevo->dato=x;

    if ((*LD).pri==NULL){
        nuevo->ant=nuevo->sig=NULL;
        (*LD).pri=(*LD).ult=nuevo;
    }
    else{
        if((*LD).pri->sig==NULL){
            nuevo->ant=(*LD).pri;
            (*LD).pri->sig=nuevo;
            (*LD).ult=nuevo;
        }
        else{
            inicio=(*LD).pri;
            fin=(*LD).ult;
            while(inicio!=fin){
                if (i){
                    fin=fin->ant;
                    i--;
                }
                else{
                    inicio=inicio->sig;
                    i++;
                }
            }
            nuevo->sig=fin->sig;
            nuevo->ant=fin;
            fin->sig->ant=nuevo;
            fin->sig=nuevo;
        }
    }

}

int cantnodos(TListaD LD){
    pnodo aux=LD.pri;
    int i=1;

    if (LD.pri!=NULL)
        while (aux->sig!=NULL){
            i++;
            aux=aux->sig;
        }
    else
        i=0;

    return i;
}

void eliminasig(TListaD *LD,pnodo ant){
    pnodo elim=(*LD).pri;

    if (elim!=NULL && ant->sig!=NULL){
        if(ant==NULL){ //eliminar primer elemento
            if (elim->sig==NULL) //unico elemento
                (*LD).pri=(*LD).ult=NULL;
            else{
                elim->sig->ant=NULL;
                (*LD).pri=elim->sig;
            }
        }
        else{
            while(elim->ant!=ant){
                elim=elim->sig;
            }
            ant->sig=elim->sig;
            if(elim->sig!=NULL)
                elim->sig->ant=ant;
            else
                (*LD).ult=ant;
        }
        free(elim);
    }
}

void eliminaX(TListaD *LD,int x){
    pnodo act=(*LD).pri,elim;

    if(act!=NULL){
        while(act!=NULL){
            if(act->dato!=x){
                act=act->sig;
            }
            else{
                if((*LD).pri==(*LD).ult){
                    (*LD).pri=(*LD).ult=NULL;
                    elim=act;
                }
                else{
                    if(act->ant==NULL){ //eliminar cabeza
                        act->sig->ant=NULL;
                        elim=act;
                        act=act->sig;
                        (*LD).pri=act;
                    }
                    else{
                        if(act->sig==NULL){//eliminar final
                            act->ant->sig=NULL;
                            (*LD).ult=act->ant;
                            elim=act;
                        }
                        else{//eliminar intermedio
                            act->sig->ant=act->ant;
                            act->ant->sig=act->sig;
                            elim=act;
                            act=act->sig;
                        }
                    }
                }
                free(elim);
            }
        }
    }
}

/*pnodo nuevo,aux; insertamedio
    int nodos,i=1;

    nuevo=(pnodo)malloc(sizeof(nodo));
    nuevo->dato=x;
    if ((*LD).pri==NULL){
        nuevo->ant=nuevo->sig=NULL;
        (*LD).pri=(*LD).ult=nuevo;
    }
    else{
        if((*LD).pri->sig==NULL){
            nuevo->ant=(*LD).pri;
            (*LD).pri->sig=nuevo;
            (*LD).ult=nuevo;
        }
        else{
            aux=(*LD).pri;
            nodos=cantnodos(*LD);
            if (nodos%2)
               nodos=nodos/2 +1;
            else
               nodos/=2;
            while(nodos!=i){
                aux=aux->sig;
                i++;
            }
            nuevo->sig=aux->sig;
            aux->sig->ant=nuevo;
            nuevo->ant=aux;
            aux->sig=nuevo;
        }
    }*/
