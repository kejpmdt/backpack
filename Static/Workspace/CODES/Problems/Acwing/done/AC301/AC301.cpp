#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 300010;
typedef long long LL;
int n, s;
LL c[N], t[N];
LL f[N];
int q[N];
int main()
{
   scanf("%d%d", &n, &s);
   for (int i = 1; i <= n; ++i)
   {
      scanf("%d%d", &t[i], &c[i]);
      t[i] += t[i - 1];
      c[i] += c[i - 1];
   }
   int hh = 0, tt = 0;
   q[0] = 0;
   for (int i = 1; i <= n; ++i)
   {
      while (hh < tt && (f[q[hh + 1]] - f[q[hh]]) <= (t[i] + s) * (c[q[hh + 1]] - c[q[hh]]))
      {
         ++hh;
      }
      f[i] = f[q[hh]] - (t[i] + s) * c[q[hh]] + t[i] * c[i] + s * c[n];
      while (hh < tt && (f[q[tt]] - f[q[tt - 1]]) * (c[i] - c[q[tt]]) >= (f[i] - f[q[tt]]) * (c[q[tt]] - c[q[tt - 1]]))
      {
         --tt;
      }
      q[++tt] = i;
   }
   printf("%lld\n", f[n]);
   return 0;
}