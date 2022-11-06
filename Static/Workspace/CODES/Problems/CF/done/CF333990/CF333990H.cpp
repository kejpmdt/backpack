#include <iostream>
#include <cstdio>
#include <algorithm>
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
int a[100005];
int main()
{
   int t;
   int n;
   read(t);
   int i;
   int nw;
   int x;
   int ans;
   while (t--)
   {
      read(n);
      for (i = 1; i <= n; ++i)
      {
         read(a[i]);
      }
      sort(a + 1, a + n + 1);
      nw = 1;
      x = 1;
      ans = 0;
      for (i = 1; i <= n; ++i)
      {
         while (nw <= a[i])
         {
            nw <<= 1;
         }
         nw >>= 1;
         if (a[i - 1] >= nw)
         {
            ++x;
         }
         else
         {
            ans += x * (x - 1);
            x = 1;
         }
      }
      ans += x * (x - 1);
      printf("%d\n", ans / 2);
   }
   return 0;
}
