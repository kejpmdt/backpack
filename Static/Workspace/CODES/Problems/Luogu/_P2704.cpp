#include <cstdio>
#define mi2(a, b) (a < b ? a : b)
#define mx2(a, b) (a > b ? a : b)
using namespace std;
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
bool f[1024][1024][2];
int main()
{
   int n, m;
   int zt;
   read(n, m);
   for (int i = 0; i < (1 << m); ++i)
   {
      for (int j = 0; j < (1 << m); ++j)
      {
         f[i][j][1] = 1;
      }
   }
   int lzt1 = 0, lzt2 = 0;
   zt = 0;
   for (int i = 1; i <= n; ++i)
   {
      lzt2 = lzt1;
      lzt1 = zt;
      zt = 0;
      for (int j = 1; j <= m; ++j)
      {
         zt <<= 1;
         if (getchar() == 'H')
         {
            zt |= 1;
         }
      }
      getchar();
      for (int t = 0; t < (1 << m); ++t)
      {
         if (((t & zt) != 0) || ((t & (t << 1)) != 0) || ((t & (t << 2)) != 0))
         {
            continue;
         }
         for (int j = 0; j < (1 << m); ++j)
         {
            if (((j & lzt1) != 0) || ((j & (j << 1)) != 0) || ((j & (j << 2)) != 0) || ((t & j) != 0))
            {
               continue;
            }
            for (int k = 0; k < (1 << m); ++k)
            {
               if (f[j][k][0])
               {
                  break;
               }
               if (((k & lzt2) != 0) || ((k & (k << 1)) != 0) || ((k & (k << 2)) != 0))
               {
                  continue;
               }
               if (((t & k) == 0) && ((j & k) == 0))
               {
                  f[i][j][0] |= f[j][k][1];
               }
            }
         }
      }
      for (int j = 0; j < (1 << m); ++j)
      {
         for (int k = 0; k < (1 << m); ++k)
         {
            f[j][k][1] = f[j][k][0];
            f[j][k][0] = 0;
         }
      }
   }
   int ans = 0;
   for (int j = 0; j < (1 << m); ++j)
   {
      for (int k = 0; k < (1 << m); ++k)
      {
         ans += f[j][k][1];
      }
   }
   printf("%d", ans);
}