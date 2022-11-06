#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 34
int f[MAXN][MAXN];
int K, B;
int dp(int n)
{
   if (n == 0)
   {
      return 0;
   }
   vector<int> v;
   while (n)
   {
      v.push_back(n % B);
      n /= B;
   }
   int ans = 0;
   int lst = 0;
   for (int i = v.size() - 1; i >= 0; --i)
   {
      if (v[i] != 0)
      {
         ans += f[i][K - lst];
         if (v[i] > 1)
         {
            if (K - lst - 1 >= 0)
               ans += f[i][K - lst - 1];
            break;
         }
         else
         {
            ++lst;
            if (lst > K)
            {
               break;
            }
         }
      }
      if (i == 0 && lst == K)
         ans++;
   }
   return ans;
}
int main()
{
   int a, b;
   cin >> a >> b;
   cin >> K >> B;
   f[0][0] = 1;
   for (int i = 1; i <= 33; ++i)
   {
      f[i][0] = 1;
      for (int j = 1; j <= 33; ++j)
      {
         f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
      }
   }
   printf("%d", dp(b) - dp(a - 1));
}