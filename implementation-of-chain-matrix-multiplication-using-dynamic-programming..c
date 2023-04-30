#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void sel(int arr[5][5], int, int);
int n, i, j, s[10][10];

int main()
{
     int l, k, q;
     printf("Enter number of matrices\n");
     scanf("%d", &n);
     int p[n + 1], m[n + 1][n + 1];
     printf("\nEnter P array values\n");

     for (i = 0; i < n + 1; i++)
     {
          printf("p[%d] = ", i);
          scanf("%d", &p[i]);
     }
     for (i = 0; i < n + 1; i++)
     {
          for (j = 0; j < n + 1; j++)
          {
               s[i][j] = 0;
               m[i][j] = 0;
          }
     }
     for (l = 2; l < n + 1; l++)
     {
          for (i = 1; i < n - l + 2; i++)
          {
               j = i + l - 1;
               m[i][j] = 100000;
               for (k = i; k < j; k++)
               {
                    q = m[i][k] + m[k + 1][j] + ((p[i - 1]) * (p[k]) * (p[j]));
                    if (q < m[i][j])
                    {
                         m[i][j] = q;
                         s[i][j] = k;
                    }
               }
          }
     }
     printf("\n\nm Table\n\n");
     for (i = 1; i < n + 1; i++)
     {
          for (j = 1; j < n + 1; j++)
          {
               printf("%d\t", m[i][j]);
          }
          printf("\n");
     }
     printf("\n\n\ns Table\n\n");

     for (i = 1; i < n + 1; i++)
     {
          for (j = 1; j < n + 1; j++)
          {
               printf("%d\t", s[i][j]);
          }
          printf("\n");
     }
     printf("\n\nThe solution is   :    ");
     sel(s, 1, n);
     printf("\n\n");
     return 0;
}

void sel(int s1[5][5], int i, int j)
{
     int a, b;
     for (a = 0; i < n + 1; a++)
     {
          for (b = 0; b < n + 1; b++)
          {
               s1[a][b] = s[a][b];
          }
     }
     if (i == j)
     {
          printf("A%d", i);
          return;
     }
     else
     {
          printf(" ( ");
          sel(s1, i, s1[i][j]);
          sel(s1, (1 + s1[i][j]), j);
          printf(" ) ");
     }
}
