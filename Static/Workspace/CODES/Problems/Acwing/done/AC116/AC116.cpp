#include <cstdio>
using namespace std;
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
bool over_boolarrayarray_need[4][4];
signed int main()
{
   signed short main_short_i;
   signed short main_short_j;
   signed short main_short_bl1;
   signed short main_short_bl2;
   char main_char_usc;
   for (main_short_i = 0; main_short_i < 4; ++main_short_i)
   {
      for (main_short_j = 0; main_short_j < 4; ++main_short_j)
      {
         main_char_usc = getchar();
         if (main_char_usc == 43)
         {
            for (main_short_bl1 = 0; main_short_bl1 < 4; ++main_short_bl1)
            {
               for (main_short_bl2 = 0; main_short_bl2 < 4; ++main_short_bl2)
               {
                  if (main_short_bl1 == main_short_i || main_short_bl2 == main_short_j)
                     over_boolarrayarray_need[main_short_bl1][main_short_bl2] ^= 1;
               }
            }
         }
      }
      main_char_usc = getchar();
   }
   signed short main_short_ans = 0;
   for (main_short_i = 0; main_short_i < 4; ++main_short_i)
   {
      for (main_short_j = 0; main_short_j < 4; ++main_short_j)
      {
         if (over_boolarrayarray_need[main_short_i][main_short_j])
            ++main_short_ans;
      }
   }
   put(main_short_ans);
   putchar(10);
   for (main_short_i = 0; main_short_i < 4; ++main_short_i)
   {
      for (main_short_j = 0; main_short_j < 4; ++main_short_j)
      {
         if (over_boolarrayarray_need[main_short_i][main_short_j])
         {
            put(main_short_i + 1);
            putchar(32);
            put(main_short_j + 1);
            putchar(10);
         }
      }
   }
   return 0;
}
