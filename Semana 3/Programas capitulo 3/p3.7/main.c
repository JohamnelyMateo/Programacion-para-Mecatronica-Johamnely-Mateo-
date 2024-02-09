#include <stdio.h>
#include <stdlib.h>

 /* Lanzamiento de martillo.
 El programa, al recibir como dato N lanzamientos de martillo, calcula el promedio
 ➥de los lanzamientos de la atleta cubana.
I, N: variables de tipo entero.
LAN, SLA: variables de tipo real. */

void main(void)
{
    int I, N;
    float LAN, SLA = 0;
    do
    {
       printf("\nIngrese numero entre 1 y 10");
        printf("Ingrese el numero de lanzamiento:\t");
        scanf("%d", &N);
    }
    while (N < 1 || N > 11 );
    /* Se utiliza la estructura do-while para verificar que el correcto. */
    for (I = 1; I<=N; I++)
    {
        printf("\nIngrese el lanzamiento %d/%d: ", I,N);
        scanf("%f", &LAN);
        SLA = SLA + LAN;
    }
    SLA = SLA / N;
    printf("\nEl promedio de lanzamiento es: %.2f", SLA);
}
