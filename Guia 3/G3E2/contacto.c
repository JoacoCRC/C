#include <stdio.h>
#include "contacto.h"
#include <string.h>


void agregarcontacto(int*i,tnombre nomb,ttel tel, tnombre vn[MAX], ttel vt[MAX]){
    //(*i)++;
    strcpy(vn[*i],nomb);
    strcpy(vt[*i],tel);
    (*i)++;
}

void listar(int i,tnombre vn[MAX],ttel vt[MAX]){
    int j;
    j=i;
    printf("AGENDA:\n");
    for (j=0;j<i;j++){
        printf("%s\t%s\n",vn[j],vt[j]);
    }
}

void buscarpornombre(int i,tnombre vn[MAX],ttel vt[MAX],tnombre nomb){
    int j=0;
    while (strcmp(nomb,vn[j]) && j<i)
        j++;

    if (j<i)
        printf("Contacto:\n%s\t%s\n",vn[j],vt[j]);
    else
        printf("No se encontro contacto\n");
}


