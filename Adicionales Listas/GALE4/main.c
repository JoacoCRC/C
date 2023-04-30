/*4. Desarrollar un programa que gestione las reservas de pasajes para los vuelos de una aerolínea.
Para ello se cuenta con una lista de destinos con la siguiente estructura:
• Destino
• Sublista ordenada de Vuelos (a dicho destino)
    o Código de vuelo
    o Fecha y horario de salida
    o Capacidad de pasajeros
    o Sublista de pasajes vendidos (para dicho vuelo)
        ▪ Documento del pasajero
Tanto para la reserva como para su cancelación se solicita: destino, código de vuelo y
documento del pasajero. El programa debe además permitir agregar destinos y vuelos. Cada
vuelo tiene una fecha y horario de salida y capacidad de pasajeros. El programa debe también
listar el estado (cantidad de reservas, lugares disponibles, etc.) de todos los vuelos de un
destino solicitado al operador.
NOTA: Dado que no se requieren cálculos con las fechas y horarios de salida, se sugiere almacenar dicho campo
como una cadena.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

typedef  struct nodoPasajes{
    char dni[10];
    struct nodoPasajes *sig;}nodoPasajes;
typedef nodoPasajes *SubLisPasajes;

typedef struct nodoVuelos{
    char codigo[10],fechayhorario[MAX];
    int capacidad;
    SubLisPasajes pasajes;
    struct nodoVuelos *sig;}nodoVuelos;
typedef nodoVuelos *SubLisVuelos;

typedef struct nodoDes{
    char destino[MAX];
    SubLisVuelos vuelos;
    struct nodoDes *sig;}nodoDes;
typedef nodoDes *TListaDestinos;



void agregarDestino(TListaDestinos *Destinos,char destino[]);
void listarDestinos(TListaDestinos Destinos);
void agregarVuelo(TListaDestinos Destinos,char destino[],char codigo[],char fecha[],int capacidad);
void listarVuelos(TListaDestinos Destinos,char destino[]);
void reservarPasaje(TListaDestinos Destinos,char destino[],char codigo[],char dni[]);
void cancelarPasaje(TListaDestinos Destinos,char destino[],char codigo[],char dni[]);

int main()
{
    TListaDestinos Destinos=NULL;
    char destino[MAX],codigo[10],fecha[MAX],dni[10];
    int res,capacidad;

    printf("Agregar destino (1)\tAgregar vuelo(2)\tListar estado de vuelos con destino...(3)\nReservar pasaje(4)\tCanselar pasaje(5)\tOtro numero para finalizar\n");
    scanf("%d",&res);
    while(res==1||res==2||res==3||res==4||res==5){
        if(res==1){
            printf("ingrese nuevo destino\n");
            scanf("%s",destino);
            agregarDestino(&Destinos,destino);
        }
        else
            if(res==2){
                printf("ingrese destino del vuelo,codigo,fechayhorario y capacidad\n");
                scanf("%s%s%s %d",destino,codigo,fecha,&capacidad);
                agregarVuelo(Destinos,destino,codigo,fecha,capacidad);
            }
            else
                if (res==3){
                    printf("ingrese destino para listar sus vuelos\n");
                    scanf("%s",destino);
                    listarVuelos(Destinos,destino);
                }
                else
                    if(res==4||res==5){
                        printf("ingrese destino,codigo de vuelo y dni");
                        scanf("%s%s%s",destino,codigo,dni);
                        if (res==4)
                            reservarPasaje(Destinos,destino,codigo,dni);
                        else
                            cancelarPasaje(Destinos,destino,codigo,dni);
                    }

        printf("Agregar destino (1)\tAgregar vuelo(2)\tListar estado de vuelos con destino...(3)\nReservar pasaje(4)\tCanselar pasaje(5)\tOtro numero para finalizar\n");
        scanf("%d",&res);
    }
    listarDestinos(Destinos);



    return 0;
}

void agregarDestino(TListaDestinos *Destinos,char destino[]){
    TListaDestinos nuevo;

    nuevo=(TListaDestinos)malloc(sizeof(nodoDes));
    strcpy(nuevo->destino,destino);
    nuevo->vuelos=NULL;
    /*if(*Destinos==NULL)
        nuevo->sig=NULL;
     else
        nuevo->sig=*Destinos;*/
    nuevo->sig=*Destinos;
    *Destinos=nuevo;

}

