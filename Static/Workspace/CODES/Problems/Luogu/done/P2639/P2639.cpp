#include <cstdio>
#include <cstring>
#define mx2(a, b) (a > b ? a : b)
using namespace std;
int f[53000];
int main()
{
   int n, m;
   scanf("%d%d", &m, &n);
   int w, d;
   memset(f, 0x00, sizeof(f));
   f[0] = 0;
   while (n--)
   {
      scanf("%d", &w);
      d = w;
      for (int i = m; i >= w; --i)
      {
         f[i] = mx2(f[i], f[i - w] + d);
      }
   }
   int max = -1;
   for (int i = 0; i <= m; ++i)
   {
      max = mx2(f[i], max);
   }
   printf("%d", max);
   return 0;
}