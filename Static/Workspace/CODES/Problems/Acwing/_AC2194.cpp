#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define MAXN 60
#define MAXM 13000
#define mi2(a, b) (a < b ? a : b)
#define mx2(a, b) (a > b ? a : b)
template <class T>
void read(T &ans)
{
   ans = 0;
   char us = getchar();
   bool f = false;
   while (us < 48 || us > 57)
   {
      f |= (us == 45);
      us = getchar();
   }
   while (us > 47 && us < 58)
   {
      ans = (ans << 1) + (ans << 3) + (us ^ 48);
      us = getchar();
   }
   ans *= f ? -1 : 1;
   return;
}
template <class T, class... O>
void read(T &x, O &...oth)
{
   read(x);
   read(oth...);
}
int fst[MAXN], nt[MAXM], to[MAXM], v[MAXM];
int w[MAXM];
int dis[MAXN], mi[MAXN];
int lst[MAXN];
bool inq[MAXN];
int S, T;
void addline(int i, int a, int b, int cost, int flow)
{
   to[i] = b;
   to[i ^ 1] = a;
   nt[i] = fst[a];
   nt[i ^ 1] = fst[b];
   fst[a] = i;
   fst[b] = i ^ 1;
   v[i] = cost;
   v[i ^ 1] = -cost;
   w[i] = flow;
   w[i ^ 1] = 0;
}
bool spfa()
{
   int u, i;
   memset(dis, 0x3f, sizeof dis);
   memset(mi, 0x00, sizeof mi);
   queue<int> q;
   q.push(S);
   inq[S] = true;
   dis[S] = 0;
   mi[S] = 0x3f3f3f3f;
   while (!q.empty())
   {
      u = q.front();
      q.pop();
      for (i = fst[u]; i; i = nt[i])
      {
         if (w[i] && dis[to[i]] > dis[u] + v[i])
         {
            dis[to[i]] = dis[u] + v[i];
            lst[to[i]] = i;
            if (!inq[to[i]])
            {
               q.push(to[i]);
               inq[to[i]] = true;
            }
         }
      }
      inq[u] = false;
   }
   return mi[T];
}
int EK()
{
   int cost = 0;
   int i;
   while (spfa())
   {
      cost += mi[T] * dis[T];
      for (i = T; i != S; i = to[lst[i] ^ 1])
      {
         w[lst[i]] -= mi[T];
         w[lst[i] ^ 1] += mi[T];
      }
   }
   return cost;
}
int main()
{
   int n, m;
   read(m, n);
   int i, j,u;
   int nw = 1;
   for (i = 1; i <= m; ++i)
   {
      read(u);
      addline((nw++) << 1, 0, i, 0, u);
   }
   for (; i <= m + n; ++i)
   {
      read(u);
      addline((nw++) << 1, i - m, m + n + 1, 0, u);
   }
   for(i=1;i<=m;++i){
      for(j=1;j<=n;++j){
         read(u);
         addline((nw++)<<1,i,m+j,u,0x3f3f3f3f);
      }
   }
   int mincost = EK();
   for (i = 1; i < nw; ++i)
   {
      w[i << 1] += w[i << 1 | 1];
      v[i << 1] = v[i << 1 | 1];
      w[i << 1 | 1] = 0;
      v[i << 1 | 1] = -v[i << 1];
   }
   int maxcost = -EK();
   printf("%d\n%d", mincost, maxcost);
   return 0;
}