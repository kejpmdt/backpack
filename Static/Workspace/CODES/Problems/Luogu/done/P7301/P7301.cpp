#include <cstdio>
#include <iostream>
using namespace std;
#define mi2(a, b) (a < b ? a : b)
#define mx2(a, b) (a > b ? a : b)
int a[1005], b[1005], c[1005], d[1005];
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
   int u;
   read(n);
   int i, j;
   for (i = 1; i <= n; ++i)
   {
      for (j = 1; j <= n; ++j)
      {
         read(u);
         if (i & 1)
            a[j] += u;
         else
            b[j] += u;
         if (j & 1)
            c[i] += u;
         else
            d[i] += u;
      }
   }
   int ans1 = 0, ans2 = 0;
   for (i = 1; i <= n; ++i)
   {
      ans1 += mx2(a[i], b[i]);
      ans2 += mx2(c[i], d[i]);
   }
   printf("%d", mx2(ans1, ans2));
}