/*26. El ranking de una asociación de tenistas es registrada en un archivo binario. Para cada jugador
se registra apellido y nombre, nacionalidad y puntaje. Realizar un subprograma que muestre los
datos del jugador ubicado en una posición recibida como parámetro.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nom[20],ap[20],nac[15];
    int punt;} treg;

void generaarch(int *);

void muestradatos(int *pos,int *cont);

int main()
{
    int pos,cont;

    generaarch(&cont);

    printf("ingrese una posicion(primer posicion 0)\n");
    scanf("%d",&pos);
    muestradatos(&pos,&cont);
    return 0;
}

void generaarch(int *cont){
    FILE *archt, *archb;
    char nom[20],ap[20],nac[15];
    int punt;
    treg reg;

    *cont=0;
    archt=fopen("DatosG1E26.txt","r");
    if (archt==NULL)
        printf("error no se encontro archivo");
    else{
        archb=fopen("ranking.dat","wb");
        if (archb==NULL)
            printf("error");
        else{
            fwrite(&reg,sizeof(treg),1,archb);
            while (!feof(archt)){
                fscanf(archt," %s %s %s %d\n",nom,ap,nac,&punt);
                (*cont)++;
                strcpy(reg.nom,nom);
                strcpy(reg.ap,ap);
                strcpy(reg.nac,nac);
                reg.punt=punt;
                fwrite(&reg,sizeof(treg),1,archb);
            }
            fclose(archb);
        }
        fclose(archt);
    }


}

void muestradatos(int *pos,int *cont){
    FILE *archb;
    treg reg;


    archb=fopen("ranking.dat","rb");

    if (*pos>=*cont)
        printf("error\n");
    else{
        fseek(archb,*pos*sizeof(treg),0);
        fread(&reg,sizeof(treg),1,archb);
        printf("en la posicion ingresada se encuntra %s %s de nacionalidad %s con %d puntos",reg.nom,reg.ap,reg.nac,reg.punt);

    }

}

