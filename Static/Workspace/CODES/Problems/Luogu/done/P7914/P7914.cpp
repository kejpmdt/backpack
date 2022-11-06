#include <iostream>
#include <cstdio>
#define mi2(a, b) (a < b ? a : b)
#define mx2(a, b) (a > b ? a : b)
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
#define mod 1000000007
long long dp[505][505][6];
char s[505];
int main()
{
   int n, k;
   read(n, k);
   int l, r, i;
   for (l = 1; l <= n; ++l)
   {
      s[l] = getchar();
      dp[l][l - 1][0] = 1;
   }
   int len;
   for (len = 1; len <= n; ++len)
   {
      for (l = 1; l + len - 1 <= n; ++l)
      {
         r = l + len - 1;
         if (len <= k)
         {
            dp[l][r][0] = dp[l][r - 1][0] && (s[r] == '?' || s[r] == '*');
         }
         if (len >= 2)
         {
            if ((s[l] == '(' || s[l] == '?') && (s[r] == ')' || s[r] == '?'))
            {
               dp[l][r][1] = (dp[l + 1][r - 1][0] + dp[l + 1][r - 1][2] + dp[l + 1][r - 1][3] + dp[l + 1][r - 1][4]) % mod;
            }
            for (i = l; i < r; ++i)
            {
               dp[l][r][2] = (dp[l][r][2] + dp[l][i][3] * dp[i + 1][r][0]) % mod;
               dp[l][r][3] = (dp[l][r][3] + (dp[l][i][2] + dp[l][i][3]) * dp[i + 1][r][1]) % mod;
               dp[l][r][4] = (dp[l][r][4] + (dp[l][i][4] + dp[l][i][5]) * dp[i + 1][r][1]) % mod;
               dp[l][r][5] = (dp[l][r][5] + dp[l][i][4] * dp[i + 1][r][0]) % mod;
            }
         }
         dp[l][r][5] = (dp[l][r][5] + dp[l][r][0]) % mod;
         dp[l][r][3] = (dp[l][r][3] + dp[l][r][1]) % mod;
      }
   }
   printf("%lld\n", dp[1][n][3]);
   return 0;
}
