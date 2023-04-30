#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*25. Desarrollar un programa que lea y procese un archivo de texto generado por un radar vigía.
Cada línea contiene patente de un vehículo, velocidad registrada, velocidad máxima permitida,
fecha y hora de la medición. Cada dato está separado por un espacio. El programa debe
generar un archivo binario con los registros donde la velocidad registrada supere en más de un
20% a la velocidad máxima. Cada registro del archivo binario contiene los mismos datos que el
archivo de texto. Mostrar, al final del proceso, la cantidad de mediciones procesadas y la
cantidad de registros generados en el archivo binario. */

void generaarch();

int main()
{

    generaarch();
    return 0;
}

void generaarch(){
    FILE *archt, *archb;
    typedef struct{
        char pat[7];
        int vel;
        int velmax;
        char fecha[11];
        char hora[6];} treg;
    treg reg;
    char pat[7],fecha[11],hora[6];
    int vel,velmax,contmed,contreg;

    archt=fopen("DatosG1E25.txt","rt");
    if (archt==NULL)
        printf("archivo no existe!\n");
    else{
        archb=fopen("radar.dat","wb");
        if (archb==NULL)
            printf("el archivo no se abrio correctamente\n");
        else{
            contmed=contreg=0;
            //fscanf(archt,"%s %d %d %s %s \n",pat,&vel,&velmax,fecha,hora);
            while(!feof(archt)){
                fscanf(archt,"%s %d %d %s %s \n",pat,&vel,&velmax,fecha,hora);
                contmed++;
                if (vel>velmax*1.2){
                    contreg++;
                    strcpy(reg.pat,pat);
                    reg.vel=vel;
                    reg.velmax=velmax;
                    strcpy(reg.fecha,fecha);
                    strcpy(reg.hora,hora);
                    fwrite(&reg,sizeof(treg),1,archb);
                }
                //fscanf(archt,"%s %d %d %s %s \n",pat,&vel,&velmax,fecha,hora);
            }
            /*contmed++;
            if (vel>velmax*1.2){
                    contreg++;
                    strcpy(reg.pat,pat);
                    reg.vel=vel;
                    reg.velmax=velmax;
                    strcpy(reg.fecha,fecha);
                    strcpy(reg.hora,hora);
                    fwrite(&reg,sizeof(treg),1,archb);
            }*/
            fclose(archb);
        }
        fclose(archt);
    }
    printf("se hicieron %d mediciones, y %d se pasaron al archivo",contmed,contreg);

}
