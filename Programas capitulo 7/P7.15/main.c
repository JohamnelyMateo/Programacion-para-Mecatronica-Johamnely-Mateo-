#include <stdio.h>
#include <ctype.h>
/* Decodifica.
El programa decodifica una cadena de caracteres compuesta por numeros y letras. */

void interpreta(char *);         /* Prototipo de funcion. */

void main(void)
{
    char cad[50];
    printf("\nIngrese la cadenade caracteres: ");
    gets(cad);
    interpreta(cad);
}
 void interpreta(char *cadena)
 /* Esta funcion se utiliza para decofificar la cadena de caracteres. */
 {
     int i = 0, j, k;
     while(cad[i] != '\0')
     {
         if (isalpha (cad[i]))   /* Se utiliza isalpha para observar si el caracter es una letra. */
         {
             k = cad[i -1] - 48;
             /* En la variable entera kse almacena el ascii del n�mero �convertido
             en caracter� que nos interesa, menos 48 que corresponde al ascii  deld�gito 0. */
             for (j = 0; j  < k; j++)
                putchar(cad[i]);
         }
         i++;
     }
 }
