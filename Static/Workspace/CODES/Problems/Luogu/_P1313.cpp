#include <cstdio>
#define mod 10007
using namespace std;
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
long long yh[1005][1005];
int main()
{
   int a, b, k, n, m;
   read(a, b, k, n, m);
   int i, j;
   yh[1][1] = 1;
   for (i = 1; i <= n + 1; ++i)
   {
      for (j = 1; j <= m + 1; ++j)
      {
         yh[i][j] += (yh[i - 1][j] * a + yh[i][j - 1] * b) % mod;
      }
   }
   printf("%d", yh[n + 1][m + 1]);
}