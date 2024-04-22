#include <stdio.h>
#include <stdlib.h>

/***********************************************************/
/*           Programacion para mecatronicos                */
/*  Nombre:    Johamnely Mateo Mosquea                     */
/*  Matricula: 2023-1530                                   */
/*  Seccion:   Viernes(Ma�ana)                             */
/*  Practica:  Proyecto final                              */
/*  Fecha:     21/04/2024                                  */
/***********************************************************/

/* Programa costo viaje.
Este programa permite gestionar los parametros y calcular el costo de viaje de un vehiculo*/


/* Estructura para los parametros fijos del vehiculo, define una estructura que contiene
los parametros fijos del vehiculo*/

struct ParametrosVehiculo
{
    float costo_vehiculo;        //2,000,000
    int tiempo_uso;             // (Se define como un entero a�os) 5 a�os
    float depreciacion;        //700,000
    float devaluacion_total;  // (costo vehiculo - depreciacion) 1,300,000
    float km_promedio_anual;  // 20,000
    float min_consumo;        // 8L/100KM
    float max_consumo;        //16L/KM
    float mantenimiento_mensual; //6200
    float seguro_mensual;       // 2000
    float costo_gomas_anual;   // 26,000
};
/* Funcion Leer parametros: lee los parametros del vehiculo desde un archivo de texto y los
alamacena en la estructura ParametrosVehiculo. Si el archino no existe, establece valores predeterminados */
void leerParametros(struct ParametrosVehiculo *parametros)
{
    FILE *archivo = fopen("parametros_vehiculo.txt", "r"); // La funcion fopen esta abriendo el archivo en modo lectura(r).
    if (archivo != NULL) // Si fopen devuelve un puntero valido al archivo , significa que se abrio correctamente . En este caso, la condidcion archivo != NULL sera verdadera, lo que significa que el archivo se abrio con exito
    {
        fscanf(archivo, "%f %d %f %f %f %f %f %f %f %f",
               &parametros->costo_vehiculo, &parametros->tiempo_uso,
               &parametros->depreciacion, &parametros->devaluacion_total, // Leer devaluaci�n total
               &parametros->km_promedio_anual, &parametros->min_consumo,
               &parametros->max_consumo, &parametros->mantenimiento_mensual,
               &parametros->seguro_mensual, &parametros->costo_gomas_anual);
        fclose(archivo); // Esta parte lee los valores de los parametros del vehiculo del archivo "parametros_vehiculo.txt" y los asigna a las variables correspondientes en la estructura, luego de que se completen las operaciones de lectura, se cierra el archivo.
    }
    else
    {
        // Valores predeterminados si el archivo no existe
        parametros->costo_vehiculo = 2000000.00;
        parametros->tiempo_uso = 5;
        parametros->depreciacion = 700000.00;
        parametros->devaluacion_total = 1300000.00;
        parametros->km_promedio_anual = 20000.00;
        parametros->min_consumo = 8.0;
        parametros->max_consumo = 16.0;
        parametros->mantenimiento_mensual = 6200.00;
        parametros->seguro_mensual = 2000.00;
        parametros->costo_gomas_anual = 26000.00;
    }
}
//Funcion escribirparametros: escribe los parametros del vehiculo en un archivo de texto.
 void escribirParametros(const struct ParametrosVehiculo *parametros)
{
    FILE *archivo = fopen("parametros_vehiculo.txt", "w"); //fopen se utiliza para abrir un archivo en modo escritura(w)
    if (archivo != NULL) //Esta estructura condicional verifica si la operacion de apertura del archivo fue exitosa.
    {
        fprintf(archivo, "%.2f %d %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f",  // Esta linea utiliza la funcion fprintf para escribir los parametros del vehiculo en el archivo abierto.
                parametros->costo_vehiculo, parametros->tiempo_uso,
                parametros->depreciacion, parametros->devaluacion_total,
                parametros->km_promedio_anual, parametros->min_consumo,
                parametros->max_consumo, parametros->mantenimiento_mensual,
                parametros->seguro_mensual, parametros->costo_gomas_anual);
        fclose(archivo); //D espues de escribir los datos en el archivo, se cierra el archivo utilizando la funcion fclose.

    }
    else
    {
        printf("No se pudo abrir el archivo de par�metros del veh�culo.\n"); // Si no se puede abrir el archivo, se imprime un mensaje de error en la consola.
        exit(1);
    }
}
// Funcion modificar parametros: Permite al usuario modificar los parametros del vehiculo y luego guarda los nuevos valores en el archivo.
void modificarParametros(struct ParametrosVehiculo *parametros)
{
    printf("\nModificando par�metros del veh�culo...\n");
    printf("Introduce el nuevo costo del veh�culo: ");
    scanf("%f", &parametros->costo_vehiculo);
    printf("Introduce el nuevo tiempo de uso del veh�culo: ");
    scanf("%d", &parametros->tiempo_uso);
    printf("Introduce la nueva depreciaci�n despu�s de %d a�os: ", parametros->tiempo_uso);
    scanf("%f", &parametros->depreciacion);
    printf("Introduce la nueva devaluaci�n total: "); // Nueva entrada para la devaluaci�n total
    scanf("%f", &parametros->devaluacion_total);
    printf("Introduce el nuevo kilometraje promedio anual: ");
    scanf("%f", &parametros->km_promedio_anual);
    printf("Introduce el nuevo m�nimo de consumo (L/100km): ");
    scanf("%f", &parametros->min_consumo);
    printf("Introduce el nuevo m�ximo de consumo (L/100km): ");
    scanf("%f", &parametros->max_consumo);
    printf("Introduce el nuevo mantenimiento mensual: ");
    scanf("%f", &parametros->mantenimiento_mensual);
    printf("Introduce el nuevo seguro mensual: ");
    scanf("%f", &parametros->seguro_mensual);
    printf("Introduce el nuevo costo anual de gomas: ");
    scanf("%f", &parametros->costo_gomas_anual);
    // Escribir los nuevos par�metros en el archivo
    escribirParametros(parametros);
    printf("�Par�metros modificados y guardados correctamente!\n");
}
/*Funcion calcularCostoViaje: Calcula y genera una tabla de costos pra diferentes niveles de consumo de combustible durante un viaje, considerando factores como
el costo del vehiculo por Km, el costo por Km por galon de combustible, y el costo total del viaje. Ademas ofrece la opcion de guardar esta tabla en un archivo*/
void calcularCostoViaje(const struct ParametrosVehiculo *parametros)
{
    float km_recorrer;
    float costo_galon;
    printf("\nIntroduce los kil�metros a recorrer en el viaje: ");
    scanf("%f", &km_recorrer);
    printf("Introduce el costo del gal�n de gasolina: ");
    scanf("%f", &costo_galon);

    // Generar la tabla de c�lculos para diferentes niveles de consumo de combustible(de min_consumo a max_consumo).
    printf("\n|-----------------------------------------------------------------------------|\n");
    printf("| Consumo (L/100km) | Costo veh�culo/km | Costo km/gal�n | Costo total viaje  |\n");
    printf("|-----------------------------------------------------------------------------|\n");
    for (float consumo = parametros->min_consumo; consumo <= parametros->max_consumo; consumo += 1.0)
    {
        // C�lculo del costo del veh�culo por kil�metro
        float costo_vehiculo_km = (((parametros->mantenimiento_mensual * 12 * parametros->tiempo_uso) +
                                    (parametros->seguro_mensual * 12 * parametros->tiempo_uso) +
                                    (parametros->costo_gomas_anual * parametros->tiempo_uso) +
                                    parametros->devaluacion_total) /
                                    (parametros->km_promedio_anual * parametros->tiempo_uso));

        // Conversi�n de litros a galones
        float galones = consumo / 3.78541; // 1 gal�n = 3.78541 litros

        // C�lculo del costo del kil�metro por gal�n durante el viaje
        float costo_km_galon = (galones * costo_galon) / 100;

        // C�lculo del costo total del viaje
        float costo_total_viaje = costo_km_galon * km_recorrer;

        printf("|      %.1f L/100km    |     %.2f         |      %.2f        |       %.2f  |\n",
               consumo, costo_vehiculo_km, costo_km_galon, costo_total_viaje);
    }
    printf("|------------------------------------------------------------------------------|\n");

    // Preguntar si desea guardar la tabla en un archivo
    int opcion_guardar;
    printf("\n�Desea guardar la tabla en un archivo? (0 = No, 1 = S�): ");
    scanf("%d", &opcion_guardar);
    if (opcion_guardar == 1)
    {
        FILE *archivo = fopen("informe_total_proyecto_final.txt", "w");
        if (archivo != NULL)
        {
            fprintf(archivo, "|----------------------------------------------------------------------------|\n");
            fprintf(archivo, "| Consumo (L/100km) | Costo veh�culo/km | Costo km/gal�n | Costo total viaje |\n");
            fprintf(archivo, "|----------------------------------------------------------------------------|\n");
            for (float consumo = parametros->min_consumo; consumo <= parametros->max_consumo; consumo += 1.0)
            {
                // C�lculo del costo del veh�culo por kil�metro
                float costo_vehiculo_km = (((parametros->mantenimiento_mensual * 12 * parametros->tiempo_uso) +
                                            (parametros->seguro_mensual * 12 * parametros->tiempo_uso) +
                                            (parametros->costo_gomas_anual * parametros->tiempo_uso) +
                                            parametros->devaluacion_total) /
                                            (parametros->km_promedio_anual * parametros->tiempo_uso));

                // Conversi�n de litros a galones
                float galones = consumo / 3.78541; // 1 gal�n = 3.78541 litros

                // C�lculo del costo del kil�metro por gal�n durante el viaje
                float costo_km_galon = (galones * costo_galon) / 100;

                // C�lculo del costo total del viaje
                float costo_total_viaje = costo_km_galon * km_recorrer;

                fprintf(archivo, "|      %.1f L/100km   |     %.2f         |      %.2f        |       %.2f     |\n",
                        consumo, costo_vehiculo_km, costo_km_galon, costo_total_viaje);
            }
            fprintf(archivo, "|-----------------------------------------------------------------------|\n");
            fclose(archivo);
            printf("\n�Tabla guardada exitosamente en el archivo 'informe_total_proyecto_final.txt'!\n");
        }
        else
        {
            printf("\n�Tabla no guardada!\n");
        }
    }
    else
    {
        printf("\n�Tabla no guardada!\n");
    }
}
/*Funcion main: es la funcion principal del programa que contiene un bucle que muestra un menu de opciones al usuario,
como ver los parametros del vehiculo, modificarlos, calcular el costo del viaje y salir del programa. El bucle continuara ejecutandose hasta que el usurio elija salir. */
int main()
{
    struct ParametrosVehiculo parametros;
    leerParametros(&parametros);

    int opcion;
    do
    {
        printf("\nMen�:\n");
        printf("1. Imprimir (ver) parametros del vehiculo\n");
        printf("2. Modificar parametros del vehiculo\n");
        printf("3. Calcular costo del viaje y generar tabla\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("\nPar�metros del veh�culo:\n");
            printf("Costo del veh�culo: %.2f\n", parametros.costo_vehiculo);
            printf("Tiempo de uso del veh�culo: %d a�os\n", parametros.tiempo_uso);
            printf("Depreciaci�n despu�s de %d a�os: %.2f\n", parametros.tiempo_uso, parametros.depreciacion);
            printf("Devaluaci�n total: %.2f\n", parametros.devaluacion_total); // Imprimir devaluaci�n total
            printf("Kilometraje promedio anual: %.2f\n", parametros.km_promedio_anual);
            printf("M�nimo de consumo (L/100km): %.2f\n", parametros.min_consumo);
            printf("M�ximo de consumo (L/100km): %.2f\n", parametros.max_consumo);
            printf("Mantenimiento mensual: %.2f\n", parametros.mantenimiento_mensual);
            printf("Seguro mensual: %.2f\n", parametros.seguro_mensual);
            printf("Costo anual de gomas: %.2f\n", parametros.costo_gomas_anual);
            break;
        case 2:
            modificarParametros(&parametros);
            break;
        case 3:
            calcularCostoViaje(&parametros);
            break;
        case 4:
            printf("\n�Hasta luego!\n");
            break;
        default:
            printf("\nOpci�n no v�lida. Por favor, seleccione una opci�n v�lida.\n");
        }
    } while (opcion != 4);

    return 0;
}



