#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre[20],apellido[20],nac[20];
    unsigned int puntaje;
}Treg;

void generabin();
void muestradatos(unsigned int pos);

int main(){

    unsigned int pos;

    generabin();
    printf("Ingrese la posicion del ranking para saber los datos del jugador: ");
    scanf("%u",&pos);
    muestradatos(pos);
    return 0;
}

void generabin(){

    FILE *archt,*archb;
    Treg reg1;

    archt=fopen("ej26arch.txt","r");
    if (archt==NULL)
     printf("El archivo de texto no existe");
    else {
     archb=fopen("ej26bin.dat","wb");
     if (archb==NULL)
      printf("El archivo binario no existe");
     else{
      fscanf(archt,"%s",reg1.nombre);
      while (!feof(archt)){
       fscanf(archt,"%s %s",reg1.apellido,reg1.nac);
       fscanf(archt,"%u",&reg1.puntaje);
       fwrite(&reg1,sizeof(reg1),1,archb);
       printf("%s %s %s %u \n",reg1.nombre,reg1.apellido,reg1.nac,reg1.puntaje);
       fscanf(archt,"%s",reg1.nombre);
      }
      fclose(archb);
     }
     fclose(archt);
    }
}

void muestradatos(unsigned int pos){

    FILE *archb;
    Treg reg1;

    archb=fopen("ej26bin.dat","rb");
    if (archb==NULL)
      printf("El archivo binario no existe");
    else{
      fseek(archb,pos,0); /*no baja de linea nunca*/
      fread(&reg1,sizeof(reg1),1,archb);
      printf("En la posicion: %u, esta el jugador: %s %s \n",pos,reg1.nombre,reg1.apellido);
      printf("de nacionalidad:%s, con puntaje: %u",reg1.nac,reg1.puntaje);
    }
}
