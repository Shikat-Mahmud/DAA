#include <iostream>
using namespace std;
class edge
{
public:
     int w = 0, e1 = 0, e2 = 0;
};
int main()
{
     int n;
     char c = 'a';
     int k = 0;
     cout << "enter number of nodes";
     cin >> n;
     int g[n][n];
     int stree[n][n], snode[n];
     edge e[n * n];
     // defalut values for tree
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
                    if (g[i][j] != 0)
                    {
                         e[k].w = g[i][j];
                         e[k].e1 = i;
                         e[k++].e2 = j;
                    }
               }
          }
     }
     // printing graph table
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
     // sorting
     for (int i = 0; i < k; i++)
     {
          for (int j = k - 1; j > i; j--)
          {
               if (e[i].w > e[j].w)
               {
                    edge tem;
                    tem = e[i];
                    e[i] = e[j];
                    e[j] = tem;
               }
          }
     }
     // printing sorted edges
     for (int i = 0; i < k; i++)
          cout << endl
               << e[i].w << "(" << (char)(c + e[i].e1) << "," << (char)(c + e[i].e2) << ")";
     // make graph-tree table;
     for (int i = 0; i < n; i++)
     {
          snode[i] = -1;
          for (int j = 0; j < n; j++)
               stree[i][j] = -1;
     }
     int gp = 0;
     for (int i = 0; i < k; i++)
     {
          if ((snode[e[i].e1] == -1 && snode[e[i].e2] == -1))
          {
               stree[e[i].e1][e[i].e2] = stree[e[i].e2][e[i].e1] = e[i].w;
               snode[e[i].e1] = snode[e[i].e2] = gp;
               gp++;
          }
          else if (stree[e[i].e1][e[i].e2] == -1 && (snode[e[i].e1] != snode[e[i].e2]))
          {
               stree[e[i].e1][e[i].e2] = stree[e[i].e2][e[i].e1] = e[i].w;
               if (snode[e[i].e1] != -1 && snode[e[i].e2] == -1)
               {
                    snode[e[i].e2] = snode[e[i].e1];
               }
               else if (snode[e[i].e2] != -1 && snode[e[i].e1] == -1)
               {
                    snode[e[i].e1] = snode[e[i].e2];
               }
               else
               {
                    int temp = snode[e[i].e2];
                    for (int l = 0; l < n; l++)
                    {
                         if (snode[l] == temp)
                         {
                              snode[l] = snode[e[i].e1];
                         }
                    }
               }
          }
     }
     cout << endl
          << "\t ";
     for (int i = 0; i < n; i++)
          cout << (char)(c + i) << "\t ";
     for (int i = 0; i < n; i++)
     {
          cout << endl
               << (char)(c + i) << "\t";
          for (int j = 0; j < n; j++)
          {
               if (stree[i][j] != -1)
                    cout << "|" << stree[i][j];
               else
                    cout << "|-";
               cout << "\t";
          }
     }
}

