#include <stdio.h>
void lcs(int arr[][10], char ar[], int, int);
int l, k;
void main()
{
     char s1[10], s2[10];
     int i, j;
     printf("\nEnter the strings\nX = ");
     s1[0] = 0;
     char ch = getchar();
     while (ch != '\n')
     {
          s1[++l] = ch;
          ch = getchar();
     }
     printf("Y = ");
     s2[0] = 0;
     char c1 = getchar();
     while (c1 != '\n')
     {
          s2[++k] = c1;
          c1 = getchar();
     }

     int c[l + 1][k + 1], b[l + 1][k + 1];
     for (i = 0; i < l + 1; i++)
     {
          for (j = 0; j < k + 1; j++)
          {
               b[i][j] = 0;
               c[i][j] = 0;
          }
     }
     // 1=diagonal  2=up     3=left
     for (i = 1; i < l + 1; i++)
     {
          for (j = 1; j < k + 1; j++)
          {
               if (s1[i] == s2[j])
               {
                    c[i][j] = c[i - 1][j - 1] + 1;
                    b[i][j] = 1; // diagonal
               }
               else if (c[i - 1][j] >= c[i][j - 1])
               {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = 2; // up
               }
               else
               {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = 3; // left
               }
          }
     }

     printf("\n\n\t");
     for (i = 1; i < k + 1; i++)
     {
          printf("\t %c", s2[i]);
     }
     printf("\n");
     for (i = 0; i < l + 1; i++)
     {
          printf("%c\t", s1[i]);
          for (j = 0; j < k + 1; j++)
          {
               printf("%d(%d)\t", c[i][j], b[i][j]);
          }
          printf("\n");
     }
     printf("\n\n");
     printf("Longest common substring of X and Y is    ");
     lcs(b, s1, l, k);
     printf("\n\n");
}
void lcs(int arr[l + 1][k + 1], char ar[l + 1], int a, int p)
{
     if (a == 0 || p == 0)
          return;
     if (arr[a][p] == 1)
     {
          lcs(arr, ar, a - 1, p - 1);
          printf("%c ", ar[a]);
     }
     else if (arr[a][p] == 2)
     {
          lcs(arr, ar, a - 1, p);
     }
     else if (arr[a][p] == 3)
     {
          lcs(arr, ar, a, p - 1);
     }
}

