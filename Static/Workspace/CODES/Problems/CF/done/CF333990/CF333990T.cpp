#include <cstdio>
#include <iostream>
#define mi2(a, b) (a < b ? a : b)
#define mx2(a, b) (a > b ? a : b)
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
   long long n;
   read(n);
   long long nw = 1;
   long long ans = 0;
   long long lst = 0;
   long long u;
   while (n--)
   {
      read(u);
      if (u == lst)
      {
         continue;
      }
      if (u > lst && u <= lst * 2)
      {
         ++nw;
      }
      else
      {
         ans = mx2(ans, nw);
         nw = 1;
      }
      lst = u;
   }
   ans = mx2(ans, nw);
   printf("%lld", ans);
   return 0;
}
