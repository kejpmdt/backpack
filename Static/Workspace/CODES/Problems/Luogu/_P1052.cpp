#include <cstdio>
#define mi2(a, b) ((a) < (b) ? (a) : (b))
using namespace std;
int p[105];
int f[105];
int main()
{
   int s, t, m;
   int l;
   scanf("%d", &l);
   scanf("%d%d%d", &s, &t, &m);
   int i, j;
   for (i = 1; i <= m; ++i)
   {
      scanf("%d", &p[i]);
   }
   p[++m] = l;
   for (i = 1; i <= m; ++i)
   {
      f[i] = 0x3fffffff;
      for (j = 0; j < i; ++j)
      {
         if (p[i] - p[j] > t)
         {
            continue;
         }
         if (p[i] - p[j] < s)
         {
            break;
         }
         f[i] = mi2(f[i], f[j] + 1);
      }
   }
   printf("%d", f[m]);
   return 0;
}
