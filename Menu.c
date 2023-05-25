#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_LONGITUD_LINEA 1000

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

void procesar_tipos_energia(char tipos_energia[][MAX_LONGITUD_LINEA], int num_tipos_energia) {
    for (int i = 0; i < num_tipos_energia; i++) {
        printf("%i.%s\n", i + 1, tipos_energia[i]);
    }
}



int main() {
    int op, op1;
    char nombre_archivo[] = "generacion_por_tecnologias_21_22_puntos_simplificado.csv";
    char tipos_energia[MAX_LONGITUD_LINEA][MAX_LONGITUD_LINEA];

    obtener_tipos_energia(nombre_archivo, tipos_energia);

    int num_tipos_energia = 17;

    setlocale(LC_ALL, "");

    while (1) {
        printf("Seleccione a que tipo de dato quiere acceder\n");
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
                    printf("Elija una energia para evaluar:\n");
        procesar_tipos_energia(tipos_energia, num_tipos_energia);
        //aqui habria que escanear la opcion seleccionada
        printf("Que desea hacer con esta energia:\n1.-Media mensual de gastos\n2.-Comparar 2 energias\n3.-Mostrar datos\n4.-Mes y año de menor gasto\n5.-Mes y año de mayor gasto\n6.-Salir");
        scanf("%i", &op1);

                    switch (op1) {
                        case 1:
                            printf("Ha seleccionado la opción 2.1\n");
                            break;
                        case 2:
                            printf("Ha seleccionado la opción 2.2\n");
                            break;
                        case 3:
                            printf("Ha seleccionado la opción 2.3\n");
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
                    printf("A continuacion indique que desea evaluar de el año escogido:\n1.-Energia mas consumida en el año\n2.-Media de gastos anuales\n");
                    printf("3.-Mes de mayor consumicion en el año\n4.-Ordenar los meses en funcion de cuando se gasta mas\n5.-Salir");
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



