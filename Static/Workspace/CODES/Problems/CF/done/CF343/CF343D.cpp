#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
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
#define MAXN 500005
#define MAXM 1000005
int fst[MAXN], nt[MAXM];
int to[MAXM];
int zpld[MAXN], bigc[MAXN], depth[MAXN], fa[MAXN], dfsn[MAXN];
int weight[MAXN];
int data[MAXN];
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
   static int x = 0;
   zpld[nw] = ld;
   dfsn[nw] = ++x;
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
struct node
{
   int l, r;
   bool one;
   bool zero;
   node *lc;
   node *rc;
   void build(int L, int R)
   {
      l = L;
      r = R;
      zero = true;
      one = false;
      if (l == r)
      {
         lc = rc = nullptr;
         return;
      }
      lc = new node;
      rc = new node;
      lc->build(l, (l + r) >> 1);
      rc->build(((l + r) >> 1) + 1, r);
   }
   void pushup(void)
   {
      if (l == r)
      {
         return;
      }
      if (lc->one && rc->one)
      {
         one = true;
         zero = false;
         return;
      }
      if (lc->zero && rc->zero)
      {
         zero = true;
         one = false;
         return;
      }
      zero = one = false;
   }
   void pushdown(void)
   {
      if (one)
      {
         lc->one = rc->one = true;
         lc->zero = rc->zero = false;
         return;
      }
      if (zero)
      {
         lc->one = rc->one = false;
         lc->zero = rc->zero = true;
         return;
      }
   }
   void change(int L, int R, bool p)
   {
      if (L <= l && R >= r)
      {
         if (p)
         {
            one = true;
            zero = false;
         }
         else
         {
            one = false;
            zero = true;
         }
         return;
      }
      pushdown();
      if (L <= (l + r) >> 1)
      {
         lc->change(L, R, p);
      }
      if (R > (l + r) >> 1)
      {
         rc->change(L, R, p);
      }
      pushup();
   }
   int ask(int k)
   {
      if (one)
      {
         return true;
      }
      if (zero)
      {
         return false;
      }
      if (k <= (l + r) >> 1)
      {
         return lc->ask(k);
      }
      else
      {
         return rc->ask(k);
      }
   }
} * root;
void change(int u)
{
   while (1)
   {
      if (u == 1)
      {
         root->change(dfsn[1], dfsn[1], false);
         return;
      }
      root->change(dfsn[zpld[u]], dfsn[u], false);
      u = fa[zpld[u]];
   }
}
int main()
{
   freopen("Wt.in", "r", stdin);
   freopen("Wt.out", "w", stdout);
   int n, m;
   int a, b;
   read(n);
   int i;
   for (i = 1; i < n; ++i)
   {
      read(a, b);
      addline(a, b);
   }
   root = new node;
   root->build(1, n);
   dfs1(1, 1);
   dfs2(1, 1);
   read(m);
   for (i = 1; i <= m; ++i)
   {
      read(a, b);
      if (a == 1)
      {
         root->change(dfsn[b], dfsn[b] + weight[b] - 1, true);
      }
      if (a == 2)
      {
         change(b);
      }
      if (a == 3)
      {
         printf("%d\n", root->ask(dfsn[b]));
      }
   }
   return 0;
}