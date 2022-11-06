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
   read(t);
   bool pd;
   int a, b;
   int u;
   int i, j;
   while (t--)
   {
      pd = false;
      read(a, b);
      if (a < b)
      {
         printf("nO\n");
         continue;
      }
      u = a;
      for (i = b; i >= 1; --i)
      {
         if (pd)
         {
            break;
         }
         if (u % i == 0 && (u / i) % 2 == 1)
         {
            printf("yEs\n");
            for (j = b; j > i; --j)
            {
               printf("1 ");
            }
            for (j = i; j >= 1; --j)
            {
               printf("%d ", u / i);
            }
            putchar(10);
            pd = true;
         }
         --u;
      }
      if (pd)
      {
         continue;
      }
      u = a;
      for (i = b; i >= 1; --i)
      {
         if (pd)
         {
            break;
         }
         if (u % i == 0 && (u / i) % 2 == 0)
         {
            printf("yEs\n");
            for (j = b; j > i; --j)
            {
               printf("2 ");
            }
            for (j = i; j >= 1; --j)
            {
               printf("%d ", u / i);
            }
            putchar(10);
            pd = true;
         }
         -- --u;
      }
      if (pd)
      {
         continue;
      }
      printf("nO\n");
   }
}
