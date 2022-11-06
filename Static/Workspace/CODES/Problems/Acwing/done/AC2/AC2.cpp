#include <cstdio>
#include <cstring>
#define mx2(a, b) ((a) > (b) ? (a) : (b))
using namespace std;
int f[1005];
int main()
{
   int N, V;
   scanf("%d%d", &N, &V);
   int v, w;
   int i;
   for (i = 2; i <= V; ++i)
   {
      f[i] = 0x80000000;
   }
   while (N--)
   {
      scanf("%d%d", &v, &w);
      for (i = v; i <= V; ++i)
      {
         f[i] = mx2(f[i], f[i - v] + w);
      }
   }
   int ans = 0;
   for (i = 0; i <= V; ++i)
   {
      ans = mx2(ans, f[i]);
   }
   printf("%d", ans);
   return 0;
}
