#include <iostream>
#include <cstdio>
using namespace std;
int num[100005];
int res;
int main()
{
   int n, m;
   cin >> n >> m;
   res = n;
   int u;
   for (int i = 1; i <= m; ++i)
   {
      cin >> u;
      ++num[u];
      if (num[u] == 1)
      {
         --res;
      }
      if (res == 0)
      {
         cout << 1;
         res = n;
         for (int j = 1; j <= n; ++j)
         {
            num[j]--;
            if (num[j])
               --res;
         }
      }
      else
      {
         cout << 0;
      }
   }
}
