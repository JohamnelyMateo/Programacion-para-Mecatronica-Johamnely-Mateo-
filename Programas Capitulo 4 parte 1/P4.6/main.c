#include <stdio.h>
#include <stdlib.h>
/* Prueba de parametros por referencias. */

void f1(int *);
 /* Prototipo de función. El parámetro es de tipo entero y por referencia
 —observa el uso del operador de indirección. */
 void main(void)
{
    int I, K = 4;
    for (I = 1; I <= 3; I++)
{
        printf("\n\nValor de K antes de llamar a la funcion: %d", ++K);
        printf("\nValor de K despues de llamar a la funcion: %d", f1(&K));
         /* Llamada a la función ff11. Se pasa la dirección de la variable K,
 ➥por medio del operador de dirección: &.  */
}
}
void f1(int *R)
/* La funcion f1 recibe un parametro por referencia. Cada vez que el
parametro se utiliza en la funcion debe ir precedido por el operador de
indireccion. */
{
    *R += *R;
}
