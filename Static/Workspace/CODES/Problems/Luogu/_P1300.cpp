#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
int cost[35][35][4];
signed char mp[35][35];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
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
struct cas
{
   int x, y;
   int nw;
   cas(int a, int b, int n) : x(a), y(b), nw(n) {}
   bool operator<(const cas &oth) const
   {
      return cost[x][y][nw] > cost[oth.x][oth.y][oth.nw];
   }
};
int main()
{
   int h, w;
   read(h, w);
   char c;
   int i, j;
   memset(cost, 0x3f, sizeof cost);
   priority_queue<cas> q;
   for (i = 1; i <= h; ++i)
   {
      for (j = 1; j <= w; ++j)
      {
         c = getchar();
         if (c == '.')
         {
            mp[i][j] = 0;
         }
         else
         {
            if (c == 'F')
            {
               mp[i][j] = 2;
            }
            else
            {
               mp[i][j] = 1;
               if (c == 'E')
               {
                  cost[i][j][0] = 0;
                  q.push(cas(i, j, 0));
               }
               if (c == 'S')
               {
                  cost[i][j][1] = 0;
                  q.push(cas(i, j, 1));
               }
               if (c == 'W')
               {
                  cost[i][j][2] = 0;
                  q.push(cas(i, j, 2));
               }
               if (c == 'N')
               {
                  cost[i][j][3] = 0;
                  q.push(cas(i, j, 3));
               }
            }
         }
      }
      getchar();
   }
   int x, y, nw;
   while (!q.empty())
   {
      x = q.top().x;
      y = q.top().y;
      nw = q.top().nw;
      if (mp[x][y] == 2)
      {
         printf("%d", cost[x][y][nw]);
         return 0;
      }
      q.pop();
      if (mp[x + dx[nw]][y + dy[nw]] != 0 && cost[x + dx[nw]][y + dy[nw]][nw] > cost[x][y][nw])
      {
         cost[x + dx[nw]][y + dy[nw]][nw] = cost[x][y][nw];
         q.push(cas(x + dx[nw], y + dy[nw], nw));
      }
      if (mp[x + dx[(nw + 1) % 4]][y + dy[(nw + 1) % 4]] != 0 && cost[x + dx[(nw + 1) % 4]][y + dy[(nw + 1) % 4]][(nw + 1) % 4] > cost[x][y][nw] + 5)
      {
         cost[x + dx[(nw + 1) % 4]][y + dy[(nw + 1) % 4]][(nw + 1) % 4] = cost[x][y][nw] + 5;
         q.push(cas(x + dx[(nw + 1) % 4], y + dy[(nw + 1) % 4], (nw + 1) % 4));
      }
      if (mp[x + dx[(nw + 3) % 4]][y + dy[(nw + 3) % 4]] != 0 && cost[x + dx[(nw + 3) % 4]][y + dy[(nw + 3) % 4]][(nw + 3) % 4] > cost[x][y][nw] + 1)
      {
         cost[x + dx[(nw + 3) % 4]][y + dy[(nw + 3) % 4]][(nw + 3) % 4] = cost[x][y][nw] + 1;
         q.push(cas(x + dx[(nw + 3) % 4], y + dy[(nw + 3) % 4], (nw + 3) % 4));
      }
      if (mp[x + dx[nw]][y + dy[nw]] == 0 && mp[x + dx[(nw + 1) % 4]][y + dy[(nw + 1) % 4]] == 0 && mp[x + dx[(nw + 3) % 4]][y + dy[(nw + 3) % 4]] == 0 && cost[x][y][(nw + 2) % 4] > cost[x][y][nw] + 10)
      {
         cost[x][y][(nw + 2) % 4] = cost[x][y][nw] + 10;
         q.push(cas(x, y, (nw + 2) % 4));
      }
   }
}
