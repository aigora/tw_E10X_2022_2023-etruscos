#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_LONGITUD_LINEA 1000
#define MAX_COLS 25
#define NUM_REGISTROS 18
#define MESES 24
#define BUFF_SIZE 1024
#define MAX_LONG_COL 100
#define MAX_LONG_LINEA 1024
#define MES_MAX_CONS 12
#define MES_MAX_2021 12
#define MES_MAX_2022 24

typedef struct {
    float valor;
    char mes[10];
} Dato;

typedef struct {
    char tipo[BUFF_SIZE];
    float valor[MESES];
} Registro;

typedef struct {
    char nombre[MAX_LONG_COL];
    double sum;
} EnergiaDatos;


void obtener_tipos_energia(char* nombre_archivo, char tipos_energia[][MAX_LONGITUD_LINEA]);
void imprimir_tipos_energia(char tipos_energia[][MAX_LONGITUD_LINEA], int num_tipos_energia);
void mostrar_datos_numericos(char* nombre_archivo, int opcion);
void ordenar_datos(Dato datos[], int n);
void mostrar_meses(char *nombre_archivo);
void media_mensual(int energia, Registro *registros);
void clasificacion(EnergiaDatos orden[], int size);
void Energiaconsumida2021(char* nombre_archivo);
void Energiaconsumida2022(char* nombre_archivo);
void MesConMayorConsumo2021();
void MesConMayorConsumo2022();
void calcularMediaGasto2021();
void calcularMediaGasto2022();



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
        printf("\n\n\t******************************\n\t\t BIENVENIDO \n\t******************************\n\n\t\t ETRUSCOS\n\n\t    Estudio de energias\n\n\t******************************\n\n");
        printf("\n  Seleccione a que tipo de dato quiere acceder\n\n");
        printf("\t1.-Fecha\n\n\t2.-Tipo de energia\n\n\t3.-Año\n\n");
        printf("  Ingrese el numero de su eleccion: ");
        scanf("%d", &op);

        switch (op) {
            case 1:

                while (1) {
                    printf("\n Que desea hacer con las fechas:\n\n");
                    printf("\t1.-Comparar dos fechas\n\t2.-Consumo total de un mes especifico\n\t3.-Salir\n");
                    scanf("  %i", &op1);

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

                    printf("\n Que desea hacer con esta energia:\n\n\t1.-Media mensual de gastos\n\t2.-Comparar 2 energias\n\t3.-Mostrar datos\n\t4.-Mes y año de menor gasto\n\t5.-Mes y año de mayor gasto\n\n\t6.-Salir\n");
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
                    printf("\nA continuacion escoja una de las siguientes opciones:\n\n\t1.-Ordenar los meses en funcion de cuando se gasta mas\n\n");
                    printf("\n\n\t2.-Energias ordenadas de mayor a menor en funcion del gasto en el año 2021\n\t3.-Media de gastos del año 2021\n\t4.-Mes con mayor consumo en el año 2021\n\n");
                    printf("\n\n\t5.-Energias ordenadas de mayor a menor en funcion del gasto en el año 2022\n\t6.-Media de gastos del año 2022\n\t7.-Mes con mayor consumo en el año 2022\n\n\n\t8.-Salir\n");
                    scanf("%i", &op1);

                    switch (op1) {
                        case 1:
                            mostrar_meses("generacion_por_tecnologias_21_22_puntos_simplificado.csv");
                            break;
                        case 2:
                            Energiaconsumida2021(nombre_archivo);
                            break;
                        case 3:
                            calcularMediaGasto2021();
                            break;
                        case 4:
                            MesConMayorConsumo2021();
                            break;
                        case 5:
                            Energiaconsumida2022(nombre_archivo);
                            break;
                        case 6:
                            calcularMediaGasto2022();
                            break;
                        case 7:
                            MesConMayorConsumo2022();
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
void clasificacion(EnergiaDatos orden[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (orden[j].sum < orden[j + 1].sum) {
                EnergiaDatos temp = orden[j];
                orden[j] = orden[j + 1];
                orden[j + 1] = temp;
            }
        }
    }
}
void Energiaconsumida2021(char* nombre_archivo) {
    // Abrir el archivo CSV en modo lectura
    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    char line[MAX_LONGITUD_LINEA];
    char* token;

     // Ignorar las 5 primeras filas
    for (int i = 0; i < 5; i++) {
        fgets(line, sizeof(line), archivo);
    }
    // Leer las filas restantes y realizar los cálculos
    EnergiaDatos ordenEnergia[MAX_LONGITUD_LINEA];
    int cont = 0;

     while (fgets(line, sizeof(line), archivo)) {
        // Obtener el nombre del tipo de energía
        char col[MAX_LONG_COL];
        token = strtok(line, ",");
        strncpy(col, token, sizeof(col));

        // Sumar los valores de las 12 celdas del año 2021
        double sum = 0.0;
        for (int i = 0; i < 12; i++) {
            token = strtok(NULL, ",");
            double value = atof(token);
            sum += value;
        }

        // Almacenar el nombre y la suma 
        EnergiaDatos energiaDatos;
        strncpy(energiaDatos.nombre, col, sizeof(energiaDatos.nombre));
        energiaDatos.sum = sum;
        ordenEnergia[cont] = energiaDatos;
        cont++;
    }

    // Ordenar de mayor a menor
    clasificacion(ordenEnergia, cont);

    // Imprimir el resultado ordenado i=1 para que no tenga en cuenta la generacion total que es la suma de todas las energias
    for (int i = 1; i < cont; i++) {
        printf("%s: %.2f\n", ordenEnergia[i].nombre, ordenEnergia[i].sum);
    }

    // Cerrar el archivo
    fclose(archivo);
}
void Energiaconsumida2022(char* nombre_archivo) {
    // Abrir el archivo CSV en modo lectura
    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    char line[MAX_LONGITUD_LINEA];
    char* token;

     // Ignorar las 5 primeras filas
    for (int i = 0; i < 5; i++) {
        fgets(line, sizeof(line), archivo);
    }
    // Leer las filas restantes y realizar los cálculos
    EnergiaDatos ordenEnergia[MAX_LONGITUD_LINEA];
    int cont = 0;

     while (fgets(line, sizeof(line), archivo)) {
        // Obtener el nombre del tipo de energía
        char col[MAX_LONG_COL];
        token = strtok(line, ",");
        strncpy(col, token, sizeof(col));

        // Sumar los valores de las 12 celdas del año 2022
        double sum = 0.0;
        for (int i = 13; i < 25; i++) {
            token = strtok(NULL, ",");
            double value = atof(token);
            sum += value;
        }

        // Almacenar el nombre y la suma 
        EnergiaDatos energiaDatos;
        strncpy(energiaDatos.nombre, col, sizeof(energiaDatos.nombre));
        energiaDatos.sum = sum;
        ordenEnergia[cont] = energiaDatos;
        cont++;
    }

    // Ordenar de mayor a menor
    clasificacion(ordenEnergia, cont);

    // Imprimir el resultado ordenado i=1 para que no tenga en cuenta la generacion total que es la suma de todas las energias
    for (int i = 1; i < cont; i++) {
        printf("%s: %.2f\n", ordenEnergia[i].nombre, ordenEnergia[i].sum);
    }

    // Cerrar el archivo
    fclose(archivo);
}
void MesConMayorConsumo2021() {
    // Abrir el archivo CSV para lectura
    FILE *archivo = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    // Ignorar las primeras filas hasta llegar a los meses
    char linea[MAX_LONG_LINEA];
    for (int i = 0; i < 4; i++) {
        fgets(linea, MAX_LONG_LINEA, archivo);
    }

    // Leer los nombres de los meses
    char *meses[MES_MAX_2021];
    fgets(linea, MAX_LONG_LINEA, archivo);
    char *token = strtok(linea, ",");
    int contador_mes = 0;
    while (token != NULL && contador_mes < MES_MAX_2021) {
        meses[contador_mes] = strdup(token);
        token = strtok(NULL, ",");
        contador_mes++;
    }

    // Leer los datos de consumo y encontrar el mes con mayor consumo
    double max_consumo = 0.0;
    int max_lista_meses = -1;
    while (fgets(linea, MAX_LONG_LINEA, archivo) != NULL) {
        char *token = strtok(linea, ",");
        int lista_meses = 0;
        while (token != NULL && lista_meses < contador_mes) {
            double consumo = atof(token);
            if (consumo > max_consumo) {
                max_consumo = consumo;
                max_lista_meses = lista_meses;
            }
            token = strtok(NULL, ",");
            lista_meses++;
        }
    }

    // Imprimir el mes con mayor consumo
    if (max_lista_meses != -1) {
        printf("El mes con mayor consumo es %s\n", meses[max_lista_meses]);
    }

    // Cerrar el archivo
    fclose(archivo);
}
void MesConMayorConsumo2022() {
    // Abrir el archivo CSV para lectura
    FILE *archivo = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    // Ignorar las primeras filas hasta llegar a los meses
    char linea[MAX_LONG_LINEA];
    for (int i = 0; i < 4; i++) {
        fgets(linea, MAX_LONG_LINEA, archivo);
    }

    // Leer los nombres de los meses
    char *meses[MES_MAX_2022];
    fgets(linea, MAX_LONG_LINEA, archivo);
    char *token = strtok(linea, ",");
    int contador_mes = 0;
    while (token != NULL && contador_mes < MES_MAX_2022) {
        meses[contador_mes] = strdup(token);
        token = strtok(NULL, ",");
        contador_mes++;
    }

    // Leer los datos de consumo y encontrar el mes con mayor consumo
    double max_consumo = 0.0;
    int max_lista_meses = -1;
    while (fgets(linea, MAX_LONG_LINEA, archivo) != NULL) {
        char *token = strtok(linea, ",");
        int lista_meses = 0;
        while (token != NULL && lista_meses < contador_mes) {
            double consumo = atof(token);
            if (consumo > max_consumo) {
                max_consumo = consumo;
                max_lista_meses = lista_meses;
            }
            token = strtok(NULL, ",");
            lista_meses++;
        }
    }

    // Imprimir el mes con mayor consumo
    if (max_lista_meses != -1) {
        printf("El mes con mayor consumo es %s\n", meses[max_lista_meses]);
    }

    // Cerrar el archivo
    fclose(archivo);
}
void calcularMediaGasto2021() {
    FILE *archivo;
    char linea[MAX_LONG_LINEA];
    char *token;
    double sum = 0.0;
    int count = 0;

    // Abrir el archivo CSV en modo lectura
    archivo = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    // Leer la fila 22 del archivo
    for (int i = 0; i < 22; i++) {
        if (fgets(linea, sizeof(linea), archivo) == NULL) {
            printf("Error al leer el archivo.\n");
            fclose(archivo);
            return;
        }
    }

    // Obtener los datos de las celdas 2 a 13 y calcular la media
    token = strtok(linea, ",");
    for (int i = 0; i < 13; i++) {
        token = strtok(NULL, ",");
        if (token != NULL && i >= 1 && i <= 12) {
            double value = atof(token);
            sum += value;
            count++;
        }
    }

    // Calcular la media y asignar el valor a la variable "media"
    double media = sum / count;

    // Imprimir el resultado
    printf("La media de gasto del año 2021 es: %f\n", media);

    // Cerrar el archivo
    fclose(archivo);
}
void calcularMediaGasto2022() {
    FILE *archivo;
    char linea[MAX_LONG_LINEA];
    char *token;
    double sum = 0.0;
    int count = 0;

    // Abrir el archivo CSV en modo lectura
    archivo = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    // Leer la fila 22 del archivo
    for (int i = 0; i < 22; i++) {
        if (fgets(linea, sizeof(linea), archivo) == NULL) {
            printf("Error al leer el archivo.\n");
            fclose(archivo);
            return;
        }
    }

    // Obtener los datos de las celdas 14 a 25 y calcular la media
    token = strtok(linea, ",");
    for (int i = 1; i < 25; i++) {
        token = strtok(NULL, ",");
        if (token != NULL && i >= 13 && i <= 25) {
            double value = atof(token);
            sum += value;
            count++;
        }
    }

    // Calcular la media y asignar el valor a la variable "media"
    double media = sum / count;

    // Imprimir el resultado
    printf("La media de gasto del año 2021 es: %f\n", media);

    // Cerrar el archivo
    fclose(archivo);
}
