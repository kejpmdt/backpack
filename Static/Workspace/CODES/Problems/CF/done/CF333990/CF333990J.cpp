#include <iostream>
#include <cstdio>
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
int main()
{
   int t;
   int n, a, b;
   int u;
   int i;
   int nw;
   int j;
   read(t);
   while (t--)
   {
      read(n, a, b);
      for (i = n - 1; i >= 1; --i)
      {
         if ((b - a) % i == 0)
         {
            u = (b - a) / i;
            nw = a;
            for (j = 1; j <= n - i - 1; ++j)
            {
               a -= u;
               if (a <= 0)
               {
                  a += u;
               }
            }
            for (j = 1; j <= n; ++j)
            {
               printf("%d ", a);
               a += u;
            }
            break;
         }
      }
      putchar(10);
   }
   return 0;
}
