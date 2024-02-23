#include <stdio.h>
#include <stdlib.h>
 /* Mayor divisor.
El programa, al recibir como dato un número entero positivo, calcula
 ➥su mayor divisor. */
int mad(int);      /* Prototipo de funcion. */
void main(void)
{
    int NUM, RES;
    printf("\nIngresa el numero: ");
    scanf("%d", &NUM);
    RES = mad(NUM);
    printf("\nEl mayor divisor de %d es: %d", NUM, RES);

}
int mad(int N1)
/* Esta funcion clacula el mayor divisor del numero N1. */
{
   int I = (N1/2);
    /* II se inicializa con el máximo valor posible que puede ser divisor
 ➥de N1. */
 while (N1 % I)
 /* El ciclo se mantiene activo mientras ((NN11  %%  II)) sea distinto de cero.
 ➥Cuando el resultado sea 0, se detiene, ya que se habrá encontrado
 ➥el mayor divisor de NN11. */
 I --;
 return I;
}
