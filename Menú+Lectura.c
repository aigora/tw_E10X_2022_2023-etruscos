#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_LONGITUD_LINEA 1000
#define MAX_COLS 25
#define NUM_REGISTROS 18
#define MESES 24
#define BUFF_SIZE 1024


typedef struct {
    float valor;
    char mes[10];
} Dato;

typedef struct {
    char tipo[BUFF_SIZE];
    float valor[MESES];
} Registro;


void obtener_tipos_energia(char* nombre_archivo, char tipos_energia[][MAX_LONGITUD_LINEA]);
void imprimir_tipos_energia(char tipos_energia[][MAX_LONGITUD_LINEA], int num_tipos_energia);
void mostrar_datos_numericos(char* nombre_archivo, int opcion);
void ordenar_datos(Dato datos[], int n);
void mostrar_meses(char *nombre_archivo);
void media_mensual(int energia, Registro *registros);




int main() {

    FILE *pf;
    pf = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");
    Registro registros[NUM_REGISTROS];

    if(pf == NULL){
    printf("Error al abrir el archivo.\n");
            return 1;
    }

    char linea[BUFF_SIZE];
    for(int i = 0; i < 5; i++){
    fgets(linea, BUFF_SIZE, pf);
//    printf("%s", linea);
    }
    int i = 0;
    char separador[] = ",";
    for(i=0; i<NUM_REGISTROS-1; i++){
        fgets(linea, BUFF_SIZE, pf);
        char *token = strtok(linea, separador);
        strncpy(registros[i].tipo, token, BUFF_SIZE);
        //printf("\n%s:\n", registros[i].tipo);
        for(int j = 0; j<MESES; j++){
            token = strtok(NULL, separador);
            registros[i].valor[j] = atof(token);
            //printf("%f, ", registros[i].valor[j]);
        }
    }


    int op, op1;
    char nombre_archivo[] = "generacion_por_tecnologias_21_22_puntos_simplificado.csv";
    char tipos_energia[MAX_LONGITUD_LINEA][MAX_LONGITUD_LINEA];

    obtener_tipos_energia(nombre_archivo, tipos_energia);

    int num_tipos_energia = 17;

    setlocale(LC_ALL, "");

    while (1) {
        printf("\nSeleccione a que tipo de dato quiere acceder\n");
        printf("1.-Fecha\n2.-Tipo de energia\n3.-Año\n");
        printf("Ingrese el numero de su eleccion: ");
        scanf("%d", &op);

        switch (op) {
            case 1:

                while (1) {
                    printf("Que desea hacer con las fechas:\n");
                    printf("1.-Comparar dos fechas\n2.-Consumo total de un mes especifico\n3.-Salir\n");
                    scanf("%i", &op1);

                    switch (op1) {
                        case 1:
                            printf("Ha seleccionado la opción 1.1\n");
                            //comparar fechas
                            break;
                        case 2:
                            printf("Ha seleccionado la opción 1.2\n");
                            //consumo total de un mes
                            break;
                        case 3:
                            break;
                        default:
                            printf("Opcion invalida. Por favor, elija nuevamente.\n");
                            continue;
                    }
                    break;
                }

                break;

            case 2:

                while (1) {
                    printf("\n\nElija una energia para evaluar:\n");
                    imprimir_tipos_energia(tipos_energia, num_tipos_energia);

                    int opcion_energia;
                    scanf("%d", &opcion_energia);

                    if (opcion_energia < 1 || opcion_energia > num_tipos_energia) {
                    printf("Opción inválida.\n");
                    return 0;
                    }

                    printf("Que desea hacer con esta energia:\n1.-Media mensual de gastos\n2.-Comparar 2 energias\n3.-Mostrar datos\n4.-Mes y año de menor gasto\n5.-Mes y año de mayor gasto\n6.-Salir\n");
                    scanf("%i", &op1);

                    switch (op1) {
                        case 1:
                            media_mensual(opcion_energia, registros);
                            break;
                        case 2:
                            printf("Ha seleccionado la opción 2.2\n");
                            break;
                        case 3:
                            mostrar_datos_numericos(nombre_archivo, opcion_energia);
                            break;
                        case 4:
                            printf("Ha seleccionado la opción 2.4\n");
                            break;
                        case 5:
                            printf("Ha seleccionado la opción 2.5\n");
                            break;
                        case 6:
                            break;
                        default:
                            printf("Opción inválida. Por favor, elija nuevamente.\n");
                            continue;
                    }
                    break;
                }

                break;

            case 3:
                while (1) {
                    printf("Por favor seleccione entre uno de los años para un estudio mas detallado:\n");
                    //funcion para imprimir los años
                    //no tengo muy claro la parte de escanear a mano (mejor opciones numeradas?)
                    printf("A continuacion indique que desea evaluar de el año escogido:\n1.-Energia mas consumida en el año 2021\n2.-Energia mas consumida en el año 2022\n");
                    printf("3.-Media de gastos del año 2021\n4.-Media de gastos del año 2022\n5.-Mes con mayor consumicion en el año 2021\n6.-Mes con mayor consumicion en el año\n7.-Ordenar los meses en funcion de cuando se gasta mas\n5.-Salir\n");
                    scanf("%i", &op1);

                    switch (op1) {
                        case 1:
                            printf("Ha seleccionado la opción 3.1\n");
                            break;
                        case 2:
                            printf("Ha seleccionado la opción 3.2\n");
                            break;
                        case 3:
                            printf("Ha seleccionado la opción 3.3\n");
                            break;
                        case 4:
                            printf("Ha seleccionado la opción 3.4\n");
                            break;
                        case 5:
                            printf("Ha seleccionado la opción 3.5\n");
                            break;
                        case 6:
                            printf("Ha seleccionado la opción 3.6\n");
                            break;     
                        case 7:
                            mostrar_meses("generacion_por_tecnologias_21_22_puntos_simplificado.csv");
                            break;
                        case 8:
                            break;
                        default:
                            printf("Opción inválida. Por favor, elija nuevamente.\n");
                            continue;
                    }
                    break;
                }

                break;

            default:
                printf("Opción inválida. Por favor, elija nuevamente.\n");
                continue;
        }

        if (op == 0) {
            break;
        }
    }

    return 0;
}



