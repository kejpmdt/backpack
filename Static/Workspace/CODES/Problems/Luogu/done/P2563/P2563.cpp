#include <cstdio>
#include <iostream>
using namespace std;
int prime[200];
int ans[205];
int main()
{
   int nw = 0;
   int i, j;
   for (i = 1; i <= 200; ++i)
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
      for (int j = prime[i]; j <= 200; ++j)
      {
         ans[j] += ans[j - prime[i]];
      }
   }
   while (cin >> n)
   {
      printf("%d\n", ans[n]);
   }
   return 0;
}
