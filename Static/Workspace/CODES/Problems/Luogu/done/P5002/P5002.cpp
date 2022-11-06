#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 10005
#define MAXM 20005
#define MOD 1000000007
int fst[MAXN], nt[MAXM];
int to[MAXM];
long long sz[MAXN];
long long ans[MAXN];
void addline(int a, int b)
{
   static int i = 0;
   ++i;
   to[i] = b;
   nt[i] = fst[a];
   fst[a] = i;
   ++i;
   to[i] = a;
   nt[i] = fst[b];
   fst[b] = i;
}
void dfs1(int nw, int f)
{
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
   int n, r, m;
   read(n, r, m);
   int i;
   int a, b;
   for (i = 1; i < n; ++i)
   {
      read(a, b);
      addline(a, b);
   }
   dfs1(r, r);
   int j;
   for (i = 1; i <= n; ++i)
   {
      ans[i] = 0;
      for (j = fst[i]; j; j = nt[j])
      {
         ans[i] += sz[to[j]] * (sz[i] - sz[to[j]] - 1) % MOD;
      }
      ans[i] += 2 * sz[i];
      ans[i] -= 1;
      ans[i] %= MOD;
   }
   for (i = 1; i <= m; ++i)
   {
      read(a);
      printf("%lld\n", ans[a]);
   }
   return 0;
}