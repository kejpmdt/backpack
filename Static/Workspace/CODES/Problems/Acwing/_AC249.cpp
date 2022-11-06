#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define MAXN 40005
#define MAXM 50005
#define belong(x) (((x)-1) / length + 1)
#define begin(x) (((x)-1) * length + 1)
#define end(x) ((x)*length)
using namespace std;
int inp[MAXN];
int us[MAXN];
int length;
struct ask
{
   int l, r;
   int t;
   bool operator<(ask x) const
   {
      if (belong(l) != belong(x.l))
         return l < x.l;
      else
         return r > x.r;
   }
} asks[MAXM];
int anss[MAXM];
template <class T>
inline T over_templatefunction_read(void)
{
   T ans;
   static bool f;
   static char us = getchar();
   ans = 0;
   f = false;
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
   return f ? -ans : ans;
}
template <typename T>
void put(T x)
{
   if (x < 0)
      return putchar(45), put(-x);
   else
      putchar(x > 9 ? put(x / 10), x % 10 | 48 : x % 10 | 48);
}
int main()
{
   int n, m;
   n = over_templatefunction_read<int>();
   m = over_templatefunction_read<int>();
   length = n / sqrt(m);
   for (int i = 1; i <= n; ++i)
      inp[i] = over_templatefunction_read<int>();
   memcpy(inp, us, sizeof inp);
   sort(us + 1, us + n + 1);
   auto usend = unique(us + 1, us + n + 1);
   for (int i = 1; i <= n; ++i)
      inp[i] = *find(us, usend, inp[i]);
   memset(us, 0x00, sizeof us);
   int nwl, nwr;
   nwl = 1, nwr = 0;
   for (int i = 1; i <= m; ++i)
   {
      asks[i].l = over_templatefunction_read<int>();
      asks[i].r = over_templatefunction_read<int>();
      asks[i].t = i;
   }
   sort(asks + 1, asks + m + 1);
   for (int i = 1; i <= m; ++i)
   {
      while (nwl < l)
      {
      }
