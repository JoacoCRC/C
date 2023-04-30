/*10. Dada una lista doblemente enlazada de caracteres, verificar si una palabra es palíndroma.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodoD{
    char letra;
    struct nodoD *ant,*sig;}nodoD;
typedef nodoD *pnodoD;
typedef struct{
    pnodoD pri,ult;}TListaD;

void armaLD(TListaD *LD);
void mostrarLD(TListaD LD);
int palindroma(TListaD LD);

int main()
{
    TListaD LD;

    LD.pri=NULL;
    LD.ult=NULL;

    armaLD(&LD);
    mostrarLD(LD);
    if(palindroma(LD))
        printf("la palabra es palindroma\n");
    else
        printf("la palabra no es palindroma\n");

    return 0;
}
void armaLD(TListaD *LD){
    FILE *archt;
    pnodoD nuevo;
    char letra;

    archt=fopen("DatosG6E10.txt","r");
    if(archt==NULL)
        printf("error al leer archivo\n");
    else{
        fscanf(archt,"%c\n",&letra);

        while(!feof(archt)){
            nuevo=(pnodoD)malloc(sizeof(nodoD));
            nuevo->letra=letra;
            if((*LD).pri==NULL){
                nuevo->ant=nuevo->sig=NULL;
                (*LD).pri=(*LD).ult=nuevo;
            }
            else{
                nuevo->ant=(*LD).ult;
                nuevo->sig=NULL;
                (*LD).ult->sig=nuevo;
                (*LD).ult=nuevo;
            }
            fscanf(archt,"%c\n",&letra);
        }
        fclose(archt);
    }
}
void mostrarLD(TListaD LD){
    pnodoD act=LD.pri;

    if(act!=NULL){
        act=LD.pri;
        while(act!=NULL){
            printf("%c\t",act->letra);
            act=act->sig;
        }
        printf("\n");
    }
}
int palindroma(TListaD LD){
    int cond=1;
    pnodoD prin,fin;

    if(LD.pri!=NULL){
        prin=LD.pri;
        fin=LD.ult;
        if (prin!=fin){ //mas de un nodo
            while(prin!=NULL && prin->letra==fin->letra ){
                prin=prin->sig;
                fin=fin->ant;
            }
            if (prin!=NULL)
                cond=0;
        }
    }
    return cond;
}
