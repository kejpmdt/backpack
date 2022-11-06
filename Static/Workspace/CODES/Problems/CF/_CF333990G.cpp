#include <cstdio>
using namespace std;
int ans[2000005];
int main()
{
   int nw = 0;
   for (int i = 1; nw <= 1000000; ++i)
   {
      nw += i;
      ans[nw] = i;
   }
   int u;
   while (nw > 0)
   {
      if (ans[nw] != 0)
      {
         u = ans[nw--];
      }
      else
         ans[nw--] = ++u;
   }
   int n;
   scanf("%d", &n);
   int x;
   while (n--)
   {
      scanf("%d", &x);
      printf("%d\n", ans[x]);
   }
}