void agregarVuelo(TListaDestinos Destinos,char destino[],char codigo[],char fecha[],int capacidad){
        TListaDestinos auxD=Destinos;
        SubLisVuelos nuevo,ant,act;

        nuevo=(SubLisVuelos)malloc(sizeof(nodoVuelos));
        strcpy(nuevo->codigo,codigo);
        strcpy(nuevo->fechayhorario,fecha);
        nuevo->capacidad=capacidad;
        nuevo->pasajes=NULL;

        if(auxD!=NULL){
            while(auxD!=NULL && strcmp(auxD->destino,destino)!=0)
                auxD=auxD->sig;
            if (auxD!=NULL){ //se encontro  el destino
                if(auxD->vuelos==NULL || strcmp(auxD->vuelos->codigo,codigo)){
                    nuevo->sig=auxD->vuelos;
                    auxD->vuelos=nuevo;
                }
                else{
                    ant=NULL;
                    act=auxD->vuelos;
                    while (act!=NULL && strcmp(act->codigo,codigo)<0){
                        ant=act;
                        act=act->sig;
                    }
                    nuevo->sig=act;
                    ant->sig=nuevo;
                }
            }
            else
                printf("no se pudo agregar vuelo, no existe el destino en la lista\n");
        }
        else
            printf("no se pudo agregar vuelo, no hay lista de destinos\n");
}

void listarDestinos(TListaDestinos Destinos){
    TListaDestinos aux=Destinos;

    while(aux!=NULL){
        printf("-%s\n",aux->destino);
        aux=aux->sig;
    }
    printf("\n");
}

void listarVuelos(TListaDestinos Destinos,char destino[]){
    TListaDestinos auxD=Destinos;
    SubLisVuelos auxV;
    SubLisPasajes auxP;
    int contPasajes;

    if(auxD!=NULL){
        while(auxD!=NULL && strcmp(auxD->destino,destino)!=0)
            auxD=auxD->sig;
       if (auxD!=NULL){
            auxV=auxD->vuelos;
            while (auxV!=NULL){                   //////
                auxP=auxV->pasajes;
                contPasajes=0;
                if (auxP!=NULL){
                    contPasajes=0;
                    while(auxP!=NULL){
                        contPasajes++;
                        auxP=auxP->sig;
                    }
                }
                printf("-vuelo %s, pasajes reservados %d, pasajes disponibles %d y fechayhora de salida %s\n",auxV->codigo,contPasajes,auxV->capacidad-contPasajes,auxV->fechayhorario);/////
                auxV=auxV->sig;
            }
       }
       else
        printf("no se puede listar vuelos, no existe este destino en la lista\n");
    }
    else
        printf("no se puede listar vuelos, no existe lista de destinos\n");
}

void reservarPasaje(TListaDestinos Destinos,char destino[],char codigo[],char dni[]){
    TListaDestinos auxD=Destinos;
    SubLisVuelos auxV;
    SubLisPasajes auxP,nuevo;
    int sum=1;

    if(auxD!=NULL){
        while(auxD!=NULL && strcmp(auxD->destino,destino)!=0)
            auxD=auxD->sig;
        if(auxD!=NULL){
            auxV=auxD->vuelos;
            if (auxV!=NULL){
                while(auxV!=NULL && strcmp(auxV->codigo,codigo)<0)
                    auxV=auxV->sig;
                if(/*auxV!=NULL &&*/ strcmp(auxV->codigo,codigo)==0){
                    auxP=auxV->pasajes;
                    nuevo=(SubLisPasajes)malloc(sizeof(nodoPasajes));
                    strcpy(nuevo->dni,dni);
                    nuevo->sig=NULL;
                    if(auxP==NULL)
                        auxV->pasajes=nuevo;
                    else{
                        while(auxP->sig!=NULL && auxV->capacidad>sum){
                            auxP=auxP->sig;
                            sum++;
                        }
                        if (sum<auxV->capacidad)
                            auxP->sig=nuevo;
                        else{
                            free(nuevo);
                            printf("no se puede reservar, no hay lugar en el vuelo\n");
                        }
                    }
                }
                else
                    printf("no se puede reservar, no se encontro vuelo en la lista\n");
            }
            else
                printf("no se puede reservar, no existen vuelos a este destino\n");
        }
        else
            printf("no se puede reservar pasaje, no existe el destino en la lista\n");
    }
    else
        printf("no se puede reservar pasaje, no existe lista de destinos\n");
}

void cancelarPasaje(TListaDestinos Destinos,char destino[],char codigo[],char dni[]){
    TListaDestinos auxD=Destinos;
    SubLisVuelos auxV;
    SubLisPasajes ant,elim;

    if(auxD!=NULL){
        while(auxD!=NULL && strcmp(auxD->destino,destino)!=0)
            auxD=auxD->sig;
        if(auxD!=NULL){
            auxV=auxD->vuelos;
            if (auxV!=NULL){
                while(auxV!=NULL && strcmp(auxV->codigo,codigo)<0)
                    auxV=auxV->sig;
                if(auxV!=NULL && strcmp(auxV->codigo,codigo)==0){
                    elim=auxV->pasajes;
                    if (elim!=NULL){
                       ant=NULL;
                       while(elim!=NULL && strcmp(elim->dni,dni)!=0){
                        ant=elim;
                        elim=elim->sig;
                       }
                       if (elim!=NULL){
                            ant->sig=elim->sig;
                            free(elim);
                       }

                    }
                }
            }
        }
    }
}
