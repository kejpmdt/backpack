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
   int n, x;
   int a, b;
   int u;
   read(t);
   while (t--)
   {
      read(n, x);
      a = b = 0;
      while (n--)
      {
         read(u);
         if (u % 2 == 0)
         {
            ++a;
         }
         else
         {
            ++b;
         }
      }
      n = a + b;
      if (n == x)
      {
         if (b % 2 == 1)
         {
            printf("yES");
         }
         else
         {
            printf("nO");
         }
      }
      else
      {
         if (a == 0)
         {
            if (x % 2 == 1)
            {
               printf("yeS");
            }
            else
            {
               printf("no");
            }
         }
         else
         {
            if (b == 0)
            {
               printf("No");
            }
            else
               printf("YES");
         }
      }
      putchar(10);
   }
   return 0;
}