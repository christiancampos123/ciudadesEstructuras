#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CIUDADES 150

struct datos
{
    char ciudad[20];
    char calle[20];
    float vent;
} vientos[MAX_CIUDADES];

char ciudades[3][30];

void carga_estructura()
{
    int i;
    char cad1[20],cad2[20],cad3[20],cad4[20];
    int id_calle,id_ciudad;
    float valor;
    FILE *pf;
    pf=fopen("C:/Users/christian.campos/Desktop/scriptsDeC/ciudadesEstructuras/callesViento.txt","r");
    if (pf==NULL)
    {
        printf("error abriendo fichero\n");
        exit(1);
    }
    fscanf(pf,"%s %s %s %s\n",cad1,cad2,cad3,cad4);
    i=0;
    while (fscanf(pf,"%d %d %s %f\n",&id_calle,&id_ciudad,cad1,&valor)!=EOF)
    {
        //printf("%d %d %s %.2f\n",id_calle,id_ciudad,cad1,valor);
        //getchar();
        //vientos[i].ciudad[0]='\0';
        //strcat(vientos[i].ciudad,ciudades[id_ciudad]);
        strcpy(vientos[i].ciudad,ciudades[id_ciudad-1]);
        //vientos[i].calle[0]='\0';
        strcpy(vientos[i].calle,cad1);
        vientos[i].vent=valor;
        i++;
    }
    fclose(pf);
}
void carga_ciudades()
{
    FILE *pf;
    char cad1[20],cad2[20];
    int id,i,j;
    pf=fopen("C:/Users/christian.campos/Desktop/scriptsDeC/ciudadesEstructuras/ciudades.txt","r");
    if (pf==NULL)
    {
        printf("error abriendo fichero\n");
        exit(1);
    }
    fscanf(pf,"%s %s\n",cad1,cad2);
    i=0;
    while (fscanf(pf,"%d %s\n",&id,ciudades[i])!=EOF)
        i++;
    fclose(pf);
    //for (j=0;j<i;j++)
        //printf("%s\n",ciudades[j]);
}

void generarStr(){
    carga_ciudades();
    //printf("%s\n",ciudades[0]);
    carga_estructura();
    //printf(vientos[i].ciudad);

}

void ensenarTodo(){
    int i;
    for (i=0;i<MAX_CIUDADES;i++){
        if(strcmp(vientos[i].ciudad,"")==0){
            printf("END");
            break;
        } else {
            printf("%s %s %.2f\n",vientos[i].ciudad,vientos[i].calle,vientos[i].vent);
        }
    }
}

void ensenarCiudades(char* city){
    int i;
    for (i=0;i<MAX_CIUDADES;i++){
        if(strcmp(vientos[i].ciudad,"")==0){
            printf("END");
            break;
        } else {
            if(strcmp(vientos[i].ciudad,city)==0){
                printf("%s %s %.2f\n",vientos[i].ciudad,vientos[i].calle,vientos[i].vent);
            }
            //printf("%s %s %.2f\n",vientos[i].ciudad,vientos[i].calle,vientos[i].vent);
        }
    }
}

void ensenarVientos(int velViento){
    int i;
    for (i=0;i<MAX_CIUDADES;i++){
        if(strcmp(vientos[i].ciudad,"")==0){
            printf("END\n");
            break;
        } else {
            if(vientos[i].vent > velViento){
                printf("%s %s %.2f\n",vientos[i].ciudad,vientos[i].calle,vientos[i].vent);
            }
            //printf("%s %s %.2f\n",vientos[i].ciudad,vientos[i].calle,vientos[i].vent);
        }
    }
}

void mostrarMenu() {
    int opcion;

    while (1) {


        printf("Menu:\n");
        printf("1. Opcion 1 - Mostrar Todo\n");
        printf("2. Opcion 2 - Escriba ciudad\n");
        printf("3. Opcion 3 - Escriba velocidad minima de viento\n");
        printf("4. Salir\n");

        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            ensenarTodo();
        } else if (opcion == 2) {
            char city[30];
            char x[30];
            scanf("%s", &city);
            ensenarCiudades(city);
            getchar();

        } else if (opcion == 3) {
            float velViento;
            // Realizar acciones correspondientes a la opción 3
            printf("Inserte una cantidad de viento");
            scanf("%f", &velViento);
            ensenarVientos(velViento);
        } else if (opcion == 4) {
            break;
        } else {
            printf("Opción inválida. Intente nuevamente.\n");
        }
    }

}

int main(){
    generarStr();
    mostrarMenu();

    /*
    ensenarTodo();
    printf("\n");
    ensenarCiudades("Palma");
    printf("\n");
    ensenarVientos(20);
    */
}
