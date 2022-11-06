#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 3005
#define MAXM 10005
using namespace std;
int fst[MAXN], nt[MAXM], to[MAXM], value[MAXM];
int dis[MAXN];
int times[MAXN];
bool inq[MAXN];
queue<int> spfaq;
int n, m;
bool SPFA(void)
{
   memset(times, 0x00, sizeof(times));
   int u, i;
   while (!spfaq.empty())
   {
      u = spfaq.front();
      for (i = fst[u]; i; i = nt[i])
      {
         if (dis[u] + value[i] < dis[to[i]])
         {
            dis[to[i]] = dis[u] + value[i];
            if (!inq[to[i]])
            {
               spfaq.push(to[i]);
               ++times[to[i]];
               if (times[to[i]] > n)
               {
                  return true;
               }
               inq[to[i]] = true;
            }
         }
      }
      spfaq.pop();
      inq[u] = false;
   }
   return false;
}
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
priority_queue<node> dijkstraq;
bool used[MAXN];

void Dijkstra(void)
{
   int i, u;
   while (!dijkstraq.empty())
   {
      u = dijkstraq.top().num;
      dijkstraq.pop();
      if (used[u])
      {  
         continue;
      }
      used[u] = true;
      for (i = fst[u]; i; i = nt[i])
      {
         if (dis[to[i]] > dis[u] + value[i])
         {
            dis[to[i]] = dis[u] + value[i];
            dijkstraq.push(node(to[i]));
            used[to[i]] = false;
         }
      }
   }
}
void Johnson(void)
{
   int i, j;
   for (i = m + 1; i <= m + n; ++i)
   {
      to[i] = i - m;
      nt[i] = fst[0];
      fst[0] = i;
      value[i] = 0;
   }
   dis[0] = 0;
   spfaq.push(0);
   inq[0] = true;
   if (SPFA())
   {
      printf("-1");
      return;
   }
   for (i = 1; i <= n; ++i)
   {
      for (j = fst[i]; j; j = nt[j])
      {
         value[j] += dis[i] -= dis[to[j]];
      }
   }
   long long ans;
   for (i = 1; i <= n; ++i)
   {
      memset(dis, 0x3f, sizeof dis);
      dis[i] = 0;
      dijkstraq.push(node(i));
      Dijkstra();
      ans = 0;
      for (j = 1; j <= n; ++j)
      {
         if (dis[j] != 0x3f3f3f3f)
         {
            ans += dis[j];
         }
         else
         {
            ans += 1000000000;
         }
      }
      printf("%lld\n", ans);
   }
}
int main()
{
   scanf("%d%d", &n, &m);
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
   Johnson();
   return 0;
}
