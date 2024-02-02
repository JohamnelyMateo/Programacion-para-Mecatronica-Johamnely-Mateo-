#include <stdio.h>
#include <stdlib.h>

/* Par, impar o nulo.
NUM: variable de tipo entero. */

void main(void)
{
    int NUM;
    printf("Ingrese el numero: ");
    scanf("%d", &NUM);
    if (NUM == 0)
        printf("\nPar");
    else
        printf("\nImpar");
}
