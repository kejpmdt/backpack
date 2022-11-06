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
long long f[305][305];
struct cow
{
   long long w, a, b;
   bool operator<(const cow &oth) const
   {
      if (b - a != oth.b - oth.a)
         return b - a < oth.b - oth.a;
      else
         return a < oth.a;
   }
} cows[45000];
#include <algorithm>
int main()
{
   long long n, m;
   read(n, m);
   long long i;
   for (i = 1; i <= m; ++i)
   {
      read(cows[i].w, cows[i].a, cows[i].b);
   }
   sort(cows + 1, cows + m + 1);
   long long k;
   long long ans = 0;
   long long j;
   long long nw = 1;
   for (i = 1; i <= n; ++i)
   {
      for (j = 1; j + i - 1 <= n; ++j)
      {
         for (k = j + 1; k < j + i; ++k)
         {
            f[j][j + i - 1] = mx2(f[j][j + i - 1], f[j][k - 1] + f[k][j + i - 1]);
         }
         if (cows[nw].a == j && cows[nw].b == j + i - 1)
         {
            f[j][j + i - 1] = mx2(f[j][j + i - 1], cows[nw].w);
            for (k = j + 1; k < j + i - 1; ++k)
            {
               f[j][j + i - 1] = mx2(f[j][j + i - 1], f[j][k - 1] + f[k + 1][j + i - 1] + cows[nw].w);
            }
            if (i != 1)
            {
               f[j][j + i - 1] = mx2(f[j][j + i - 1], f[j][j + i - 2] + cows[nw].w);
               f[j][j + i - 1] = mx2(f[j][j + i - 1], f[j + 1][j + i - 1] + cows[nw].w);
            }
            ++nw;
         }
         ans = mx2(ans, f[j][j + i - 1]);
      }
   }
   printf("%lld", ans);
   return 0;
}