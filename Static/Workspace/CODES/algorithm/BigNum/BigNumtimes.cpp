#include <cstdio>
#define MAXN 10000001
#define MAXM 100000001
#define mx(a, b) (a > b ? a : b)
using namespace std;
int a[MAXN], b[MAXN], us[MAXM];
inline void readgj(int d[])
{
   register char us = getchar();
   for (int i = 1; i <= ::us[0]; ++i)
      ::us[i] = 0;
   register int i = 0;
   while (us < '0' || us > '9')
      us = getchar();
   while (us >= '0' && us <= '9')
   {
      ::us[++i] = us ^ 48;
      us = getchar();
   }
   d[0] = ::us[0] = i;
   while (i > 0)
   {
      d[d[0] - i + 1] = ::us[i];
      --i;
   }
   return;
}
inline void check(int d[])
{
   while (d[d[0]] == 0 && d[0] > 1)
      --d[0];
}
inline int read()
{
   register char us = getchar();
   register int ans = 0;
   while (us < '0' || us > '9')
      us = getchar();
   while (us >= '0' && us <= '9')
   {
      ans = (ans << 3) + (ans << 1) + (us ^ 48);
      us = getchar();
   }
   return ans;
}
inline void jw(int d[])
{
   check(d);
   for (int i = 1; i <= d[0]; ++i)
   {
      if (d[i] >= 10)
      {
         if (i == d[0])
            ++d[0];
         d[i + 1] += d[i] / 10;
         d[i] %= 10;
      }
   }
   return;
}
inline void jia(int a[], int b[])
{
   for (int i = 1; i <= mx(a[0], b[0]); ++i)
      a[i] += b[i];
   jw(a);
   return;
}
inline void cheng(int a[], int b)
{
   for (int i = 1; i <= a[0]; ++i)
      a[i] *= b;
   jw(a);
   return;
}
inline void cheng(int a[], int b[])
{
   register int i, j;
   for (int i = 1; i <= us[0]; ++i)
      us[i] = 0;
   for (i = 1; i <= a[0]; ++i)
   {
      for (j = 1; j <= b[0]; ++j)
      {
         us[i + j - 1] += a[i] * b[j];
      }
   }
   us[0] = a[0] + b[0] - 1;
   for (i = 1; i <= us[0]; ++i)
      a[i] = us[i];
   a[0] = us[0];
   jw(a);
   return;
}
inline void printgj(int d[])
{
   check(d);
   for (register int i = d[0]; i; --i)
      putchar(d[i] | 48);
   return;
}
int main()
{
   int r;
   readgj(a);
   while (1)
   {
      readgj(b);
      cheng(a, b);
      printgj(a);
   }
   return 0;
}