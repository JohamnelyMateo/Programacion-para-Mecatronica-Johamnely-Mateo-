#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x = 0.0;
    double b = 0.0;
    int ciclos = 0;

    printf("Calculo raiz cuadrada!\n");
    printf("Ingrese el numero: ");
    scanf("%lf", &x);

    b = x;
    while(!(b == (x/b)))
    {
        printf("\nCiclos para calculo: %d",ciclos);
        printf("\nRaiz cuadrada de %lf es: %lf",x,b);
        b = 0.5 *((x/b)+ b);
        ciclos++;
        if (ciclos>=20)
        {
            break;
        }
    }
   return 0;
}

