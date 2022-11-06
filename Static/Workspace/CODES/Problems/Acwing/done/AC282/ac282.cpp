#include <cstdio>
#include <cstring>
#define mi2(a, b) ((a) < (b) ? (a) : (b))
using namespace std;
int f[305][305];
int d[305];
int main()
{
   int n;
   memset(f, 0x3f, sizeof f);
   scanf("%d", &n);
   int i, j, k;
   for (i = 1; i <= n; ++i)
   {
      scanf("%d", &d[i]);
      f[i][0] = 0;
      d[i] += d[i - 1];
   }
   for (j = 0; j <= n; ++j)
   {
      for (i = 1; i + j <= n; ++i)
      {
         for (k = 0; k <= j; ++k)
         {
            f[i][j] = mi2(f[i][j], f[i][k] + f[i + k + 1][j - k - 1] + d[i + j] - d[i - 1]);
         }
      }
   }
   printf("%d", f[1][n - 1]);
   return 0;
}