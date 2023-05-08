#include <stdio.h>

int main()
{
    int op, op1;


    printf("Menu:\nSeleccione a que tipo de dato quiere acceder\n");
    printf("1.-Fecha\n2.-Tipo de energia\n3.-Año");
    scanf("%i", &op);

    switch(op)
    {
    case 1:
        printf("Que desea hacer con las fechas:\n");
        printf("1.-Comparar dos fechas\n2.-Consumo total de un mes especifico\n3.-Salir");
        scanf("%i", &op1);

        switch(op1)
        {
            case 1:
                //funcion de comparar
            break;

            case 2:
                //funcion de elegir mes
            break;

            default:
                return 0;
        }

    case 2:
        printf("Elija una energia para evaluar:");
        // funcion de escaneo de las energias
        printf("Que desea hacer con esta energia:\n1.-Media mensual de gastos\n2.-Comparar 2 energias\n3.-Mostrar datos\n4.-Mes y año de menor gasto\n5.-Mes y año de mayor gasto\n6.-Salir");
        scanf("%i", &op1);

        switch(op1)
        {
        case 1:
            //funcion de calculo de la media
        break;

        case 2:
            printf("Por favor, seleccione otra energia con la que compararla:\n");
            //funcion de escaneo de la energia seleccionada
            //funcion de cmaparar energias (porcentajes, totales, etc.)
        break;

        case 3:
            //funcion de muestra de datos de energia seleccionada
        break:

        case 4:
        }
    }

    return 0;
}
