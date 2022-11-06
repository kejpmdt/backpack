#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
   double x, y;
   bool operator<(const node &oth) const
   {
      if (x != oth.x)
      {
         return x < oth.x;
      }
      else
      {
         return y < oth.y;
      }
   }
} nodes[10005];
int q[20005];
int main()
{
   int n;
   scanf("%d", &n);
   for (int i = 1; i <= n; ++i)
   {
      scanf("%lf%lf", &nodes[i].x, &nodes[i].y);
   }
   sort(nodes + 1, nodes + n + 1);
   int tt = 0;
   q[0] = 1;
   for (int i = 1; i <= n; ++i)
   {
      while (tt > 0 && (nodes[q[tt]].y - nodes[q[tt - 1]].y) * (nodes[i].x - nodes[q[tt - 1]].x) <= (nodes[i].y - nodes[q[tt - 1]].y) * (nodes[q[tt]].x - nodes[q[tt - 1]].x))
      {
         --tt;
      }
      q[++tt] = i;
   }