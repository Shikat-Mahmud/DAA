#include <iostream>
using namespace std;
int main()
{
     int n;
     char c = 'a';
     cout << "enter number of nodes";
     cin >> n;
     int g[n][n];
     int stree[n][3];
     for (int i = 0; i < n; i++)
          stree[i][0] = stree[i][1] = stree[i][2] = -1;
     cout << "enter graph egdes 0 for no egde and weight for edge\n";
     for (int i = 0; i < n; i++)
     {
          for (int j = i; j < n; j++)
          {
               g[i][j] = 0;
               if (i != j)
               {
                    cout << "(" << ((char)(c + i)) << "," << (char)(c + j) << "):-";
                    cin >> g[i][j];
                    g[j][i] = g[i][j];
               }
          }
     }
     cout << "\t ";
     for (int i = 0; i < n; i++)
          cout << (char)(c + i) << "\t";
     for (int i = 0; i < n; i++)
     {
          cout << endl
               << (char)(c + i) << "\t ";
          for (int j = 0; j < n; j++)
          {
               if (g[i][j] != 0)
                    cout << "|" << g[i][j];
               else
                    cout << "|-";
               cout << "\t";
          }
     }
     // root node
     stree[0][0] = stree[0][1] = 0;
     stree[0][2] = 1;
     // making stree
     int counter = 0, i = 0;
     while (counter < n)
     {
          for (int k = 0; k < n; k++)
          {
               if (g[i][k] != 0)
               {
                    if (stree[k][0] == -1 && stree[k][2] != 1)
                    {
                         stree[k][0] = i;
                         stree[k][1] = g[i][k];
                    }
                    else
                    {
                         if (stree[k][1] > g[i][k] && stree[k][2] != 1)
                         {
                              stree[k][0] = i;
                              stree[k][1] = g[i][k];
                         }
                    }
               }
          }
          int temp = -1;
          for (int k = 0; k < n; k++)
          {
               if (stree[k][2] != 1 && stree[k][0] != -1)
               {
                    if (temp == -1)
                         temp = k;
                    else
                    {
                         if (stree[temp][1] > stree[k][1])
                              temp = k;
                    }
               }
          }
          i = temp;
          stree[i][2] = 1;
          counter++;
     }
     for (i = 0; i < n; i++)
          cout << endl
               << (char)(c + i) << ":-" << (char)(c + stree[i][0]) << "," << stree[i][1];
}

