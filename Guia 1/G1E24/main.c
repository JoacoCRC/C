#include <stdio.h>
#include <stdlib.h>

/*24. Un sensor de temperatura realiza mediciones periódicas (una cada 5 seg.). Las mismas son
registradas en un archivo binario, donde cada elemento es de tipo float. Implementar un
programa que genere dicho archivo y, otro programa que lo lea y muestre por pantalla
temperatura promedio, máxima y mínima. */

void generaarch();
void leaarch();


int main(){
    generaarch();
    leaarch();
    return 0;
}


void generaarch(){
    FILE *archt,*archb;
    float temp;
    archt=fopen("DatosG1E24.txt","r");
    if (archt==NULL)
        printf("el archivo no eiste\n");
    else{
        archb=fopen("Temperaturas.dat","wb");
        if (archb==NULL)
            printf("el archivo no se abrio correctamente");
        else{
            fscanf(archt,"%f",&temp);
            while (!feof(archt)){
                fwrite(&temp,sizeof(temp),1,archb);
                fscanf(archt,"%f",&temp);
            }
            fwrite(&temp,sizeof(temp),1,archb);
            fclose(archb);   //bien ubicados??
        }
        fclose(archt);
    }
}

void leaarch(){
    FILE *archb;
    float temp,suma=0,cont=0,max,min;
    archb=fopen("Temperaturas.dat","rb");
    if (archb==NULL)
        printf("error al abrir archivo\n");
    else{
        fread(&temp,sizeof(temp),1,archb);
        if (!feof(archb))
            max=min=temp;
        while (!feof(archb)){
            cont++;
            if (temp>max)
                max=temp;
            else
                if (temp<min)
                    min=temp;
            suma+=temp;
            fread(&temp,sizeof(temp),1,archb);
        }
        fclose(archb);
    }
    if(cont>0)
        printf("el promedio es:%5.2f, la maxima es:%5.2f, y la minima:%5.2f", suma/cont, max, min);
    else
        printf("error");

}


/*int main()
{
    FILE *archt,*archb;
    float temp,sum=0,cont=0,max,min;
    archt= fopen("DatosG1E24.txt","r");
    if (archt == NULL)
        printf("archivo no existe!");
    else{
        archb = fopen("Temperaturas.dat","wb");

        fscanf(archt,"%f",&temp);
        fwrite(&temp,4,1,archb);
        while (!feof(archt)){
            fscanf(archt,"%f",&temp);
            fwrite(&temp,4,1,archb);
        }
    }
    fclose(archt);
    fclose(archb);

    archb=fopen("Temperaturas.dat","r");
    fread(&temp,4,1,archb);

    max=min=temp;

    while(!feof(archb)){
        if (temp<min)
            min=temp;
        else
            if (temp>max)
                max=temp;
        cont++;
        sum+=temp;
         fread(&temp,4,1,archb);


    }
    printf("el promedio de temperaturas medida es: %5.2f, la maxima: %5.2f, y la minima: %5.2f",sum/cont,max,min);
    fclose(archb);
    return 0;
}*/
