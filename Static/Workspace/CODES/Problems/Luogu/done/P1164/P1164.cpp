#include <cstdio>
using namespace std;
int f[10005];
int main()
{
   int i;
   int m, n;
   int a;
   f[0] = 1;
   scanf("%d%d", &n, &m);
   while (n--)
   {
      scanf("%d", &a);
      for (i = m; i >= a; --i)
      {
         f[i] += f[i - a];
      }
   }
   printf("%d\n", f[m]);
   return 0;
}
