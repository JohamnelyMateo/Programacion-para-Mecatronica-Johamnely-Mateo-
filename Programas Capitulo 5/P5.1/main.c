#include <stdio.h>
#include <stdlib.h>
/* Cuenta-números.
 El programa, al recibir como datos un arreglo unidimensional de tipo
 ➥entero y un número entero, determina cuántas veces se encuentra el
 ➥número en el arreglo. */
void main(void)
{
    int I, NUM, CUE = 0;
    int ARRE [100];                /* Declaracion del arreglo */
    for (I=0; I<100; I++)
    {
        printf("Ingrese el elemento %d del arreglo: ", I+1);
        scanf("%d", &ARRE[I]);    /* Lectura -Asignacion - del arreglo */
    }
    printf("\n\nIngresa el elemento %d del arreglo: ", I+1);
    scanf("%d", &NUM);
    for (I=0; I<100; I++)
        if (ARRE[I]== NUM)      /* Comparacion del numero con los elementos del arreglo*/
        CUE++;
    printf("\n\nEl %d se encuentra %d veces en el arreglo", NUM, CUE);
}
