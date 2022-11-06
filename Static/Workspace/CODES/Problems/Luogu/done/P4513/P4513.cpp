#include <cstdio>
#include <iostream>
#define mi2(a, b) (a < b ? a : b)
#define mx2(a, b) (a > b ? a : b)
#define MAXN 500005
using namespace std;
int inp[MAXN];
struct node
{
   int l, r;
   node *lc, *rc;
   int data, sum;
   int lmax, rmax;
   node(void) {}
   node(int L, int R, int ans, int num) : lmax(L), rmax(R), data(ans), sum(num) {}
   void pushup(void)
   {
      sum = lc->sum + rc->sum;
      data = mx2(mx2(lc->data, rc->data), lc->rmax + rc->lmax);
      lmax = mx2(lc->lmax, lc->sum + rc->lmax);
      rmax = mx2(rc->rmax, rc->sum + lc->rmax);
   }
   void build(int L, int R)
   {
      l = L, r = R;
      if (l == r)
      {
         lmax = rmax = sum = data = inp[l];
         lc = rc = nullptr;
         return;
      }
      lc = new node;
      rc = new node;
      lc->build(l, (l + r) >> 1);
      rc->build(((l + r) >> 1) + 1, r);
      pushup();
   }
   void change(int x, int k)
   {
      if (l == r)
      {
         sum = lmax = rmax = data = k;
         return;
      }
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
   node ask(int L, int R)
   {
      if (R < l || L > r)
      {
         return node(0, 0, 0, 0);
      }
      if (L <= l && R >= r)
      {
         return node(lmax, rmax, data, sum);
      }
      if (R <= (l + r) >> 1)
      {
         return lc->ask(L, R);
      }
      if (L > (l + r) >> 1)
      {
         return rc->ask(L, R);
      }
      node a = lc->ask(L, R);
      node b = rc->ask(L, R);
      return node(mx2(a.lmax, a.sum + b.lmax), mx2(b.rmax, b.sum + a.rmax), mx2(mx2(a.data, b.data), a.rmax + b.lmax), a.sum + b.sum);
   }
} * root;
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
   int n, m;
   read(n, m);
   int i;
   for (i = 1; i <= n; ++i)
   {
      read(inp[i]);
   }
   root = new node;
   root->build(1, n);
   int a, b;
   signed char opt;
   while (m--)
   {
      read(opt, a, b);
      if (opt == 1)
      {
         if (a > b)
         {
            swap(a, b);
         }
         printf("%d\n", root->ask(a, b).data);
      }
      else
      {
         root->change(a, b);
      }
   }
   return 0;
}