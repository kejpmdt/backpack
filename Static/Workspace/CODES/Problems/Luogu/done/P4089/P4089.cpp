#include <iostream>
#define MAXN 1000006
using namespace std;
int f[MAXN];
long long t[MAXN];
int main()
{
   int n;
   cin >> n;
   for (int i = 1; i <= n; ++i)
   {
      cin >> f[i];
   }
   int nw;
   int u;
   int ans = 0;
   for (int i = 1; i <= n; ++i)
   {
      t[i] = i * 10000000 + 1;
      nw = i;
      while (f[nw])
      {
         if (t[f[nw]] / 10000000 == i)
         {
            ans += t[nw] % 10000000 - t[f[nw]] % 10000000 + 1;
            break;
         }
         t[f[nw]] = t[nw] + 1;
         nw = f[nw];
      }
      nw = f[i];
      u = i;
      while (nw)
      {
         f[u] = 0;
         u = nw;
         nw = f[nw];
      }
   }
   cout << ans;
   return 0;
}