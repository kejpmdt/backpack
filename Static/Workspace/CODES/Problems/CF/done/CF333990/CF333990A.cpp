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
int num[200005];
int main()
{
   int t, n;
   long long ans;
   read(t);
   int nw;
   while (t--)
   {
      read(n);
      for (int i = 1; i <= n; ++i)
      {
         read(num[i]);
         num[i] -= i;
      }
      sort(num + 1, num + n + 1);
      nw = 0;
      ans = 0;
      for (int i = 1; i <= n; ++i)
      {
         if (num[i] != num[i - 1])
         {
            nw = 0;
         }
         ++nw;
         ans += nw - 1;
      }
      printf("%lld\n", ans);
   }
   return 0;
}