#include <iostream>
using namespace std;
int main()
{
   int n;
   int i, j;
   cin >> n;
   int ans = 0;
   for (i = 0; i <= n; ++i)
   {
      for (j = i; j <= n; ++j)
      {
         ans += i;
         ans += j;
      }
   }
   cout << ans;
   return 0;
}