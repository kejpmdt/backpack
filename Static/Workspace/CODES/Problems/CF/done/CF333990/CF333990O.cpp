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
   int n;
   int u, lst;
   read(t);
   int i;
   bool pd;
   while (t--)
   {
      read(n);
      pd = true;
      for (i = 1; i <= n; ++i)
      {
         read(u);
         if (i == 1 || !pd)
         {
            lst = u;
            continue;
         }
         if (u - lst > 1 || lst - u > 1)
         {
            printf("YES\n%d %d\n", i - 1, i);
            pd = false;
         }
         lst = u;
      }
      if (pd)
      {
         printf("NO\n");
      }
   }
}
