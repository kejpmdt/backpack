#include <cstdio>
#define mx2(a, b) (a > b ? a : b)
using namespace std;
int main()
{
   char uschar = getchar();
   int ans = 0;

   int a = 0;
   int b = 0;
   while (uschar == 'M' || uschar == 'F')
   {
      if (uschar == 'M')
      {
         ++a;
         b = 0;
      }
      else
      {
         if (a)
         {
            ans = mx2(ans + 1, a);
         }
         ans = mx2(ans, a);
         b = a;
      }
      uschar = getchar();
   }
   printf("%d", ans);
}
