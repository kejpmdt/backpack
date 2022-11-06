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
bool f[100000005];
int ss[100000000];
int s;
int main()
{
   int n, q;
   read(n, q);
   int i, j;
   s = 0;
   f[1] = true;
   for (i = 2; i <= n; ++i)
   {
      if (!f[i])
      {
         ss[++s] = i;
      }
      for (j = 1; i * ss[j] <= n; ++j)
      {
         f[i * ss[j]] = true;
         if (i % ss[j] == 0)
         {
            break;
         }
      }
   }
   int u;
   while (q--)
   {
      read(u);
      printf("%d\n", ss[u]);
   }
   return 0;
}