#include <cstdio>
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
using namespace std;
int main()
{
   int l, r;
   l = over_templatefunction_read<int>();
   r = over_templatefunction_read<int>();
   int u;
   int ans;
   for (int i = l; i <= r; ++i)
   {
      u = i;
      while (u)
      {
         if (u % 10 == 2)
            ++ans;
         u /= 10;
      }
   }
   put(ans);
}