#include <cstdio>
#include <cstring>
#include <algorithm>
#define mx2(a, b) (a > b ? a : b)
#define MAXN 300005
using namespace std;
int fa[MAXN];
int v[2 * MAXN];
int fst[MAXN];
int nt[2 * MAXN];
int to[2 * MAXN];
int zpld[MAXN];
int weight[MAXN];
int bigson[MAXN];
int times[MAXN];
int deep[MAXN];
int p[MAXN];
int dis[MAXN];
inline int read(void)
{
   int ans = 0;
   char us = getchar();
   bool f = false;
   while (us < '0' || us > '9')
   {
      f |= (us == '-');
      us = getchar();
   }
   while (us >= '0' && us <= '9')
   {
      ans = (ans << 1) + (ans << 3) + (us ^ 48);
      us = getchar();
   }
   return f ? -ans : ans;
}
void dfs1(int nw, int f)
{
   times[nw] = 1;
   deep[nw] = deep[f] + 1;
   fa[nw] = f;
   if (to[fst[nw]] == f)
   {
      fst[nw] = nt[fst[nw]];
   }
   for (int i = fst[nw]; i; i = nt[i])
   {
      if (to[nt[i]] == f)
      {
         nt[i] = nt[nt[i]];
      }
      dis[to[i]] = dis[nw] + v[i];
      dfs1(to[i], nw);
      weight[to[i]] = v[i];
      if (times[to[i]] > times[bigson[nw]])
      {
         bigson[nw] = to[i];
      }
      times[nw] += times[to[i]];
   }
}
void dfs2(int nw, int ld)
{
   zpld[nw] = ld;
   if (bigson[nw] != 0)
   {
      dfs2(bigson[nw], ld);
   }
   for (int i = fst[nw]; i; i = nt[i])
   {
      if (to[i] == bigson[nw])
      {
         continue;
      }
      dfs2(to[i], to[i]);
   }
}
int re;
int nd;
void dfs3(int nw)
{
   p[nw] = times[nw];
   for (int i = fst[nw]; i; i = nt[i])
   {
      dfs3(to[i]);
      p[nw] += p[to[i]];
   }
   if (p[nw] == nd)
   {
      re = mx2(re, weight[nw]);
   }
}
int lca(int a, int b)
{
   while (zpld[a] != zpld[b])
   {
      if (deep[zpld[a]] < deep[zpld[b]])
      {
         b = fa[zpld[b]];
      }
      else
      {
         a = fa[zpld[a]];
      }
   }
   return deep[a] < deep[b] ? a : b;
}
struct ask
{
   int frm, to, lca, length;
   bool operator<(const ask &other) const { return length > other.length; }
} asks[MAXN];
int n, m;
int findbig(int x)
{
   int l = 1;
   int r = m + 1;
   while (l != r - 1)
   {
      if (asks[(l + r) >> 1].length <= x)
      {
         r = (l + r) >> 1;
      }
      else
      {
         l = (l + r) >> 1;
      }
   }
   return l;
}
bool pd(int x, int d)
{
   memset(times, 0, sizeof times);
   for (int i = 1; i <= x; ++i)
   {
      if (asks[i].frm != asks[i].lca)
      {
         ++times[asks[i].frm];
      }
      if (asks[i].to != asks[i].lca)
      {
         ++times[asks[i].to];
      }
      if (asks[i].frm != asks[i].to)
      {
         -- --times[asks[i].lca];
      }
   }
   nd = x;
   re = 0;
   dfs3(1);
   for (int i = 1; i <= x; ++i)
   {
      if (asks[i].frm != asks[i].lca)
      {
         --times[asks[i].frm];
      }
      if (asks[i].to != asks[i].lca)
      {
         --times[asks[i].to];
      }
      if (asks[i].frm != asks[i].to)
      {
         ++ ++times[asks[i].lca];
      }
   }

   if (asks[1].length - re <= d)
   {
      return true;
   }
   else
   {
      return false;
   }
}
void show()
{
   for (int i = 1; i <= m; ++i)
   {
      printf("%d ", asks[i].length);
   }
   printf("\n");
   printf("\n");
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
   freopen("debug.txt", "w", stdout);
#endif
   re = 0;
   n = read();
   m = read();
   int i;
   int a, b, c;
   for (i = 1; i < n; ++i)
   {
      a = read();
      b = read();
      c = read();
      v[i] = v[i + n] = c;
      to[i] = b;
      to[i + n] = a;
      nt[i] = fst[a];
      nt[i + n] = fst[b];
      fst[a] = i;
      fst[b] = i + n;
   }
   dfs1(1, 1);
   dfs2(1, 1);
   memset(times, 0x00, sizeof times);
   for (i = 1; i <= m; ++i)
   {
      asks[i].frm = read();
      asks[i].to = read();
      asks[i].lca = lca(asks[i].frm, asks[i].to);
      asks[i].length = dis[asks[i].frm] + dis[asks[i].to] - 2 * dis[asks[i].lca];
   }
   int l, r, x;
   sort(asks + 1, asks + m + 1);
   l = -1;
   r = asks[1].length;
   while (l < r - 1)
   {
      x = findbig((l + r) >> 1);
      if (pd(x, (l + r) >> 1))
      {
         r = (l + r) >> 1;
      }
      else
      {
         l = (l + r) >> 1;
      }
   }
   printf("%u", r);
   return 0;
}