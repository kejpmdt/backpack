#include <iostream>
#include <cstdio>
using namespace std;
template <class T>
struct deque
{
   struct node
   {
      node *lst;
      node *nt;
      T data;
      node(node *a, node *b, T c) : lst(a), nt(b), data(c) {}
   };
   node *fst;
   node *lst;
   deque()
   {
      lst = fst = new node(nullptr, nullptr, 0);
   }
   void push_back(T x)
   {
      node *us = new node(lst, nullptr, x);
      lst = lst->nt = us;
   }
   void push_front(T x)
   {
      node *us = new node(fst, fst->nt, x);
      fst->nt = fst->nt->lst = us;
   }
   void pop_front()
   {
      if (fst->nt)
      {
         fst = fst->nt;
         delete fst->lst;
         fst->lst = nullptr;
      }
   }
   void pop_back()
   {
      if (lst->lst)
      {
         lst = lst->lst;
         delete lst->nt;
         lst->nt = nullptr;
      }
   }
   T front()
   {
      return empty() ? 0 : fst->nt->data;
   }
   T back()
   {
      return empty() ? 0 : lst->data;
   }
   bool empty()
   {
      return lst == fst;
   }
};
int ori[1005][1005];
int mx[1005][1005];
int mxans[1005][1005];
int mi[1005][1005];
int mians[1005][1005];
int main()
{
   deque<int> q;
   int n, m, x;
   scanf("%d%d%d", &n, &m, &x);
   for (int i = 1; i <= n; ++i)
   {
      for (int j = 1; j <= m; ++j)
      {
         scanf("%d", &ori[i][j]);
      }
   }
   for (int j = 1; j <= n; ++j)
   {
      while (!q.empty())
      {
         q.pop_back();
      }
      for (int i = 1; i <= m; ++i)
      {
         if (!q.empty() && q.front() <= i - x)
         {
            q.pop_front();
         }
         while (!q.empty() && ori[j][q.back()] <= ori[j][i])
         {
            q.pop_back();
         }
         q.push_back(i);
         mx[j][i] = ori[j][q.front()];
      }
      while (!q.empty())
      {
         q.pop_back();
      }
      for (int i = 1; i <= m; ++i)
      {
         if (!q.empty() && q.front() <= i - x)
         {
            q.pop_front();
         }
         while (!q.empty() && ori[j][q.back()] >= ori[j][i])
         {
            q.pop_back();
         }
         q.push_back(i);
         mi[j][i] = ori[j][q.front()];
      }
   }
   for (int j = 1; j <= m; ++j)
   {
      while (!q.empty())
      {
         q.pop_back();
      }
      for (int i = 1; i <= n; ++i)
      {
         if (!q.empty() && q.front() == i - x)
         {
            q.pop_front();
         }
         while (!q.empty() && mx[q.back()][j] <= mx[i][j])
         {
            q.pop_back();
         }
         q.push_back(i);
         mxans[i][j] = mx[q.front()][j];
      }
      while (!q.empty())
      {
         q.pop_back();
      }
      for (int i = 1; i <= n; ++i)
      {
         if (!q.empty() && q.front() == i - x)
         {
            q.pop_front();
         }
         while (!q.empty() && mi[q.back()][j] >= mi[i][j])
         {
            q.pop_back();
         }
         q.push_back(i);
         mians[i][j] = mi[q.front()][j];
      }
   }
   int ans = 0x7fffffff;
   for (int i = x; i <= n; ++i)
   {
      for (int j = x; j <= m; ++j)
      {
         if (mxans[i][j] - mians[i][j] < ans)
         {
            ans = mxans[i][j] - mians[i][j];
         }
      }
   }
   printf("%d", ans);
   return 0;
}
