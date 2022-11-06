#include <cstdio>
#include <cstring>
#define mi2(a, b) (a < b ? a : b)
#define mx2(a, b) (a > b ? a : b)
using namespace std;
long long f[5005];
long long t[5005];
long long c[5005];
int main()
{
   int n;
   int s;
   scanf("%d%d", &n, &s);
   for (int i = 1; i <= n; ++i)
   {
      scanf("%d%d", &t[i], &c[i]);
   }
   for (int i = 1; i <= n; ++i)
   {
      t[i] += t[i - 1];
   }
   for (int i = 1; i <= n; ++i)
   {
      c[i] += c[i - 1];
   }
   memset(f, 0x3f, sizeof f);
   f[0] = 0;
   for (int i = 1; i <= n; ++i)
   {
      for (int j = 0; j < i; ++j)
      {
         f[i] = mi2(f[i], f[j] + (c[i] - c[j]) * t[i] + s * (c[n] - c[j]));
      }
   }
   printf("%lld", f[n]);
}