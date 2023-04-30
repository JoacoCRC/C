/*15. Simular un juego de naipes donde N jugadores van tomando un naipe del mazo por turno. El
juego finaliza cuando el mazo queda vacío. El puntaje de cada jugador consiste en la sumatoria
de los números de los naipes que fue tomando. Si el palo del naipe tomado coincide con el palo
del levantado en el turno anterior el número se duplica. Implementar utilizando las estructuras
(pilas y/o colas) que considere necesarias.*/

#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

void armarmazo (TPila *p);
void juego (TPila *p,int n, int vec[]);
void mostrarpuntajes(int v[],int n);


int main()
{
    TPila mazo;
    int n,puntos[MAX];

    armarmazo(&mazo);

    printf("ingrese cantidad de jugadores\n");
    scanf("%d",&n);
    juego(&mazo,n,puntos);
    mostrarpuntajes(puntos,n);

    return 0;
}
void armarmazo(TPila *p){
    TElementoP x;
    FILE *archt;

    archt=fopen("DatosG5E15.txt","r");      //problema al leer ultima linea del archivo,agregue una ultima linea con un valor
    if (archt==NULL)                        //este ultimo valor no se guarda y funciona com lo esperado.
        printf("error al leer archivo\n");
    else{
        iniciaP(p);
        fscanf(archt,"%d %c\n",&x.num,&x.palo);
        while (!feof(archt)){
            poneP(p,x);
            fscanf(archt,"%d %c\n",&x.num,&x.palo);
        }
        fclose(archt);
    }
}
void juego(TPila *p, int n, int vec[]){
    TElementoP x;
    char palos[MAX];
    int i;

    for(i=0;i<n;i++){    //INICIALIZO VECTOR PUNTAJES Y VECTOR PALO ANTERIOR
        vec[i]=0;
        palos[i]=' ';
    }
    i=0;
    while (!VaciaP(*p)){
        sacaP(p,&x);
        /*if (i<n){    //TODAVIA NO LLEGO EL TURNO DEL ULTIMO JUGADOR
            if (palos[i]==x.palo)
                vec[i]+= 2*x.num;
            else{
                vec[i]+=x.num;
                palos[i]=x.palo;
            }

            i++;
        }

        else   //LLEGO EL TURNO DEL ULTIMO JUGADOR
           i=0;*/
        if (i==n)
            i=0;
        if (palos[i]==x.palo)
            vec[i]+= 2*x.num;
        else{
            vec[i]+=x.num;
            palos[i]=x.palo;
        }
        i++;
    }
}
void mostrarpuntajes(int v[],int n){
    int i,max=v[0],ganador=1;

    for(i=0;i<n;i++){
        printf("El jugador %d consiguio %d puntos\n",i+1,v[i]);
        if (v[i]>max)
            ganador=i+1;
    }
    printf("El ganador del juego es el jugador %d",ganador);
}

