#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define mi2(a, b) (a < b ? a : b)
#ifndef ONLINE_JUDGE
#define MAXN 10
#define MAXM 20
#else
#define MAXN 5005
#define MAXM 100005
#endif
using namespace std;
signed int fst[MAXN], nt[MAXM], lst[MAXN];
signed short to[MAXM];
signed char v[MAXM], w[MAXM];
signed int dis[MAXN];
signed char mi[MAXN];
bool inq[MAXN];
signed short n, S, T;
signed int m;
template <class T>
inline void read(T &ans)
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
template <class T, class... Oth>
void read(T &x, Oth &...o)
{
   read(x);
   read(o...);
}
void addline(int i, signed short a, signed short b, signed char c, signed char d)
{
   to[i] = b;
   to[i ^ 1] = a;
   nt[i] = fst[a];
   nt[i ^ 1] = fst[b];
   fst[a] = i;
   fst[b] = i ^ 1;
   v[i] = d;
   v[i ^ 1] = -d;
   w[i] = c;
   w[i ^ 1] = 0;
}
bool spfa()
{
   queue<signed short> q;
   signed short u;
   signed int i;
   q.push(S);
   inq[S] = true;
   memset(dis, 0x3f, sizeof dis);
   memset(mi, 0x00, sizeof mi);
   dis[S] = 0;
   mi[S] = 127;
   while (!q.empty())
   {
      u = q.front();
      q.pop();
      for (i = fst[u]; i; i = nt[i])
      {
         if (dis[to[i]] > dis[u] + v[i] && w[i] > 0)
         {
            lst[to[i]] = i;
            dis[to[i]] = dis[u] + v[i];
            mi[to[i]] = mi2(mi[u], w[i]);
            if (!inq[to[i]])
            {
               q.push(to[i]);
               inq[to[i]] = true;
            }
         }
      }
      inq[u] = false;
   }
   return dis[T] != 0x3f3f3f3f;
}
void EK(int &cost, int &flow)
{
   cost = 0;
   flow = 0;
   while (spfa())
   {
      cost += dis[T] * mi[T];
      flow += mi[T];
      for (int i = T; i != S; i = to[lst[i] ^ 1])
      {
         w[lst[i]] -= mi[T];
         w[lst[i] ^ 1] += mi[T];
      }
   }
   return;
}
int main()
{
   read(n, m, S, T);
   signed short a, b;
   signed char c, d;
   for (int i = 1; i <= m; ++i)
   {
      read(a, b, c, d);
      addline(i << 1, a, b, c, d);
   }
   int flow, cost;
   EK(cost, flow);
   printf("%d %d", flow, cost);
   return 0;
}