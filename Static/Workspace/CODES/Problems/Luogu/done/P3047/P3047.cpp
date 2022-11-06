#include <cstdio>
using namespace std;
#define MAXN 100005
#define MAXM 200005
int fst[MAXN], nt[MAXM], to[MAXM];
void addline(int a, int b)
{
   static int i;
   to[++i] = b, nt[i] = fst[a], fst[a] = i;
   to[++i] = a, nt[i] = fst[b], fst[b] = i;
}
int f[MAXN][30];
int n, k;
void dfs1(int nw, int fa)
{
   if (to[fst[nw]] == fa)
   {
      fst[nw] = nt[fst[nw]];
   }
   int i, j;
   for (i = fst[nw]; i; i = nt[i])
   {
      if (to[nt[i]] == fa)
      {
         nt[i] = nt[nt[i]];
      }
      dfs1(to[i], nw);
      for (j = 0; j + 1 <= 25; ++j)
      {
         f[nw][j + 1] += f[to[i]][j];
      }
   }
}
void dfs2(int nw)
{
   int i, j;
   for (i = fst[nw]; i; i = nt[i])
   {
      for (j = 24; j >= 0; --j)
      {
         if (j >= 1)
            f[to[i]][j + 1] -= f[to[i]][j - 1];
         f[to[i]][j + 1] += f[nw][j];
      }
      dfs2(to[i]);
   }
}
int main()
{
   scanf("%d%d", &n, &k);
   int i;
   int u, v;
   for (i = 1; i < n; ++i)
   {
      scanf("%d%d", &u, &v);
      addline(u, v);
   }
   for (i = 1; i <= n; ++i)
   {
      scanf("%d", &f[i][0]);
   }
   dfs1(1, 1);
   dfs2(1);
   int ans, j;
   for (i = 1; i <= n; ++i)
   {
      ans = 0;
      for (j = 0; j <= k; ++j)
      {
         ans += f[i][j];
      }
      printf("%d\n", ans);
   }
   return 0;
}
