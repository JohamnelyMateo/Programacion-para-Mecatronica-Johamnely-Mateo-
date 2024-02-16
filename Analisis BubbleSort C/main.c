/* BubbleSort C */


#include <stdio.h>
#include <time.h> //Esta es una libreria diferente a la que ya hemos usado,  esta tiene funciones de tiempo.

#define ARRAY_SIZE 10 //Esto se utiliza para especificar el valor de un arreglo, aqui es 10

int i; //Aqui se muestra a i como una variable de tipo entero.
int change;//Esta variable de tipo entero tiene como funcion especificar cambios.
int n; //Aqui muestra a n como una variable de tipo entero
int a [ARRAY_SIZE]; //Es el arreglo donde estan los numeros aleatorios
int buf; //Es una variable de tipo entero temporal, esta va intercambiando valores mientras se va ordenando.
time_t seed;//su funcion es empezar a generar los numeros aleatorios


int main(int argc, char*argv[])
{
    seed = 0; //Empieza el proceso de conteo de las semillas desde 0.
    srand(time(&seed));//Tiempo actual.
    n = sizeof(a)/sizeof(*a);//aqui se muestra el tamaño del arreglo a, donde se ve una division de un arreglo completo y uno individual.
    for(i = 0; i <= n-1;i++) //Empieza un bucle con los numeros aleatorios.
    {
        a[i]= rand()% 1000; //Valor nuevo
    }
    for(i = 0; i<= n-1;i++)
    {
        printf("Element a[%d]: %dVn", i, a[i]); // Se imprimira el contenido del arreglo antes de ser ordenados.

    }
    change = 1; //aqui se ordena los numeros aleatorios.
    while (change == 1) //Aqui se inicia una repeticion hasta change = 1 para ordenar los numeros con bubblesort.
    {
        change = 0;
        for(i = 0; i <= n-2; i++)
        {
            if (a[i]> a[i+1])
            {
              buf = a[i];
              a[i]= a[i+1];
              a[i+1]= buf;
              change= 1;
            }
        }
    }
    printf("\n--------------------\n"); //Esto imprime una separacion de los numeros desordenados de los ordenados
    for (i= 0; i<= n-1; i++) //Aqui se ordena de menor a mayor.
    {
        printf("Element a[%d]: %d\n",i,a[i]); //Se imprime en pantalla los elementos ya ordenados.
    }
    return 0; //Finaliza el programa.
}
