#include <cstdio>
#include <iostream>
using namespace std;
long long prime[1000];
long long ans[1005];
int main()
{
   int nw = 0;
   int i, j;
   for (i = 1; i <= 1000; ++i)
   {  
      for (j = 2; j < i; ++j)
      {
         if (i % j == 0)
         {
            break;
         }
      }
      if (i == j)
      {
         prime[nw++] = i;
      }
   }
   int n;
   ans[0] = 1;
   for (int i = 0; i < nw; ++i)
   {
      for (int j = prime[i]; j <= 1000; ++j)
      {
         ans[j] += ans[j - prime[i]];
      }
   }
   while (cin >> n)
   {
      printf("%lld\n", ans[n]);
   }
   return 0;
}
