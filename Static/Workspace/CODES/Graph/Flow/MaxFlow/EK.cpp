#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#define MAXN 1005
#define MAXM 20050
using namespace std;
#define mi2(a, b) (a < b ? a : b)
#define INF 0x3f3f3f3f
int n, m, s, t;
int fst[MAXN], nt[MAXM], v[MAXM], to[MAXM];
int mi[MAXN], pre[MAXN];
bool used[MAXN];
void addline(int i, int a, int b, int c)
{
   to[i] = b;
   to[i ^ 1] = a;
   nt[i] = fst[a];
   nt[i ^ 1] = fst[b];
   fst[a] = i;
   fst[b] = i ^ 1;
   v[i] = c;
   v[i ^ 1] = 0;
}
queue<int> q;
bool bfs()
{
   while (!q.empty())
   {
      q.pop();
   }
   memset(used, 0x00, sizeof used);
   memset(mi, 0x00, sizeof mi);
   q.push(s);
   used[s] = true;
   mi[s] = INF;
   pre[s] = 0;
   int u, i;
   while (!q.empty())
   {
      u = q.front();
      q.pop();
      for (i = fst[u]; i; i = nt[i])
      {
         if (!used[to[i]] && v[i] > 0)
         {
            used[to[i]] = true;
            mi[to[i]] = mi2(mi[u], v[i]);
            pre[to[i]] = i;
            if (to[i] == t)
            {
               return true;
            }
            q.push(to[i]);
         }
      }
   }
   return false;
}
int EK()
{
   int r = 0;
   int i;
   while (bfs())
   {
      r += mi[t];
      for (i = t; i != s; i = to[pre[i] ^ 1])
      {
         v[pre[i]] -= mi[t];
         v[pre[i] ^ 1] += mi[t];
      }
   }
   return r;
}
int main()
{
   scanf("%d%d%d%d", &n, &m, &s, &t);
   int i;
   int a, b, c;
   for (i = 1; i <= m; ++i)
   {
      scanf("%d%d%d", &a, &b, &c);
      addline(i << 1, a, b, c);
   }
   printf("%d\n", EK());
   return 0;
}
