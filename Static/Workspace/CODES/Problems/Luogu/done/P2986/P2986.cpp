#include <cstdio>
#define MAXN 100005
#define MAXM 200005
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
long long n;
long long fst[MAXN], nt[MAXM];
long long to[MAXM];
long long v[MAXM];
long long weight[MAXN];
long long cost[MAXN];
long long fa[MAXN];
void addline(long long a, long long b, long long c)
{
   static long long i = 0;
   to[++i] = b, nt[i] = fst[a], fst[a] = i, v[i] = c;
   to[++i] = a, nt[i] = fst[b], fst[b] = i, v[i] = c;
}
void dfs1(long long nw, long long f)
{
   fa[nw] = f;
   if (to[fst[nw]] == f)
   {
      fst[nw] = nt[fst[nw]];
   }
   long long i;
   cost[nw] = 0;
   for (i = fst[nw]; i; i = nt[i])
   {
      if (to[nt[i]] == f)
      {
         nt[i] = nt[nt[i]];
      }
      dfs1(to[i], nw);
      cost[nw] += cost[to[i]];
      cost[nw] += weight[to[i]] * v[i];
      weight[nw] += weight[to[i]];
   }
   return;
}
long long z;
long long dfs2(long long nw)
{
   long long i;
   for (i = fst[nw]; i; i = nt[i])
   {
      if (weight[to[i]] > z / 2)
      {
         return cost[nw] - cost[to[i]] - weight[to[i]] * v[i] + (z - weight[to[i]]) * v[i] + dfs2(to[i]);
      }
   }
   return cost[nw];
}
int main()
{
   read(n);
   for (long long i = 1; i <= n; ++i)
   {
      read(weight[i]);
      z += weight[i];
   }
   long long a, b, c;
   for (long long i = 1; i < n; ++i)
   {
      read(a, b, c);
      addline(a, b, c);
   }
   dfs1(1, 1);
   printf("%lld", dfs2(1));
   return 0;
}