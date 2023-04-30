#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int size;
void max_heapify(int *, int);
void build_max(int *);
void heapsort(int *);
int heap_size;

void main()
{
     printf("Enter size of array\n");
     scanf("%d", &size);
     int a[size], i, j, p, k = size - 1;
     printf("Enter %d elements in array\n", size);
     for (i = 0; i < size; i++)
          scanf("%d", &a[i]);

     heapsort(a);
     printf("\n\n");
     printf("Sorted heap is\n");
     for (i = 0; i < size; i++)
          printf("%d  ", a[i]);

     printf("\n\n");
     int y = log2(size + 1) + 1, l = 0;
     for (j = 0; j <= log2(size + 1) + 1; j++)
     {
          printf("\n");
          for (p = y; p >= 0; p--)
               printf("  ");
          y--;
          for (i = 0; (i < pow(2, j) && l < size); i++)
          {
               printf("%d  ", a[k]);
               k--;
               l++;
          }
          printf("\n");
     }
}

void heapsort(int *b)
{
     int i, p;
     build_max(b);
     for (i = size; i >= 0; i--)
     {
          p = b[0];
          b[0] = b[i];
          b[i] = p;
          heap_size--;
          max_heapify(b, 0);
     }
}

void build_max(int *c)
{
     int i;
     heap_size = size;
     for (i = size / 2; i >= 0; i--)
     {
          max_heapify(c, i);
     }
}

void max_heapify(int *d, int a)
{
     int lt, rt, largest, p;
     lt = a * 2;
     rt = ((a * 2) + 1);
     if (lt <= heap_size && d[lt] > d[a])
          largest = lt;
     else
          largest = a;
     if (rt <= heap_size && d[rt] > d[largest])
          largest = rt;
     if (largest != a)
     {
          p = d[a];
          d[a] = d[largest];
          d[largest] = p;
          max_heapify(d, largest);
     }
}
