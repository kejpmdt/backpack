#include <iostream>
#include <cstdio>
#define mi2(a, b) (a < b ? a : b)
#define mx2(a, b) (a > b ? a : b)
#define MAXN 1000006
using namespace std;
int a[MAXN], b[MAXN];
__int128_t dfs(int nw)
{
   __int128_t A, B;
   if (a[nw] < 0)
   {
      A = -a[nw];
   }
   else
   {
      A = dfs(a[nw]);
   }
   if (b[nw] < 0)
   {
      B = -b[nw];
   }
   else
   {
      B = dfs(b[nw]);
   }
   return 2ll * mx2(A, B);
}
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
void print(__int128_t x)
{
   if (x == 0)
   {
      return;
   }
   print(x >> 1);
   putchar(48 | (x & 1));
}
int main()
{
   int n;
   read(n);
   for (int i = 1; i <= n; ++i)
   {
      read(a[i], b[i]);
   }
   __int128_t ans = dfs(1);
   print(ans);
}