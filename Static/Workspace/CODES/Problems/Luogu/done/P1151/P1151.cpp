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
   int k;
   bool f = true;
   k = over_templatefunction_read<int>();
   for (int i = 10000; i <= 30000; ++i)
   {
      if (i / 100 % k == 0 && i % 1000 % k == 0 && i / 10 % 1000 % k == 0)
      {
         put(i);
         f = false;
         putchar(10);
      }
   }
   if (f)
      printf("No");
}