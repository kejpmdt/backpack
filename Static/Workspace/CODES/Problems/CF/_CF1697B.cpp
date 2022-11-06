#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long a[200005];
template <class T>
void read(T &ans)
{
   ans = 0;
   bool f = false;
   char us = getchar();
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
template <class T, class... Oth>
void read(T &x, Oth &...a)
{
   read(x);
   read(a...);
}
int main()
{
   int n, q;
   read(n, q);
   for (int i = 1; i <= n; ++i)
   {
      read(a[i]);
   }
   sort(a + 1, a + n + 1);
   for (int i = 1; i <= n; ++i)
   {
      a[i] += a[i - 1];
   }
   int x, y;
   while (q--)
   {
      read(y, x);
      printf("%lld\n", a[n - y + x] - a[n - y]);
   }
   return 0;
}