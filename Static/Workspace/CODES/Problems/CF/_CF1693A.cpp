#include <cstdio>
#include <iostream>
using namespace std;
template <class T>
inline void read(T &ans)
{
   ans = 0;
   unsigned char us = getchar();
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
}
template <class T, class... O>
inline void read(T &x, O &...oth)
{
   read(x);
   read(oth...);
}
int main()
{
   int t;
   read(t);
   int n;
   int i;
   long long u;
   long long nw;
   long long nt;
   signed char res;
   while (t--)
   {
      read(n);
      u = 0;
      res = 0;
      nw = 0;
      nt = 0;
      for (i = 1; i <= n; ++i)
      {
         read(u);
         nw = nt;
         nt = 0;//res: 1已经到0
         if (res == 1 && u != 0)
         {
            res = -1;
         }
         if (res == -1)
         {
            continue;
         }
         if (nw > u)
         {
            res = -1;
            continue;
         }
         if (nw == u)
         {
            res = 1;
         }
         nt = nw - u;
      }
      if (res == 0 && nt == 0)
      {
         printf("Yes\n");
      }
      else
      {
         printf("No\n");
      }
   }
}
