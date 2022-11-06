#include <iostream>
#include <cstdio>
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
long long f[200005];
int main()
{
   int n, m;
   scanf("%d%d", &n, &m);
   ++m;
   long long sum = 0;
   for (int i = 1; i <= n; ++i)
   {
      scanf("%d", &cost[i]);
      sum += cost[i];
   }
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

   printf("%lld", sum - f[q.front()]);
}