#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct dl
{
   struct node
   {
      node *lst;
      node *nt;
      int data;
      node(node *a, node *b, int c) : lst(a), nt(b), data(c) {}
   };
   node *fst;
   node *lst;
   dl()
   {
      lst = fst = new node(nullptr, nullptr, 0);
   }
   void push(int x)
   {
      node *us = new node(lst, nullptr, x);
      lst = lst->nt = us;
   }
   void pop_front()
   {
      if (fst->nt)
      {
         fst = fst->nt;
      }
   }
   void pop_back()
   {
      if (lst->lst)
      {
         lst = lst->lst;
      }
   }
   int front()
   {
      return fst->nt->data;
   }
   int back()
   {
      return lst->data;
   }
   bool empty()
   {
      return lst == fst;
   }
};
int cost[200005];
int n;
int f[200005];
int check(int m)
{
   dl q;
   q.push(0);
   for (int i = 1; i <= n; ++i)
   {
      if (!q.empty() && q.front() < i - m)
         q.pop_front();
      f[i] = f[q.front()] + cost[i];
      while (!q.empty() && f[q.back()] >= f[i])
         q.pop_back();
      q.push(i);
   }
   if (!q.empty() && q.front() <= n - m)
      q.pop_front();
   return q.empty() ? 50000 : f[q.front()];
}
int main()
{
   int t;
   scanf("%d%d", &n, &t);
   for (int i = 1; i <= n; ++i)
   {
      scanf("%d", &cost[i]);
   }
   int l = -1, r = n;
   while (l < r - 1)
   {
      if (check(((l + r) >> 1) + 1) <= t)
      {
         r = (l + r) >> 1;
      }
      else
      {
         l = (l + r) >> 1;
      }
   }
   printf("%d", r); // "6 4 5" 2 "5" 3 "4 5 2" 3 "4 5 2" 3 "6 3 5"
   return 0;
}