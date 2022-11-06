#include <bits/stdc++.h>
using namespace std;
void init()
{
   //这里是预处理DP数组
}
int dp(int x)
{
   if (x == 0)
   {
      //这里特判掉0
   }
   vector<int> v;
   while (x)
      v.push_back(x % 10), x /= 10; //这里将数字进行数位拆分，10表示10进制
   int ans = 0, lst;                //万金油，一般是统计数目的ans和前面累计影响的lst
   for (int i = v.size() - 1; i >= 0; --i)
   {
      int x = v[i];
      for (int i = 0; i < x; ++i)
      {
         //这里处理一般性的影响
      }
      if (x /*...*/)
      {
         //特殊情况终止处理
         break;
      }
      lst /*...*/; //累计影响
      if (!i)
      {
         //最后单独处理
      }
   }
   return ans;
}
