#include <iostream>
#include <cstdio>
using namespace std;
int nums[500005];
int main()
{
   int nw = 0;
   int i = 0;
   int q;
   cin >> q;
   int opt;
   long long sum = 0;
   double a, b;
   while (q--)
   {
      cin >> opt;
      if (opt == 1)
      {
         cin >> nums[++nw];
         sum -= nums[nw - 1];
         sum += nums[nw];
         while (i < nw - 1)
         {
            a = 1.0 * sum / (i + 1);
            b = 1.0 * (sum + nums[i + 1]) / (i + 2);
            if (a >= b)
            {
               ++i;
               sum += nums[i];
            }
            else
            {
               break;
            }
         }
      }
      else
      {
         a = 1.0 * sum / (i + 1);
         printf("%.6lf\n", nums[nw] - a);
      }
   }
   return 0;
}
