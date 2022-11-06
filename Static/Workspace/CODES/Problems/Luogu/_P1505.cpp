#include <iostream>
#include <cstdio>
#define MAXN 200005
#define MAXM 400005
#define mi2(a, b) (a < b ? a : b)
#define mx2(a, b) (a > b ? a : b)
using namespace std;
int fst[MAXN], nt[MAXM];
int to[MAXM];
int v[MAXM];
int chg[MAXN];
int zpld[MAXN], bigc[MAXN], depth[MAXN], fa[MAXN], dfsn[MAXN];
int weight[MAXN];
int data[MAXN];
struct node
{
   int l, r;
   node *lc, *rc;
   int sum, mi, mx;
   bool pd;
   int askmax(int, int);
   int askmin(int, int);
   int asksum(int, int);
   void build(int, int);
   void change(int, int);
   void pushdown(void);
   void pushup(void);
   void reserve(int, int);
} * root;
void addline(int, int, int);
int askmax(int, int);
int askmin(int, int);
int asksum(int, int);
void change(int, int);
void dfs1(int, int);
void dfs2(int, int, int);
void reserve(int, int);
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
int main()
{
   root = new node;
   read(n);
   int a, b, c;
   string s;
   int i;
   for (i = 1; i < n; ++i)
   {
      read(a, b, c);
      addline(a + 1, b + 1, c);
   }
   dfs1(1, 1);
   dfs2(1, 1, 1);
   root->build(1, n);
   read(m);
   for (i = 1; i <= m; ++i)
   {
      cin >> s;
      read(a, b);
      if (s == "SUM")
      {
         printf("%d\n", asksum(a + 1, b + 1));
      }
      if (s == "MIN")
      {
         printf("%d\n", askmin(a + 1, b + 1));
      }
      if (s == "MAX")
      {
         printf("%d\n", askmax(a + 1, b + 1));
      }
      if (s == "C")
      {
         change(a, b);
      }
      if (s == "N")
      {
         reserve(a + 1, b + 1);
      }
   }
   return 0;
}
int node::askmax(int L, int R)
{
   if (L <= l && R >= r)
   {
      return mx;
   }
   pushdown();
   if (R <= (l + r) >> 1)
   {
      return lc->askmax(L, R);
   }
   if (L > (l + r) >> 1)
   {
      return rc->askmax(L, R);
   }
   int a = lc->askmax(L, R);
   int b = rc->askmax(L, R);
   return mx2(a, b);
}
int node::askmin(int L, int R)
{
   if (L <= l && R >= r)
   {
      return mi;
   }
   pushdown();
   if (R <= (l + r) >> 1)
   {
      return lc->askmin(L, R);
   }
   if (L > (l + r) >> 1)
   {
      return rc->askmin(L, R);
   }
   int a = lc->askmin(L, R);
   int b = rc->askmin(L, R);
   return mi2(a, b);
}
int node::asksum(int L, int R)
{
   if (L <= l && R >= r)
   {
      return mi;
   }
   pushdown();
   if (R <= (l + r) >> 1)
   {
      return lc->asksum(L, R);
   }
   if (L > (l + r) >> 1)
   {
      return rc->asksum(L, R);
   }
   return lc->asksum(L, R) + rc->asksum(L, R);
}
void node::build(int L, int R)
{
   l = L, r = R;
   pd = false;
   if (l == r)
   {
      lc = rc = nullptr;
      sum = mi = mx = data[l];
      return;
   }
   lc = new node;
   rc = new node;
   lc->build(l, (l + r) >> 1);
   rc->build(((l + r) >> 1) + 1, r);
   pushup();
}
void node::change(int x, int k)
{
   if (l == r)
   {
      sum = mi = mx = k;
      return;
   }
   pushdown();
   if (x <= (l + r) >> 1)
   {
      lc->change(x, k);
   }
   else
   {
      rc->change(x, k);
   }
   pushup();
}
void node::pushdown(void)
{
   if (!pd)
   {
      return;
   }
   lc->sum = -lc->sum;
   lc->mi = -lc->mi;
   lc->mx = -lc->mx;
   swap(lc->mi, lc->mx);
   lc->pd = !lc->pd;
   rc->sum = -rc->sum;
   rc->mi = -rc->mi;
   rc->mx = -rc->mx;
   swap(rc->mi, rc->mx);
   rc->pd = !rc->pd;
   pd = false;
}
void node::pushup(void)
{
   sum = lc->sum + rc->sum;
   mi = mi2(lc->mi, rc->mi);
   mx = mx2(lc->mx, rc->mx);
}
void node::reserve(int L, int R)
{
   if (L <= l && R >= r)
   {
      sum = -sum;
      mi = -mi;
      mx = -mx;
      swap(mi, mx);
      pd = !pd;
      return;
   }
   pushdown();
   if (R > (l + r) >> 1)
   {
      rc->reserve(L, R);
   }
   if (L <= (l + r) >> 1)
   {
      lc->reserve(L, R);
   }
   pushup();
}
void addline(int a, int b, int c)
{
   static int i = 1;
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
int askmax(int a, int b)
{
   int ans = 0x80000000;
   int u;
   while (1)
   {
      if (zpld[a] == zpld[b])
      {
         if (depth[a] > depth[b])
         {
            swap(a, b);
         }
         if (a == b)
         {
            return ans;
         }
         u = root->askmax(dfsn[a] + 1, dfsn[b]);
         ans = mx2(ans, u);
         return ans;
      }
      if (depth[zpld[a]] < depth[zpld[b]])
      {
         swap(a, b);
      }
      u = root->askmax(dfsn[zpld[a]], dfsn[a]);
      ans = mx2(ans, u);
      a = fa[zpld[a]];
   }
}
int askmin(int a, int b)
{
   int ans = 0x7fffffff;
   int u;
   while (1)
   {
      if (zpld[a] == zpld[b])
      {
         if (depth[a] > depth[b])
         {
            swap(a, b);
         }
         if (a == b)
         {
            return ans;
         }
         u = root->askmin(dfsn[a] + 1, dfsn[b]);
         ans = mi2(ans, u);
         return ans;
      }
      if (depth[zpld[a]] < depth[zpld[b]])
      {
         swap(a, b);
      }
      u = root->askmin(dfsn[zpld[a]], dfsn[a]);
      ans = mi2(ans, u);
      a = fa[zpld[a]];
   }
}
int asksum(int a, int b)
{
   int ans = 0;
   while (1)
   {
      if (zpld[a] == zpld[b])
      {
         if (depth[a] > depth[b])
         {
            swap(a, b);
         }
         if (a == b)
         {
            return ans;
         }
         ans += root->asksum(dfsn[a] + 1, dfsn[b]);
         return ans;
      }
      if (depth[zpld[a]] < depth[zpld[b]])
      {
         swap(a, b);
      }
      ans += root->asksum(dfsn[zpld[a]], dfsn[a]);
      a = fa[zpld[a]];
   }
}
void change(int x, int k)
{
   root->change(dfsn[chg[x]], k);
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
      chg[i >> 1] = to[i];
      dfs1(to[i], nw);
      if (weight[to[i]] > weight[to[bigc[nw]]])
      {
         bigc[nw] = i;
      }
      weight[nw] += weight[to[i]];
   }
}
void dfs2(int nw, int ld, int dat)
{
   static int x = 0;
   zpld[nw] = ld;
   dfsn[nw] = ++x;
   data[x] = dat;
   if (!bigc[nw])
   {
      return;
   }
   dfs2(to[bigc[nw]], ld, v[bigc[nw]]);
   bigc[nw] = to[bigc[nw]];
   int i;
   for (i = fst[nw]; i; i = nt[i])
   {
      if (to[i] == bigc[nw])
      {
         continue;
      }
      dfs2(to[i], to[i], v[i]);
   }
}
void reserve(int a, int b)
{
   while (1)
   {
      if (zpld[a] == zpld[b])
      {
         if (depth[a] > depth[b])
         {
            swap(a, b);
         }
         if (a == b)
         {
            return;
         }
         root->reserve(dfsn[a], dfsn[b]);
         return;
      }
      if (depth[zpld[a]] < depth[zpld[b]])
      {
         swap(a, b);
      }
      root->reserve(dfsn[zpld[a]], dfsn[a]);
      a = fa[zpld[a]];
   }
}