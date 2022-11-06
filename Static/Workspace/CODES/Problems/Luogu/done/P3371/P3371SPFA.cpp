#include <cstdio>
#include <queue>
using namespace std;
int fst[10005], nt[500005], to[500005], value[500005];
int dis[10005];
bool inq[10005];
queue<int> q;
int main()
{
   int n, m, s;
   scanf("%d%d%d", &n, &m, &s);
   int u, v, w;
   int i;
   for (i = 1; i <= n; ++i)
   {
      dis[i] = 0x7fffffff;
   }
   for (i = 1; i <= m; ++i)
   {
      scanf("%d%d%d", &u, &v, &w);
      to[i] = v;
      nt[i] = fst[u];
      fst[u] = i;
      value[i] = w;
   }
   dis[s]=0;
   q.push(s);
   inq[s] = true;
   while (!q.empty())
   {
      u = q.front();
      for (i = fst[u]; i; i = nt[i])
      {
         if (dis[u] + value[i] < dis[to[i]])
         {
            dis[to[i]] = dis[u] + value[i];
            if (!inq[to[i]])
            {
               q.push(to[i]);
               inq[to[i]] = true;
            }
         }
      }
      q.pop();
      inq[u]=false;
   }
   for (i = 1; i <= n; ++i)
   {
      printf("%d ", dis[i]);
   }
   return 0;
}
