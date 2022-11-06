#include <cstdio>
#include <vector>
using namespace std;
long long f[15][10][10];
void init(void)
{
   for (int i = 0; i < 10; ++i)
   {
      f[1][i][i] = 1;
   }
   for (int i = 2; i <= 13; ++i)
   {
      for (int j = 0; j < 10; ++j)
      {
         for (int k = 1; k < 10; ++k)
         {
            for (int t = 0; t < 10; ++t)
            {
               f[i][j][k] += f[i - 1][t][k];
            }
         }
      }
   }
}

vector<int> dp(int x)
{
   vector<int> ans(10, 0);
   if (x == 0)
   {
      return ans;
   }
