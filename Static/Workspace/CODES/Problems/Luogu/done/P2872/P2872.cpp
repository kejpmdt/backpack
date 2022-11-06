#include <cstdio>
#include <queue>
#include <cmath>
#define MAXN 2005
using namespace std;
int fa[MAXN];
int getfa(int nw)
{
   if (fa[fa[nw]] != fa[nw])
   {
      fa[nw] = getfa(fa[nw]);
   }
   return fa[nw];
}
struct line
{
   int frm;
   int to;
   double l;
   line(int x, int y, int a, int b, int c, int d)
   {
      frm = x;
      to = y;
      l = pow((double)(a - c) * (a - c) + (b - d) * (b - d), 0.5);
   }
   bool operator<(const line &o) const
   {
      return l > o.l;
   }
};
int xs[MAXN], ys[MAXN];
int main()
{
   int n, m;
   scanf("%d%d", &n, &m);
   for (int i = 1; i <= n; ++i)
   {
      scanf("%d%d", &xs[i], &ys[i]);
   }
   priority_queue<line> q;
   int a, b;
   for (int i = 1; i <= n; ++i)
   {
      fa[i] = i;
   }
   for (int i = 1; i <= m; ++i)
   {
      scanf("%d%d", &a, &b);
      fa[getfa(a)] = getfa(b);
   }
   for (int i = 1; i <= n; ++i)
   {
      for (int j = i + 1; j <= n; ++j)
      {
         q.push(line(i, j, xs[i], ys[i], xs[j], ys[j]));
      }
   }
   double ans = 0;
   while (!q.empty())
   {
      while (!q.empty() && getfa(q.top().frm) == getfa(q.top().to))
      {
         q.pop();
      }
      if (q.empty())
      {
         break;
      }
      ans += q.top().l;
      fa[getfa(q.top().frm)] = getfa(q.top().to);
   }
   printf("%.2lf", ans);
   return 0;
}
