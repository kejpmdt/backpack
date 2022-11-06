#include <iostream>
#include <cstdio>
#define MAXN 500005
#define MAXM 1000005
using namespace std;
int f[MAXN][30];
int depth[MAXN];
int fst[MAXN], nt[MAXM];
int to[MAXM];
int LCA(int a, int b)
{
   if (depth[a] > depth[b])
   {
      swap(a, b);
   }
   int x = 0;
   while (depth[f[b][x]] >= depth[a])
   {
      ++x;
   }
   --x;
   while (x >= 0)
   {
      if (depth[f[b][x]] >= depth[a])
      {
         b = f[b][x];
      }
      --x;
   }
   ++x;
   while (f[a][x] != f[b][x])
   {
      ++x;
   }
   while (x >= 0)
   {
      if (f[a][x] != f[b][x])
      {
         a = f[a][x];
         b = f[b][x];
      }
      --x;
   }
   return f[a][1];
}
void dfs1(int nw, int fa)
{
   f[nw][1] = fa;
   depth[nw] = depth[fa] + 1;
   if (to[fst[nw]] == fa)
   {
      fst[nw] = nt[fst[nw]];
   }
   int i;
   for (i = fst[nw]; i; i = nt[i])
   {
      if (to[nt[i]] == fa)
      {
         nt[i] = nt[nt[i]];
      }
      dfs1(to[i], nw);
   }
}
void addline(int a, int b)
{
   static int nw = 0;
   ++nw;
   to[nw] = b;
   nt[nw] = fst[a];
   fst[a] = nw;
   ++nw;
   to[nw] = a;
   nt[nw] = fst[b];
   fst[b] = nw;
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
   int i;
   int a, b;
   for (i = 1; i < n; ++i)
   {
      read(a, b);
      addline(a, b);
   }
   dfs1(s, s);
   int j;
   for (i = 1; i <= n; ++i)
   {
      f[i][0] = i;
   }
   for (i = 1; i < 29; ++i)
   {
      for (j = 1; j <= n; ++j)
      {
         f[j][i + 1] = f[f[j][i]][i];
      }
   }
   for (i = 1; i <= m; ++i)
   {
      read(a, b);
      printf("%d\n", LCA(a, b));
   }
   return 0;
}