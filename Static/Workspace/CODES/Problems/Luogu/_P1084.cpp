#include <iostream>
#include <cstdio>
#include <queue>
#define MAXN 50005
#define MAXM 100005
using namespace std;
int fst[MAXN], nt[MAXM];
int to[MAXM];
int v[MAXM];
int zpld[MAXN], bigc[MAXN], depth[MAXN], fa[MAXN], dfsn[MAXN];
int weight[MAXN];
int data[MAXN];
int ars[MAXN];
int place[MAXN];
struct node
{
   node *lc;
   node *rc;
   long long sum;
   int l;
   int r;
   void pushup(void)
   {
      if (l == r)
      {
         return;
      }
      sum = lc->sum + rc->sum;
   }
   void build(int L, int R)
   {
      l = L;
      r = R;
      if (l == r)
      {
         sum = data[l];
         lc = rc = nullptr;
         return;
      }
      lc = new node;
      rc = new node;
      lc->build(l, (l + r) >> 1);
      rc->build(((l + r) >> 1) + 1, r);
      pushup();
   }
   int ask(int L, int R)
   {
      if (L <= l && R >= r)
      {
         return sum;
      }
      if (L > r || R < l)
      {
         return 0;
      }
      return lc->ask(L, R) + rc->ask(L, R);
   }
} * root;
void dfs1(int nw, int f)
{
   fa[nw] = f;
   depth[nw] = depth[f] + 1;
   weight[nw] = 1;
   int i;
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
      weight[nw] += weight[to[i]];
      if (weight[to[i]] > weight[bigc[nw]])
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
      weight[to[i]] = v[i];
      if (to[i] == bigc[nw])
      {
         continue;
      }
      dfs2(to[i], to[i]);
   }
}
void dfs3(int nw)
{
   static int x = 0;
   dfsn[nw] = ++x;
   data[x] = weight[nw];
   if (!bigc[nw])
   {
      return;
   }
   dfs3(bigc[nw]);
   int i;
   for (i = fst[nw]; i; i = nt[i])
   {
      if (to[i] == bigc[nw])
      {
         continue;
      }
      dfs3(to[i]);
   }
}
void addline(int a, int b, int c)
{
   static int i = 0;
   ++i;
   to[i] = b;
   nt[i] = fst[a];
   fst[a] = i;
   v[i] = c;
   ++i;
   to[i] = a;
   nt[i] = fst[b];
   fst[b] = i;
   v[i] = c;
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
int n, m;
bool check(long long x)
{
   int i, j;
   for (j = 1; j <= m; ++j)
   {
   }
}
int main()
{
   read(n);
   root = new node;
   int i, a, b, c;
   for (i = 1; i < n; ++i)
   {
      read(a, b, c);
      addline(a, b, c);
   }
   dfs1(1, 1);
   dfs2(1, 1);
   dfs3(1);
   root->build(1, n);
   read(m);
   if (m == 1 && nt[fst[1]])
   {
      printf("-1");
      return 0;
   }
   for (i = 1; i <= m; ++i)
   {
      read(ars[i]);
   }
   long long l, r;
   l = -1, r = 60000000000000ll;
   while (l < r - 1)
   {
      if (check((l + r) >> 1))
      {
         r = (l + r) >> 1;
      }
      else
      {
         l = (l + r) >> 1;
      }
   }
   printf("%lld", r);
   return 0;
}
