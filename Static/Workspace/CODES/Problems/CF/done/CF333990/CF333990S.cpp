#include <cstdio>
#include <iostream>
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
   int n;
   read(n);
   int a = 0, b = 0;
   int u;
   while (n--)
   {
      read(u);
      if (u == 1)
      {
         ++a;
      }
      else
      {
         ++b;
      }
   }
   if (b)
   {
      printf("2 ");
      --b;
   }
   if (a)
   {
      printf("1 ");
      --a;
   }
   while (b)
   {
      printf("2 ");
      --b;
   }
   while (a)
   {
      printf("1 ");
      --a;
   }
   return 0;
}