void obtener_tipos_energia(char* nombre_archivo, char tipos_energia[][MAX_LONGITUD_LINEA]) {
    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    char linea[MAX_LONGITUD_LINEA];
    char *token;
    int num_tipos_energia = 0;
    int num_lineas_leidas = 0;

    while (fgets(linea, MAX_LONGITUD_LINEA, archivo) != NULL) {
        if (num_lineas_leidas >= 5) {
            token = strtok(linea, ",");
            if (token != NULL) {
                strcpy(tipos_energia[num_tipos_energia++], token);
            }
        }
        num_lineas_leidas++;
    }

    fclose(archivo);
}

void imprimir_tipos_energia(char tipos_energia[][MAX_LONGITUD_LINEA], int num_tipos_energia) {
    for (int i = 0; i < num_tipos_energia; i++) {
        printf("%i.%s\n", i+1, tipos_energia[i]);
    }
}

void mostrar_datos_numericos(char* nombre_archivo, int opcion) {
    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    char linea[MAX_LONGITUD_LINEA];
    int contador = 0;
    int contador_energias = 0;
    int energia_seleccionada = opcion - 1;

    while (fgets(linea, MAX_LONGITUD_LINEA, archivo) != NULL) {
        if (contador >= 5) {
            if (contador_energias == energia_seleccionada) {
                printf("\n\nDatos de la energía seleccionada:\n");
                printf("%s", linea);
                break;
            }
            contador_energias++;
        }

        contador++;
    }

    fclose(archivo);
}

void ordenar_datos(Dato datos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (datos[j].valor < datos[j + 1].valor) {
                Dato temp = datos[j];
                datos[j] = datos[j + 1];
                datos[j + 1] = temp;
            }
        }
    }
}

void mostrar_meses(char *nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    char linea[BUFF_SIZE];

    for (int i = 0; i < 4; i++) {
        fgets(linea, BUFF_SIZE, archivo);
    }

    fgets(linea, BUFF_SIZE, archivo);
    char *token = strtok(linea, ",");
    char meses[MAX_COLS][10];
    int i = 0;
    while (token != NULL && i < MAX_COLS) {
        strcpy(meses[i], token);
        token = strtok(NULL, ",");
        i++;
    }

    for (int i = 0; i < 16; i++) {
        fgets(linea, BUFF_SIZE, archivo);
    }

    fgets(linea, BUFF_SIZE, archivo);
    token = strtok(linea, ",");
    float gen_total[MAX_COLS];
    i = 0;
    while (token != NULL && i < MAX_COLS) {
        gen_total[i] = atof(token);
        token = strtok(NULL, ",");
        i++;
    }

    fclose(archivo);

    Dato datos_combinados[MAX_COLS];
    for (int j = 0; j < MAX_COLS; j++) {
        datos_combinados[j].valor = gen_total[j];
        strcpy(datos_combinados[j].mes, meses[j]);
    }

    ordenar_datos(datos_combinados, MAX_COLS);

    printf("Meses con sus respectivas generaciones totales(ordenados de mayor a menor):\n");
    for (int j = 0; j < MAX_COLS; j++) {
        printf("%s: %.2f\n", datos_combinados[j].mes, datos_combinados[j].valor);
    }
}

void media_mensual(int energia, Registro *registros){
energia = energia-1;
float resultado, aux1, aux2;
int i=0;
aux2=0;
for(int x = 0; x < MESES-1; x++){
    aux1 = registros[energia].valor[x] + aux2;
    aux2 = aux1;
}
resultado = aux2/MESES;
printf("La media mensual de %s es de: %f", registros[energia].tipo, resultado);
}
