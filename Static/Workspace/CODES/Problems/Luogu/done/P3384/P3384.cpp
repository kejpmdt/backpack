#include <iostream>
#include <cstdio>
#define MAXN 100005
#define MAXM 200005
using namespace std;
int fst[MAXN], nt[MAXM];
int to[MAXM];
int v[MAXM];
int inp[MAXM];
int zpld[MAXN], bigc[MAXN], depth[MAXN], fa[MAXN], dfsn[MAXN];
int sz[MAXN];
int P;
class node
{
public:
   node *lc;
   node *rc;
   long long sum;
   int l, r;
   long long add;
   void build(int L, int R)
   {
      l = L, r = R;
      add = 0;
      if (L == R)
      {
         sum = v[L];
         return;
      }
      lc = new node;
      rc = new node;
      lc->build(L, (L + R) >> 1);
      rc->build(((L + R) >> 1) + 1, R);
      pushup();
      return;
   }
   void pushup(void)
   {
      if (lc)
      {
         sum = (lc->sum + rc->sum) % P;
      }
   }
   void pushdown(void)
   {
      if (lc)
      {
         lc->add += add;
         lc->sum += add * (lc->r - lc->l + 1);
         lc->add %= P;
         lc->sum %= P;
      }
      if (rc)
      {
         rc->add += add;
         rc->sum += add * (rc->r - rc->l + 1);
         rc->add %= P;
         rc->sum %= P;
      }
      add = 0;
   }
   void Add(int L, int R, long long k)
   {
      if (L <= l && R >= r)
      {
         add += k;
         sum += k * (r - l + 1);
         sum %= P;
         add %= P;
         return;
      }
      pushdown();
      if (L <= (l + r) >> 1)
      {
         lc->Add(L, R, k);
      }
      if (R > (l + r) >> 1)
      {
         rc->Add(L, R, k);
      }
      pushup();
   }
   long long ask(int L, int R)
   {
      if (L <= l && R >= r)
      {
         return sum;
      }
      pushdown();
      long long ans = 0;
      if (L <= (l + r) >> 1)
      {
         ans += lc->ask(L, R);
      }
      if (R > (l + r) >> 1)
      {
         ans += rc->ask(L, R);
      }
      return ans;
   }
} * root;
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
   int i;
   sz[nw] = 1;
   depth[nw] = depth[f] + 1;
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
   static int x = 0;
   zpld[nw] = ld;
   dfsn[nw] = ++x;
   v[dfsn[nw]] = inp[nw];
   int i;
   if (!bigc[nw])
   {
      return;
   }
   dfs2(bigc[nw], ld);
   for (i = fst[nw]; i; i = nt[i])
   {
      if (to[i] == bigc[nw])
      {
         continue;
      }
      dfs2(to[i], to[i]);
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
void spadd(int a, int b, int k)
{
   while (1)
   {
      if (zpld[a] == zpld[b])
      {
         if (depth[a] > depth[b])
         {
            swap(a, b);
         }
         root->Add(dfsn[a], dfsn[b], k);
         return;
      }
      if (depth[zpld[a]] < depth[zpld[b]])
      {
         swap(a, b);
      }
      root->Add(dfsn[zpld[a]], dfsn[a], k);
      a = fa[zpld[a]];
   }
}
long long spask(int a, int b)
{
   long long ans = 0;
   while (1)
   {
      if (zpld[a] == zpld[b])
      {
         if (depth[a] > depth[b])
         {
            swap(a, b);
         }
         ans += root->ask(dfsn[a], dfsn[b]);
         ans %= P;
         return ans;
      }
      if (depth[zpld[a]] < depth[zpld[b]])
      {
         swap(a, b);
      }
      ans += root->ask(dfsn[zpld[a]], dfsn[a]);
      ans %= P;
      a = fa[zpld[a]];
   }
}
void treeadd(int a, int k)
{
   root->Add(dfsn[a], dfsn[a] + sz[a] - 1, k);
}
long long treeask(int a)
{
   return root->ask(dfsn[a], dfsn[a] + sz[a] - 1);
}
int n, m, r;
void show(void)
{
   int i, j;
   for (i = 1; i <= n; ++i)
   {
      for (j = fst[i]; j; j = nt[j])
      {
         printf("%d %d\n", i, j);
      }
   }
   for (i = 1; i <= n; ++i)
   {
      printf("%d ", root->ask(dfsn[i], dfsn[i]));
   }
   return;
}
int main()
{
   freopen("F:\\tests\\P3384_2.in", "r", stdin);
   read(n, m, r, P);
   int i;
   for (i = 1; i <= n; ++i)
   {
      read(inp[i]);
      inp[i] %= P;
   }
   int a, b;
   for (i = 1; i < n; ++i)
   {
      read(a, b);
      addline(a, b);
   }
   dfs1(r, r);
   dfs2(r, r);
   root = new node;
   root->build(1, n);
   //   show();
   unsigned char opt;
   int k;
   for (i = 1; i <= m; ++i)
   {
      read(opt);
      if (opt == 1)
      {
         read(a, b, k);
         k %= P;
         spadd(a, b, k);
      }
      else if (opt == 2)
      {
         read(a, b);
         printf("%lld\n", spask(a, b) % P);
      }
      else if (opt == 3)
      {
         read(a, k);
         k %= P;
         treeadd(a, k);
      }
      else
      {
         read(a);
         printf("%lld\n", treeask(a) % P);
      }
   }
   return 0;
}
