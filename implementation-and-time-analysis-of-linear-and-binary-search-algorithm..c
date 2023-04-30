#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 500

void main()
{
     int e, a[500], i, c = 0;
     clock_t end, start;
     double cpu;
     printf("Enter element to search:   ");
     scanf("%d", &e);
     printf("\n\n");
     for (i = 0; i < 500; i++)
     {
          a[i] = rand() % 100;
     }
     for (i = 0; i < 500; i++)
     {
          printf("%d ", a[i]);
     }
     printf("\n\nThe found elements are: \n");
     start = clock();
     for (i = 0; i < 500; i++)
     {
          if (a[i] == e)
          {
               printf("%d ", a[i]);
               c++;
          }
     }

     end = clock();
     cpu = ((double)(end = start) / CLOCKS_PER_SEC);
     printf("\n\nThe number of elements found are: %d ", c);
     printf("\n\nThe time taken is: %lf\n\n", cpu);
}
