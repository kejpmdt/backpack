#include <cstdio>
#define mi2(a, b) (a < b ? a : b)
#define mx2(a, b) (a > b ? a : b)
#define MAXN 105
using namespace std;
int l[MAXN], r[MAXN];
int v[MAXN];
int f[MAXN][605];
int T;
void dps(int nw)
{
   static int x = 1;
   int t, u;
   scanf("%d%d", &t, &u);
   t <<= 1;
   if (u != 0)
   {
      for (int i = 1; i <= u; ++i)
      {
         f[nw][t + i * 5] = i;
      }
      for (int i = 1; i <= T; ++i)
      {
         f[nw][i] = mx2(f[nw][i], f[nw][i - 1]);
      }
   }
   else
   {
      l[nw] = ++x;
      r[nw] = ++x;
      dps(l[nw]);
      dps(r[nw]);
      for (int i = 1; i + t <= T; ++i)
      {
         for (int j = 0; j <= i; ++j)
         {
            f[nw][i + t] = mx2(f[nw][i + t], f[l[nw]][j] + f[r[nw]][i - j]);
         }
      }
      for (int i = 1; i <= T; ++i)
      {
         f[nw][i] = mx2(f[nw][i], f[nw][i - 1]);
      }
   }
}
int main()
{
   scanf("%d", &T);
   dps(1);
   printf("%d", f[1][T - 1]);
}