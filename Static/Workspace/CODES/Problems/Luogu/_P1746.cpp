#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 1005
#define abs(x) (x > 0 ? x : -(x))
using namespace std;
short tx, ty;
short dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
struct stable
{
   short x, y;
   short dis;
   short g;
   bool operator<(const stable &other) const
   {
      return g > other.g;
   }
   stable(short a, short b, short d) : x(a), y(b), dis(d)
   {
      g = dis + abs(tx - a) + abs(ty - b);
   }
   stable(void){}
};
short mp[MAXN][MAXN];
short frm[MAXN][MAXN];
inline short read(void)
{
   short ans = 0;
   char us = getchar();
   while (us < '0' || us > '9')
   {
      us = getchar();
   }
   while (us >= '0' && us <= '9')
   {
      ans = (ans << 1) + (ans << 3) + (us ^ 48);
      us = getchar();
   }
   return ans;
}
int main()
{
   priority_queue<stable> q;
   short n;
   n = read();
   short i, j;
   for (i = 0; i <= n + 1; ++i)
   {
      mp[i][0] = mp[i][n + 1] = mp[0][i] = mp[n + 1][i] = 1;
   }
   for (i = 1; i <= n; ++i)
   {
      for (j = 1; j <= n; ++j)
      {
         mp[i][j] = getchar() ^ 48;
      }
      getchar();
   }
   i = read();
   j = read();
   tx = read();
   ty = read();
   q.push(stable(i, j, 0));
   stable u;
   while (!q.empty())
   {
      u = q.top();
      q.pop();
      if (u.x == tx && u.y == ty)
      {
         printf("%d", u.dis);
         return 0;
      }
      for (i = 0; i < 4; ++i)
      {
         q.push(stable(u.x+dx[i], u.y+dy[i],u.dis+1));
      }
   }
   return 0;
}