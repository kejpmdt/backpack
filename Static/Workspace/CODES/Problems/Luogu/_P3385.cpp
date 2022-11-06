#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 2005
#define MAXM 6005
using namespace std;
int fst[MAXN], nt[MAXM];
int to[MAXM];
int v[MAXM];
int dis[MAXN], length[MAXN];
void addline(int a, int b, int c, int &i)
{

   ++i;
   to[i] = b;
   nt[i] = fst[a];
   fst[a] = i;
   v[i] = c;
   if (c > 0)
   {
      ++i;
      to[i] = a;
      nt[i] = fst[b];
      fst[b] = i;
      v[i] = c;
   }
}
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
int n;
bool pd;
void spfa(int nw)
{
   int i;
   if (length[nw] > n + 10)
   {
      pd = true;
      return;
   }
   for (i = fst[nw]; i; i = nt[i])
   {
      if (dis[to[i]] > dis[nw] + v[i])
      {
         dis[to[i]] = dis[nw] + v[i];
         length[to[i]] = length[nw] + 1;
         spfa(to[i]);
         if (pd)
         {
            return;
         }
      }
   }
}
int main()
{
   int t;
   read(t);
   int m;
   int a, b, c;
   int nw;
   while (t--)
   {
      nw = 0;
      memset(fst, 0x00, sizeof fst);
      memset(dis, 0x3f, sizeof dis);
      memset(length, 0x00, sizeof length);
      memset(to, 0x00, sizeof to);
      memset(v, 0x00, sizeof v);
      dis[1] = 0;
      read(n);
      read(m);
      while (m--)
      {
         read(a, b, c);
         addline(a, b, c, nw);
      }
      pd = false;
      spfa(1);
      if (pd)
      {
         printf("YES\n");
      }
      else
      {
         printf("NO\n");
      }
   }
}
