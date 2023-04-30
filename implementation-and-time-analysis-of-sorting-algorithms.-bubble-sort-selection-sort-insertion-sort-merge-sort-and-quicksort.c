#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 900

int main()
{
     int i, j, a[900], t, p, min;
     clock_t start, end;

     double cpu;

     /*  BUBBLE SORT  */

     for (i = 0; i < size; i++)
          a[i] = rand() % 100;
     start = clock();
     for (i = 0; i < size; i++)
     {
          for (j = 0; j < size; j++)
          {
               if (a[j + 1] < a[j])
               {
                    t = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = t;
               }
          }
     }
     end = clock();
     cpu = ((double)(end - start) / CLOCKS_PER_SEC);
     printf("\nBUBBLE SORT  ");
     printf("\nTime is  %lf \n", cpu);
     printf("Sorted data  \n");
     for (i = 0; i < size; i++)
          printf("%d ", a[i]);

     /*  SELECTION SORT  */

     for (i = 0; i < size; i++)
          a[i] = rand() % 100;
     start = clock();
     for (i = 0; i < (size - 1); i++)
     {
          min = i;
          for (j = i + 1; j < size; j++)
          {
               if (a[min] > a[j])
               {
                    min = j;
               }
          }
          if (min != i)
          {
               t = a[i];
               a[i] = a[min];
               a[min] = t;
          }
     }
     end = clock();
     printf("\nSELECTION SORT  ");
     cpu = ((double)(end - start) / CLOCKS_PER_SEC);
     printf("\nTime is %lf", cpu);
     printf("\nSorted data  \n");
     for (i = 0; i < size; i++)
          printf("%d ", a[i]);

     /*  INSERTION SORT  */

     for (i = 0; i < size; i++)
          a[i] = rand() % 100;
     start = clock();
     for (i = 1; i < size; i++)
     {
          p = a[i];
          j = i - 1;
          while (j >= 0 && a[j] > p)
          {
               a[j + 1] = a[j];
               j = j - 1;
          }
          a[j + 1] = p;
     }
     end = clock();
     printf("\nINSERTION SORT  ");
     cpu = ((double)(end - start) / CLOCKS_PER_SEC);
     printf("\nTime is %lf", cpu);

     printf("\nSorted data  \n");
     for (i = 0; i < size; i++)
          printf("%d ", a[i]);
     printf("\n");

     return 0;
}
