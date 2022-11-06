#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 3005
#define MAXM 9005
using namespace std;
int fst[MAXN];
int nt[MAXM];
int to[MAXM];
int v[MAXM];
int weight[MAXN];
int dis[MAXN];
int times[MAXN];
bool used[MAXN];
int n, m;
bool spfa(void)
{
   memset(weight, 0x3f, sizeof weight);
   queue<int> q;
   int u;
   q.push(0);
   used[0] = true;
   times[0] = 0;
   weight[0] = 0;
   int i;
   while (!q.empty())
   {
      u = q.front();
      q.pop();
      for (i = fst[u]; i; i = nt[i])
      {
         if (weight[to[i]] > weight[u] + v[i])
         {
            weight[to[i]] = weight[u] + v[i];
            if (!used[to[i]])
            {
               q.push(to[i]);
               times[to[i]] = times[u] + 1;
               used[to[i]] = true;
               if (times[to[i]] > n)
               {
                  return true;
               }
            }
         }
      }
      used[u] = false;
   }
   return false;
}
class node
{
public:
   int num;
   int d;
   bool operator<(const node &other) const
   {
      return d > other.d;
   }
   node(int x) : num(x), d(dis[x]) {}
};
void dijkstra(int s)
{
   priority_queue<node> q;
   memset(used, 0x00, sizeof used);
   memset(dis, 0x3f, sizeof dis);
   dis[s] = 0;
   int u;
   int i;
   for (i = 1; i <= n; ++i)
   {
      q.push(node(i));
   }
   while (!q.empty())
   {
      u = q.top().num;
      if (q.top().d != dis[u])
      {
         q.pop();
         continue;
      }
      used[u] = true;
      q.pop();
      for (i = fst[u]; i; i = nt[i])
      {
         if (dis[to[i]] > dis[u] + v[i])
         {
            dis[to[i]] = dis[u] + v[i];
         }
         if (!used[to[i]])
         {
            q.push(node(to[i]));
         }
      }
   }
   return;
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("my.txt", "w", stdout);
   freopen("in.txt", "r", stdin);
#endif
   scanf("%d%d", &n, &m);
   int i;
   int a, b, c;
   for (i = 1; i <= m; ++i)
   {
      scanf("%d%d%d", &a, &b, &c);
      if (a == b && c < 0)
      {
         printf("-1");
         return 0;
      }
      to[i] = b;
      v[i] = c;
      nt[i] = fst[a];
      fst[a] = i;
   }
   for (i = m + 1; i <= m + n; ++i)
   {
      to[i] = i - m;
      v[i] = 0;
      nt[i] = fst[0];
      fst[0] = i;
   }
   if (spfa())
   {
      printf("-1");
      return 0;
   }
   int j;
   for (i = 1; i <= n; ++i)
   {
      for (j = fst[i]; j; j = nt[j])
      {
         v[j] += weight[i];
         v[j] -= weight[to[j]];
      }
   }
   long long ans;
   for (i = 1; i <= n; ++i)
   {
      dijkstra(i);

      ans = 0;
      for (j = 1; j <= n; ++j)
      {
         if (dis[j] == 0x3f3f3f3f)
         {
            dis[j] = 1000000000;
         }
         else
         {
            dis[j] += weight[j];
            dis[j] -= weight[i];
         }
         // printf("%d ", dis[j]);
         ans += (long long)dis[j] * j;
      }
      // printf("\n");
      printf("%lld\n", ans);
   }
   return 0;
}
