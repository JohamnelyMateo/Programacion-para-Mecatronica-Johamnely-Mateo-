#include <stdio.h>
#include <stdlib.h>
void main (void)

{
    int matriz [5][5];
    int i, j;
    int SumaDP = 0;
    int SumaDS = 0;

    printf("Introduce los elementos de la matriz: \n");
    for (i = 0; i<5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("Elemnto en [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            if (i==j)
            {
                SumaDP += matriz[i][j];
            }
            if (i + j == 5-1)
            {
                SumaDS += matriz [i][j];
            }
        }
    }
    printf("\n Matriz 5x5: \n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n\n");
    }
    printf("\nSuma de la diagonal principal: %d\n", SumaDP);
    printf("\nSuma de la diagonal secundaria: %d\n", SumaDS);

    return 0;
}
