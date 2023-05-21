#include <stdio.h> <stdlib.h> <string.h>

#define MAX_REGISTROS 18
#define MESES 24


typedef struct {
    char tipo[30];
    float valores[MESES];
} Registro;


int main() {
    FILE *archivo;
    Registro registros[MAX_REGISTROS];
    int i, j;

          /* for(i=0; i<MAX_REGISTROS; i++){
                for(j=0;j<MESES;j++){
                  registros[i].valores[j] = 0;
                }
           } */ //queria asignarles valor 0 a todos porque en la lectura se inventa los 3 o 4 ultimos caracteres decimales

    archivo = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");

//ABRIR fichero
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
//Lee las 5 primeras lineas para empezar a leer desde la 6a (la que nos interesa, con datos)
    char linea[200];
    for (int i = 0; i < 5; i++) {
      fgets(linea, 200, archivo);
    }

//Almacena los datos en una estructura, para cada fila empieza leyendo el nombre como char y a continuación lee los numeros ignorando las comillas
    for (i = 1; i < MAX_REGISTROS; i++) {
        if(i == 8){
        fgets(linea, 2000, archivo);
        }
            //printf("%d", i);
//Primero lee el tipo de generación
            if (fscanf(archivo, "%[^,],", &registros[i].tipo) != 1) {
                printf("Error al leer el nombre.\n");
                return 1;
            }
            printf("\n%s\n", registros[i].tipo);
            //printf("\nok2\n");
//Ahora para cada tipo, lee los datos tipo float
            for (j = 0; j < MESES; j++) {
                if (fscanf(archivo, "%f,", &registros[i].valores[j]) != 1) {
                    printf("Error al leer el numero: %d\n", j);
                    return 1;
                }
                printf("%f, ", registros[i].valores[j]);
            }
    }

    fclose(archivo);
/*
    for (i = 0; i < MAX_REGISTROS; i++) {
        printf("%s:", registros[i].tipo);
        for (j = 0; j < MESES; j++) {
            printf(" %.2f", registros[i].valores[j]);
        }
        printf("\n");
    }
*/
    return 0;
}




