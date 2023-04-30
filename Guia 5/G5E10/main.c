/*10. Simular un sistema de computación simplificado, donde cada proceso posee un ID, el tiempo de
solicitud y su duración (ambos en segundos). Los procesos están ordenados ascendentemente
por tiempo de solicitud, y cada uno comienza cuando el anterior ha finalizado. El programa
debe mostrar para cada proceso el tiempo en que empieza y termina. Al finalizar mostrar
tiempo promedio de espera. */

#include <stdio.h>
#include <stdlib.h>
#include "colas.h"


void armarcola(TCola *c,int *i);
void demoras(TCola *c,int cont);
void muestracola(TCola *c);

int main()
{
    TCola c;
    int cont=0;
    armarcola(&c,&cont);

    //muestracola(&c);
    demoras(&c,cont);

    return 0;
}
void armarcola(TCola *c,int * i){
    FILE*archt;
    TElementoC x;

    archt=fopen("DatosG5E10.txt","r");
    if (archt==NULL)
        printf("error al leer archivo\n");
    else{
        IniciaC(c);
        fscanf(archt,"%s %d %d",x.id,&x.tsol,&x.tdur);
        while (!feof(archt)){
            poneC(c,x);
            (*i)++;
            fscanf(archt,"%s %d %d",x.id,&x.tsol,&x.tdur);
        }
        fclose(archt);
    }
}
void muestracola(TCola *c){
    TElementoC x;
    while (!VaciaC(*c)){
        sacaC(c,&x);
        printf("%s %d %d\n",x.id,x.tsol,x.tdur);
    }
}
void demoras(TCola *c,int cont){
    TElementoC x;
    int finant=0,sum=0;
    while (!VaciaC(*c)){
        sacaC(c,&x);
        if (finant<=x.tsol){ //cuando se solicita proceso  no se esta ejecutando nada o justo termina
            finant=x.tsol+x.tdur;

            printf("el proceso %s, empieza a los %d s y termina a los %d s\n",x.id,x.tsol,finant);
        }
        else{ //cuando se solicita el nuevo proceso sigue ejecutando el anterior, arranca cuando termina este
            printf("el proceso %s, empieza a los %d s y termina a los %d s\n",x.id,finant,finant+x.tdur);
            sum+=finant-x.tsol;
            finant+=x.tdur;
        }
    }
    printf("tiempo promedio de espera %5.2f s",(float) sum/cont);
}

