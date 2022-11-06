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
   long long n, k;
   read(t);
   while (t--)
   {
      read(n, k);
      if (k % (n - 1) == 0)
      {
         printf("%lld\n", k / (n - 1) * n - 1);
      }
      else
      {
         printf("%lld\n", k / (n - 1) * n + k % (n - 1));
      }
   }
   return 0;
}