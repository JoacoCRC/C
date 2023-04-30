#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char nombre[20];}TReg;


void cargaarchivo();

int main()
{
    FILE* archb;
    TReg reg;
    cargaarchivo();
    archb=fopen("LecturaAdelantada.dat","rb");
    fread(&reg)

    return 0;
}

void cargaarchivo(){

    FILE* archt, *archb;
    char nom[20];
    TReg reg;

    archt=fopen("LecturaAdelantada.txt","r");
    if (archt==NULL)
        printf("error al leer archivo\n");
    else{
        archb=fopen("LecturaAdelantada.dat","wb");
        if (archb==NULL)
            printf("error\n");
        else{
            fscanf(archt,"%s\n",nom);
            while (!feof(archt)){
                strcpy(reg.nombre,nom);
                fwrite(&reg,sizeof(TReg),1,archb);
                printf("%s\n",nom);
                fscanf(archt,"%s",nom);
            }
            fclose(archb);
        }
        fclose(archt);
    }
}
