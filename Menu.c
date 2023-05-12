#include <stdio.h>

int main()
{
    int op, op1, i;

    do
        {
        printf("Menu:\nSeleccione a que tipo de dato quiere acceder\n");
        printf("1.-Fecha\n2.-Tipo de energia\n3.-Año\n");
        scanf("%i", &op);
        } while(op > 3 || op < 1);

    switch(op)
    {
    case 1:
        do
        {
            printf("Que desea hacer con las fechas:\n");
        printf("1.-Comparar dos fechas\n2.-Consumo total de un mes especifico\n3.-Salir\n");
        scanf("%i", &op1);

        switch(op1) //aqui hay un fallo con el do while, si no es una de las opciones pasa al case 2
        {
            case 1:
                //funcion de comparar
            break;

            case 2:
                //funcion de elegir mes
            break;

            case 3:
                return 0;
            break;

            default:
                printf("Opcion seleccionada no valida, pofavor intentelo de nuevo\n");
        }
        break;
        }
        while(op1 < 1 || op1 > 3);

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
        break;

        case 4:
            //funcion para elegir el mes y año de menor gasto
        break;

        case 5:
            //funcion para elegir el mes y año de mayor gasto
        break;

        case 6:
            return 0;
        break;

        default:
            printf("Opcion elegida no valida, porfavor vuelva a introducir un valor\n")
        }
        break;

    case 3:
       printf("Por favor seleccione uno de los dos años para un estudio mas detallado:\n");
       //no tengo muy claro la parte de escanear a mano (mejor opciones numeradas?)
       printf("A continuacion indique que desea evaluar de el año escogido:\n1.-Energia mas consumida en el año\n2.-Media de gastos anuales\n3.-Mes de mayor consumicion en el año\n4.-Ordenar los meses en funcion de cuando se gasta mas\n5.-Salir");
       scanf("%i", &op1);

       switch(op1)
       {
       case 1:
        break;

       case 2:
        break;

       case 3:
        break;

       case 4:
        break;

       case 5:
        break;

        default:
       }
    }

    return 0;
}
