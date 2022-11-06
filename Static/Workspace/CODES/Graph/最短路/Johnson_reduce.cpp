#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
template <class T>
inline T read(void)
{
   T ans = 0;
   char us = getchar();
   bool f = false;
   while (us < '0' || us > '9')
   {
      f |= (us == '-');
      us = getchar();
   }
   while (us >= '0' && us <= '9')
   {
      ans = (ans << 1) + (ans << 3) + (us ^ 48);
      us = getchar();
   }
   return f ? -ans : ans;
}
class Graph
{
private:
   const int MAX_N;
   const int MAX_M;

public:
   int n;
   int m;
   Graph(int inpn, int inpm, int ntime, int mtime) : MAX_N(inpn * ntime + 5), MAX_M(inpm * mtime + 5)
   {
      n = inpn;
      m = inpm;
      // nodes = new node[MAX_N];
      fst = new int[MAX_N];
      nt = new int[MAX_M];
      to = new int[MAX_M];
      v = new int[MAX_M];
      memset(fst, 0x00, MAX_N * sizeof *fst);
      memset(nt, 0x00, MAX_N * sizeof *nt);
      memset(to, 0x00, MAX_N * sizeof *to);
      memset(v, 0x00, MAX_N * sizeof *v);
   }
   void show(int *x)
   {
      for (int i = 0; i <= n; ++i)
      {
         printf("%d ", x[i]);
      }
      for (int i = 0; i <= n; ++i)
      {
         printf("\n%d---\n", i);
         for (int j = fst[i]; j; j = nt[j])
         {
            printf("--%d %d %d (%d->%d)\n", i, to[j], v[j], j, nt[j]);
         }
      }
   }
   void Johnson(void)
   {
      int *weight;
      int *dis;
      weight = new int[MAX_N];
      dis = new int[MAX_N];
      int i, j;
      for (i = 1; i <= n; ++i)
      {
         addline(m + i, 0, i, 0);
      }
      // show(weight);
      if (!SPFA(0, weight))
      {
         printf("-1");
         return;
      }
      // show(weight);
      long long ans;
      for (i = 1; i <= n; ++i)
      {
         for (j = fst[i]; j; j = nt[j])
         {
            v[j] += weight[i];
            v[j] -= weight[to[j]];
         }
      }
      for (i = 1; i <= n; ++i)
      {
         ans = 0;
         Dijkstra(i, dis);
         // show(dis);
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
            //printf("%d ", dis[j]);
         }
         //printf("\n");
         for (j = 1; j <= n; ++j)
         {
            ans += (long long)j * dis[j];
         }
         printf("%lld\n", ans);
      }
   }
   void Dijkstra(int s, int *dis)
   {
      priority_queue<node> q;
      int i;
      memset(dis, 0x3f, MAX_N * sizeof *dis);
      int *used;
      used = new int[MAX_N];
      memset(used, 0x00, MAX_N * sizeof *used);
      dis[s] = 0;
      for (int i = 1; i <= n; ++i)
      {
         q.push(node(i, dis));
      }
      int u;
      while (!q.empty())
      {
         u = q.top().num;
         if (dis[u] != q.top().d)
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
               q.push(node(to[i], dis));
            }
         }
      }
      delete used;
      return;
   }
   bool SPFA(int s, int *dis)
   {
      queue<int> q;
      bool *inqueue;
      int *times;
      inqueue = new bool[MAX_N];
      times = new int[MAX_N];
      int i;
      memset(inqueue, 0x00, MAX_N * sizeof *inqueue);
      memset(dis, 0x3f, MAX_N * sizeof *dis);
      memset(times, 0x00, MAX_N * sizeof *times);
      dis[s] = 0;
      q.push(s);
      inqueue[s] = true;
      times[s] = 1;
      while (!q.empty())
      {
         for (i = fst[q.front()]; i; i = nt[i])
         {
            if (dis[to[i]] > dis[q.front()] + v[i])
            {
               dis[to[i]] = dis[q.front()] + v[i];
               if (!inqueue[to[i]])
               {
                  q.push(to[i]);
                  ++times[to[i]];
                  if (times[to[i]] > n + 5)
                  {
                     delete inqueue;
                     delete times;
                     return false;
                  }
               }
            }
         }
         q.pop();
      }
      delete inqueue;
      delete times;
      return true;
   }
   void init(int m);
   void addline(int i, int u, int t, int w = 1)
   {
      to[i] = t;
      nt[i] = fst[u];
      fst[u] = i;
      v[i] = w;
   }
   int *fst;
   int *nt;
   int *to;
   int *v;
   class node
   {
   public:
      int num;
      int d;
      bool operator<(const node &other) const
      {
         return d > other.d;
      }
      node(int n, int *dis) : num(n), d(dis[n]) {}
      node(void);
   } * nodes;
};
void Graph::init(int g)
{
   int u, v, w;
   for (int i = 1; i <= g; ++i)
   {
      u = read<int>();
      v = read<int>();
      w = read<int>();
      if (u == v)
      {
         if (w < 0)
         {
            printf("-1");
            exit(0);
         }
         else
         {
            --m;
            --g;
            continue;
         }
      }

      addline(i, u, v, w);
   }
}
void printline(Graph *g)
{
   for (int i = 0; i <= g->n; ++i)
   {
      for (int j = g->fst[i]; j; j = g->nt[j])
      {
         printf("%d %d %d\n", i, g->to[j], g->v[i]);
      }
   }
   printf("\n\n");
}
int main()
{
#ifndef ONLINE_JUDGE
//   freopen("my.txt", "w", stdout);
//   freopen("in.txt", "r", stdin);
#endif
   int n, m;
   n = read<int>();
   m = read<int>();
   Graph mp(n, m, 2, 2);
   mp.init(m);
   mp.Johnson();
   return 0;
}