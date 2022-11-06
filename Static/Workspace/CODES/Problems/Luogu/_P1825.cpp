#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
unsigned char mp[305][305];
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
int tox[305][305];
int toy[305][305];
int ntx[100], nty[100];
int main()
{
   int n, m;
   read(n, m);
   int i, j;
   deque<int> xs;
   deque<int> ys;
   for (i = 1; i <= n; ++i)
   {
      for (j = 1; j <= m; ++j)
      {
         mp[i][j] = getchar();
         if (mp[i][j] > 64 && mp[i][j] < 91)
         {
            if (ntx[mp[i][j]] != 0)
            {
               tox[i][j] = ntx[mp[i][j]];
               toy[i][j] = nty[mp[i][j]];
               tox[ntx[mp[i][j]]][nty[mp[i][j]]] = i;
               toy[ntx[mp[i][j]]][nty[mp[i][j]]] = j;
            }
            else
            {
               ntx[mp[i][j]] = i;
               nty[mp[i][j]] = j;
            }
         }
         else
         {
            tox[i][j] = i;
            toy[i][j] = j;
         }
         if(mp[i][j]==61){

      }
      getchar();
   }
   }
