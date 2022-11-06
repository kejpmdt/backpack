#include <iostream>
#include <cstdio>
#define mi2(a, b) (a < b ? a : b)
#define mx2(a, b) (a > b ? a : b)
using namespace std;
#define MAXN 100005
#define MAXM 200005
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
int fst[MAXN], nt[MAXM];
int to[MAXM];
int v[MAXM];
int zpld[MAXN], bigc[MAXN], depth[MAXN], fa[MAXN], dfsn[MAXN];
int weight[MAXN];
int data[MAXN];
struct node
{
   int l, r;
   node *lc, *rc;
   int mx;
   int lazy;
   int chg;
   bool chd;
   void add(int, int, int);
   int ask(int, int);
   void build(int, int);
   void change(int, int, int);
   void pushdown(void);
   void pushup(void);
} * root;
void add(int, int, int);
void addline(int, int, int);
int ask(int, int);
void change(int, int);
void cover(int, int, int);
void dfs1(int, int);
void dfs2(int, int, int);
void dfs3(int);
int main()
{
   int n;
   read(n);
   int a, b, c;
   root = new node;
   for (int i = 1; i < n; ++i)
   {
      read(a, b, c);
      addline(a, b, c);
   }
   dfs1(1, 1);
   dfs2(1, 1, 0);
   dfs3(1);
   root->build(1, n);
   string s;
   while (cin >> s)
   {
      if (s == "Stop")
      {
         return 0;
      }
      if (s == "Max")
      {
         read(a, b);
         printf("%d\n", ask(a, b));
      }
      if (s == "Add")
      {
         read(a, b, c);
         add(a, b, c);
      }
      if (s == "Change")
      {
         read(a, b);
         change(a, b);
      }
      if (s == "Cover")
      {
         read(a, b, c);
         cover(a, b, c);
      }
   }
   return 0;
}
void node::add(int L, int R, int k)
{
   if (L <= l && R >= r)
   {
      mx += k;
      lazy += k;
      chg += k;
      return;
   }
   pushdown();
   if (L <= (l + r) >> 1)
   {
      lc->add(L, R, k);
   }
   else
   {
      rc->add(L, R, k);
   }
   pushup();
}
int node::ask(int L, int R)
{
   if (L <= l && R >= r)
   {
      return mx;
   }
   pushdown();
   if (R <= (l + r) >> 1)
   {
      return lc->ask(L, R);
   }
   if (L > (l + r) >> 1)
   {
      return rc->ask(L, R);
   }
   int a = lc->ask(L, R);
   int b = rc->ask(L, R);
   return mx2(a, b);
}
void node::build(int L, int R)
{
   l = L, r = R;
   lazy = 0;
   chd = false;
   if (l == r)
   {
      mx = data[l];
      lc = rc = nullptr;
      return;
   }
   lc = new node;
   rc = new node;
   lc->build(l, (l + r) >> 1);
   rc->build(((l + r) >> 1) + 1, r);
   pushup();
}
void node::change(int L, int R, int k)
{
   if (L <= l && R >= r)
   {
      mx = k;
      lazy = 0;
      chd = true;
      chg = k;
      return;
   }
   pushdown();
   if (L <= (l + r) >> 1)
   {
      lc->change(L, R, k);
   }
   if (R > (l + r) >> 1)
   {
      rc->change(L, R, k);
   }
   pushup();
}
inline void node::pushdown(void)
{
   lc->mx += lazy;
   rc->mx += lazy;
   lc->lazy += lazy;
   rc->lazy += lazy;
   lc->chg += lazy;
   rc->chg += lazy;
   lazy = 0;
   if (chd)
   {
      lc->chd = true;
      lc->chg = chg;
      rc->chd = true;
      rc->chg = chg;
      lc->mx = chg;
      rc->mx = chg;
      lc->lazy = 0;
      rc->lazy = 0;
      chd = false;
   }
}
void node::pushup(void)
{
   mx = mx2(lc->mx, rc->mx);
}
void add(int a, int b, int k)
{
   while (1)
   {
      if (zpld[a] == zpld[b])
      {
         if (a == b)
         {
            return;
         }
         if (depth[a] > depth[b])
         {
            swap(a, b);
         }
         root->add(dfsn[a] + 1, dfsn[b], k);
         return;
      }
      if (depth[zpld[a]] < depth[zpld[b]])
      {
         swap(a, b);
      }
      root->add(dfsn[zpld[a]], dfsn[a], k);
      a = fa[zpld[a]];
   }
}
void addline(int a, int b, int c)
{
   static int i = 1;
   ++i;
   to[i] = b;
   v[i] = c;
   nt[i] = fst[a];
   fst[a] = i;
   ++i;
   to[i] = a;
   v[i] = c;
   nt[i] = fst[b];
   fst[b] = i;
}
int ask(int a, int b)
{
   int ans = 0x80000000;
   int u;
   while (1)
   {
      if (zpld[a] == zpld[b])
      {
         if (a == b)
         {
            return ans;
         }
         if (depth[a] > depth[b])
         {
            swap(a, b);
         }
         u = root->ask(dfsn[a] + 1, dfsn[b]);
         ans = mx2(ans, u);
         return ans;
      }
      if (depth[zpld[a]] < depth[zpld[b]])
      {
         swap(a, b);
      }
      u = root->ask(dfsn[zpld[a]], dfsn[a]);
      a = fa[zpld[a]];
      ans = mx2(ans, u);
   }
}
void change(int x, int k)
{
   root->change(dfsn[v[x]], dfsn[v[x]], k);
}
void cover(int a, int b, int k)
{
   while (1)
   {
      if (zpld[a] == zpld[b])
      {
         if (a == b)
         {
            return;
         }
         if (depth[a] > depth[b])
         {
            swap(a, b);
         }
         root->change(dfsn[a] + 1, dfsn[b], k);
         return;
      }
      if (depth[zpld[a]] < depth[zpld[b]])
      {
         swap(a, b);
      }
      root->change(dfsn[zpld[a]], dfsn[a], k);
      a = fa[zpld[a]];
   }
}
void dfs1(int nw, int f)
{
   fa[nw] = f;
   weight[nw] = 1;
   depth[nw] = depth[f] + 1;
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
   int i;
   for (i = fst[nw]; i; i = nt[i])
   {
      if (i == bigc[nw])
      {
         continue;
      }
      dfs2(to[i], to[i], v[i]);
   }
}
void dfs3(int nw)
{
   if (!bigc[nw])
   {
      return;
   }
   v[bigc[nw] >> 1] = to[bigc[nw]];
   bigc[nw] = to[bigc[nw]];
   dfs3(bigc[nw]);
   int i;
   for (i = fst[nw]; i; i = nt[i])
   {
      if (to[i] == bigc[nw])
      {
         continue;
      }
      v[i >> 1] = to[i];
      dfs3(to[i]);
   }
}