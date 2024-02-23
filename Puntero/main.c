#include <stdio.h>
#include <stdlib.h>

int main()
{
    double *ptrd;
    int *num;
    int a[100];

    double d1 = 18.0;
    int int1 = 97;
    printf("\nValor de d1 = %lf",d1);
    ptrd = &d1; // &operador de distancia
    *ptrd = 125.5; // *Operador de in direccion

    printf("\nValor de d1 = %lf",d1);
     printf("\nValor de d1 = %lf",*ptrd);

      printf("\nDireccion de d1 = %p",&d1);
      //un puntero es un numero entero a 64 bits

       printf("\nDimencion de d1 : %d", sizeof(d1));
       printf("\nDimencion de a[100] : %d", sizeof(a));
       printf("\nDimencion de a[1] : %d", sizeof(*a));
       printf("\nDimencion de int : %d", sizeof(int1));
       return 0;

}
