/*6. Resolver el ejercicio anterior suponiendo que el digrafo está almacenado en una lista de
adyacencia*/

#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
    int etiueta;
    struct nodo* sig;}nodo;
typedef nodo* TLista;

typedef struct{
    int etiueta;
    TLista lista;}LAdy;


void armalista(LAdy v[]);
void inserta(TLista *l,int x);
void grados(LAdy v[],int n);

int main()
{
    LAdy v[4];
    int i;
    for (i=0;i<4;i++){
        v[i].etiueta=0;
        v[i].lista=NULL;
    }
    armalista(v);
    grados(v,4);
    return 0;
}
void armalista(LAdy v[]){
    v[0].etiueta=1;
    inserta(&v[0].lista,2);
    inserta(&v[0].lista,3);
    v[1].etiueta=2;
    inserta(&v[1].lista,4);
    v[2].etiueta=3;
    inserta(&v[2].lista,2);
    inserta(&v[2].lista,1);
    v[3].etiueta=4;
    inserta(&v[3].lista,3);


}

void inserta(TLista *l,int x){
    TLista aux;

    aux=(TLista)malloc(sizeof(nodo));
    aux->etiueta=x;
    aux->sig=(*l);
    (*l)=aux;
}

void grados(LAdy v[],int n){
    int GrE[n],GrS[n],Gr[n],i;
    TLista l;

    for (i=0;i<n;i++){
        GrE[i]=0;
        GrS[i]=0;
        Gr[i]=0;
    }
    for(i=0;i<n;i++){
        l=v[i].lista;
        while(l!=NULL){
            GrS[i]+=1;
            GrE[l->etiueta -1]+=1;
            if(i+1==l->etiueta)
                Gr[i]-=1;
            l=l->sig;
       }

    }
    for(i=0;i<n;i++){
        Gr[i]+= GrE[i]+GrS[i];
        printf("En el vertice %d el grado de entrada es %d, el de salida %d y el grado es %d\n",i+1,GrE[i],GrS[i],Gr[i]);
    }
}
