#include <iostream>
#include <cstdio>
#define MAXN 500005
#define MAXM 1000005
using namespace std;
int fst[MAXN], nt[MAXM];
int to[MAXM];
int zpld[MAXN], bigc[MAXN], depth[MAXN], fa[MAXN];
int sz[MAXN];
void addline(int a, int b)
{
   static int nw = 0;
   ++nw;
   nt[nw] = fst[a];
   to[nw] = b;
   fst[a] = nw;
   ++nw;
   nt[nw] = fst[b];
   to[nw] = a;
   fst[b] = nw;
}
void dfs1(int nw, int f)
{
   fa[nw] = f;
   depth[nw] = depth[f] + 1;
   int i;
   sz[nw] = 1;
   if (to[fst[nw]] == f)
   {
      fst[nw] = nt[fst[nw]];
   }
   for (i = fst[nw]; i; i = nt[i])
   {
      if (to[nt[i]] == f)
      {
         nt[i] = nt[nt[i]];
      }
      dfs1(to[i], nw);
      sz[nw] += sz[to[i]];
      if (sz[to[i]] > sz[bigc[nw]])
      {
         bigc[nw] = to[i];
      }
   }
}
void dfs2(int nw, int ld)
{
   zpld[nw] = ld;
   if (!bigc[nw])
   {
      return;
   }
   dfs2(bigc[nw], ld);
   int i;
   for (i = fst[nw]; i; i = nt[i])
   {
      if (to[i] == bigc[nw])
      {
         continue;
      }
      dfs2(to[i], to[i]);
   }
}
int LCA(int a, int b)
{
   while (1)
   {
      if (zpld[a] == zpld[b])
      {
         return depth[a] < depth[b] ? a : b;
      }
      if (depth[zpld[a]] < depth[zpld[b]])
      {
         b = fa[zpld[b]];
      }
      else
      {
         a = fa[zpld[a]];
      }
   }
}
template <class T>
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
template <class T, class... O>
void read(T &x, O &...oth)
{
   read(x);
   read(oth...);
}
int main()
{
   int n, m, s;
   read(n, m, s);
   int a, b;
   int i;
   for (i = 1; i < n; ++i)
   {
      read(a, b);
      addline(a, b);
   }
   dfs1(s, s);
   dfs2(s, s);
   for (i = 1; i <= m; ++i)
   {
      read(a, b);
      printf("%d\n", LCA(a, b));
   }
}
