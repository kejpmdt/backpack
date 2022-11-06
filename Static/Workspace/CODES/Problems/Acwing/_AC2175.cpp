#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 105
#define MAXM 105
using namespace std;
#define mi2(a, b) (a < b ? a : b)
template <class T>
void read(T &ans)
{
   ans = 0;
   bool f = false;
   char us = getchar();
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
signed int s, t;
template <class T, class... Oth>
void read(T &x, Oth &...a)
{
   read(x);
   read(a...);
}
template <class T>
void put(T x)
{
   if (x < 0)
   {
      return putchar(45), put(-x);
   }
   else
   {
      putchar(x > 9 ? put(x / 10), x % 10 | 48 : x % 10 | 48);
   }
}
template <class T, class... O>
void put(char j, T x, O... oth)
{
   put(x);
   putchar(j);
   put(oth...);
}
signed int fst[MAXN], to[MAXM], nt[MAXM], deep[MAXN], cur[MAXN];
bool v[MAXM];
void addline(signed int i, signed int a, signed int b)
{
   to[i] = b;
   to[i ^ 1] = a;
   nt[i] = fst[a];
   nt[i ^ 1] = fst[b];
   fst[a] = i;
   fst[b] = i ^ 1;
   v[i] = 1;
   v[i ^ 1] = 0;
}
bool bfs()
{
   queue<signed int> q;
   q.push(s);
   memset(deep, 0x00, sizeof deep);
   deep[s] = 1;
   signed int u, i;
   cur[s] = fst[s];
   while (!q.empty())
   {
      u = q.front();
      q.pop();
      for (i = fst[u]; i; i = nt[i])
      {
         if (deep[to[i]] == 0 && v[i])
         {
            deep[to[i]] = deep[u] + 1;
            if (to[i] == t)
            {
               return true;
            }
            q.push(to[i]);
            cur[to[i]] = fst[to[i]];
         }
      }
   }
   return false;
}
signed int find(signed int nw, signed int li)
{
   if (nw == t)
   {
      return li;
   }
   if (li == 0)
   {
      return 0;
   }
   signed int ans = 0;
   signed int u;
   for (signed int i = cur[nw]; i; i = nt[i])
   {
      cur[nw] = i;
      if (deep[to[i]] == deep[nw] + 1 && v[i])
      {
         u = find(to[i], mi2(li - ans, v[i]));
         if (u)
         {
            ans += u;
            v[i] -= u;
            v[i ^ 1] += u;
         }
         else
         {
            deep[to[i] = 0];
         }
      }
   }
   return ans;
}
signed int dinic()
{
   signed int ans = 0;
   signed int u;
   while (bfs())
   {
      do
      {
         u = find(s, 20);
         ans += u;
      } while (u);
   }
   return ans;
}
int main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
   #endif
   memset(fst, 0x00, sizeof fst);
   signed int n, m;
   read(m, n);
   s = 0;
   t = n + 1;
   signed int i = 1;
   signed int a, b;
   read(a, b);
   while(a-b)
   {
      addline(i++, a, b);
      read(a, b);
   }
   signed int j;
   for (j = 1; j <= m; ++j)
   {
      addline(i++, 0, j);
   }
   for (; j <= n; ++j)
   {
      addline(i++, j, n + 1);
   }
   put(dinic());
   putchar(10);
   for (i = m + 1; i <= n; ++i)
   {
      for (j = fst[i]; j; j = nt[j])
      {
         if (v[j] && to[j] != n + 1)
         {
            put(32, i, to[j]);
            putchar('\n');
            break;
         }
      }
   }
   return 0;
}
