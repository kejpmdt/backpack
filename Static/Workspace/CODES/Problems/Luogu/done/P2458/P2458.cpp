#include <cstdio>
#define mi2(a, b) (a < b ? a : b)
#define mx2(a, b) (a > b ? a : b)
#define MAXN 1505
#define MAXM 3005
using namespace std;
int fst[MAXN], nt[MAXN];
int cost[MAXN];
int f[1505][3];
void dps(int nw)
{
   f[nw][0] = f[nw][2] = 0;
   f[nw][1] = cost[nw];
   int i;
   int delta = 0x7fffffff;
   for (i = fst[nw]; i; i = nt[i])
   {
      dps(i);
      if (f[i][1] <= f[i][2])
      {
         delta = 0;
      }
      else
      {
         delta = mi2(delta, f[i][1] - f[i][2]);
      }
      f[nw][0] += mi2(f[i][1], f[i][2]);
      f[nw][1] += mi2(f[i][0], mi2(f[i][1], f[i][2]));
      f[nw][2] += mi2(f[i][1], f[i][2]);
   }
   f[nw][2] += delta;
   return;
}
template <typename T>
void read(T &ans)
{
   ans = 0;
   char us = getchar();
   bool f = false;
   while (us < 48 || us > 57)
   {
      f |= (us == 45);
      us = getchar();
   }
   while (us > 47 && us < 58)
   {
      ans = (ans << 1) + (ans << 3) + (us ^ 48);
      us = getchar();
   }
   ans *= f ? -1 : 1;
   return;
}
template <typename T, typename... O>
void read(T &x, O &...oth)
{
   read(x);
   read(oth...);
}
int fa[MAXN];
int main()
{
   int n;
   read(n);
   int m;
   int u;
   int x;
   for (int i = 1; i <= n; ++i)
   {
      read(x);
      read(cost[x], m);
      while (m--)
      {
         read(u);
         fa[u] = x;
         nt[u] = fst[x];
         fst[x] = u;
      }
   }
   u = 1;
   while (fa[u])
   {
      u = fa[u];
   }
   dps(u);
   printf("%d", mi2(f[u][1], f[u][2]));
   return 0;
}