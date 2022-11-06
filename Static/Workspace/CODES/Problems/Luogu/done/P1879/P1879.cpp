#include <cstdio>
template <typename T>
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
template <typename T, typename... O>
void read(T &x, O &...oth)
{
   read(x);
   read(oth...);
}
using namespace std;
int f[13][4096];
int mp[13][13];
int zt[13];
int main()
{
   int n, m;
   read(m, n);
   for (int i = 1; i <= m; ++i)
   {
      for (int j = 1; j <= n; ++j)
      {
         read(mp[i][j]);
         mp[i][j] = 1 - mp[i][j];
         zt[i] <<= 1;
         zt[i] |= mp[i][j];
      }
   }
   for (int i = 0; i < (1 << n); ++i)
   {
      if (i & (i << 1))
      {
         continue;
      }
      if ((i & zt[1]) == 0)
      {
         f[1][i] = 1;
      }
   }
   for (int i = 2; i <= m; ++i)
   {
      for (int j = 0; j < (1 << n); ++j)
      {
         if ((j & (j << 1)) || (j & zt[i]))
         {
            continue;
         }
         for (int k = 0; k < (1 << n); ++k)
         {
            if ((j & k) == 0)
            {
               f[i][j] += f[i - 1][k];
               f[i][j] %= 100000000;
            }
         }
      }
   }
   int ans = 0;
   for (int k = 0; k < (1 << n); ++k)
   {
      ans += f[m][k];
      ans %= 100000000;
   }
   printf("%d", ans);
   return 0;
}
