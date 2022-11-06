#include <cstdio>
#include <queue>
#define MAXN 100005
#define MAXM 500005
using namespace std;
long long dis[MAXN];
int fst[MAXN], nt[MAXM], to[MAXM], v[MAXM];
bool used[MAXN];
int n;
struct node
{
   int num;
   int d;
   bool operator<(const node &other) const
   {
      return dis[num] > dis[other.num];
   }
   node(int n) : num(n), d(dis[n]) {}
};
priority_queue<node> q;
void Dijkstra(void)
{
   int k, i, u;
   while (!q.empty())
   {
      u = q.top().num;
      q.pop();
      if (used[u])
      {
         continue;
      }
      used[u] = true;
      for (i = fst[u]; i; i = nt[i])
      {
         if (dis[to[i]] > dis[u] + v[i])
         {
            dis[to[i]] = dis[u] + v[i];
            q.push(node(to[i]));
            used[to[i]] = false;
         }
      }
   }
}
int main()
{
   int s, m, i;
   scanf("%d%d%d", &n, &m, &s);
   for (i = 0; i <= n; ++i)
   {
      dis[i] = 0x7fffffff;
   }
   int u, w;
   for (i = 1; i <= m; ++i)
   {
      scanf("%d%d%d", &u, &w, &v[i]);
      to[i] = w;
      nt[i] = fst[u];
      fst[u] = i;
   }
   dis[s] = 0;
   q.push(node(s));
   Dijkstra();
   for (i = 1; i <= n; ++i)
   {
      printf("%lld ", dis[i]);
   }
   return 0;
}