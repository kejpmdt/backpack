#include <cstdio>
#define MAXN 100005
#define MAXM 500005
using namespace std;
int dis[MAXN];
int fst[MAXN], nt[MAXM], to[MAXM], v[MAXM];
bool used[MAXN];
int n;
int simplegetnw(void)
{
   int ans = 0;
   for (int i = 1; i <= n; ++i)
   {
      if (used[i])
      {
         continue;
      }
      if (dis[i] < dis[ans] || ans == 0)
      {
         ans = i;
      }
   }
   return ans;
}
void Dijkstra(void)
{
   int k, i, u;
   for (int k = 1; k <= n; ++k)
   {
      u = simplegetnw();
      used[u] = true;
      for (i = fst[u]; i; i = nt[i])
      {
         if (used[to[i]])
         {
            continue;
         }
         if (dis[to[i]] < dis[u] + v[i])
         {
            continue;
         }
         dis[to[i]] = dis[u] + v[i];
      }
   }
}
int main()
{
   int s, m, i;
   scanf("%d%d%d", &n, &m, &s);
   for (i = 0; i <= n; ++i)
      dis[i] = 0x7fffffff;
   int u, w;
   for (i = 1; i <= m; ++i)
   {
      scanf("%d%d%d", &u, &w, &v[i]);
      to[i] = w;
      nt[i] = fst[u];
      fst[u] = i;
   }
   dis[s] = 0;
   Dijkstra();
   for (i = 1; i <= n; ++i)
   {
      printf("%d ", dis[i]);
   }
   return 0;
}