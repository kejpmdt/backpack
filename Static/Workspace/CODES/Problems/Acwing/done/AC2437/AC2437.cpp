#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
struct Node
{
   int s[2], p, v;
   int size, flag;

   void init(int _v, int _p)
   {
      v = _v, p = _p;
      size = 1;
   }
} tr[N];
int root, idx;

void pushup(int x)
{
   tr[x].size = tr[tr[x].s[0]].size + tr[tr[x].s[1]].size + 1;
}

void pushdown(int x)
{
   if (tr[x].flag)
   {
      swap(tr[x].s[0], tr[x].s[1]);
      tr[tr[x].s[0]].flag ^= 1;
      tr[tr[x].s[1]].flag ^= 1;
      tr[x].flag = 0;
   }
}

void rotate(int x)
{
   int y = tr[x].p, z = tr[y].p;
   int k = tr[y].s[1] == x;
   tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;
   tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
   tr[x].s[k ^ 1] = y, tr[y].p = x;
   pushup(y), pushup(x);
}

void splay(int x, int k)
{
   while (tr[x].p != k)
   {
      int y = tr[x].p, z = tr[y].p;
      if (z != k)
         if ((tr[y].s[1] == x) ^ (tr[z].s[1] == y))
            rotate(x);
         else
            rotate(y);
      rotate(x);
   }
   if (!k)
      root = x;
}

void insert(int v)
{
   int u = root, p = 0;
   while (u)
      p = u, u = tr[u].s[v > tr[u].v];
   u = ++idx;
   if (p)
      tr[p].s[v > tr[p].v] = u;
   tr[u].init(v, p);
   splay(u, 0);
}

int get_k(int k)
{
   int u = root;
   while (true)
   {
      pushdown(u);
      if (tr[tr[u].s[0]].size >= k)
         u = tr[u].s[0];
      else if (tr[tr[u].s[0]].size + 1 == k)
         return u;
      else
         k -= tr[tr[u].s[0]].size + 1, u = tr[u].s[1];
   }
   return -1;
}
void output(int u)
{
   pushdown(u);
   if (tr[u].s[0])
      output(tr[u].s[0]);
   if (tr[u].v >= 1 && tr[u].v <= n)
      printf("%d ", tr[u].v);
   if (tr[u].s[1])
      output(tr[u].s[1]);
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
   read(n, m);
   for (int i = 0; i <= n + 1; ++i)
      insert(i);
   while (m--)
   {
      int l, r;
      read(l, r);
      l = get_k(l), r = get_k(r + 2);
      splay(l, 0), splay(r, l);
      tr[tr[r].s[0]].flag ^= 1;
   }
   output(root);
   return 0;
}