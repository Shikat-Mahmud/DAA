#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fact(int x)
{
     double f = x;
     if (x != 1)
          f *= fact(x - 1);
     else
          return 1;
     return f;
}

void main()
{
     int i, n;
     double a, fa = 1;
     clock_t end, start;
     double cpu;
     printf("\nEnter a number to find factorial    ");
     scanf("%d", &n);
     start = clock();

     for (i = n; i > 0; i--)
     {
          fa *= i;
     }
     end = clock();
     cpu = ((double)(end - start) / CLOCKS_PER_SEC);
     printf("\nTime for iterative is %lf", cpu);
     printf("\nFactorial of %d is %lf\n", n, fa);
     start = clock();
     a = fact(n);
     end = clock();
     cpu = ((double)(end - start) / CLOCKS_PER_SEC);
     printf("\nTime for recursive is %lf", cpu);
     printf("\nFactorial of %d is %lf", n, a);
     printf("\n");
}

