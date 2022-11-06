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
bool over_boolarrayarray_res[2200][2200];
int over_signedintarray_pow3[8] = {1, 3, 9, 27, 81, 243, 729, 2187};
void over_voidfunction_fx(int frmx, int frmy, int lev)
{
   if (lev == 1)
   {
      over_boolarrayarray_res[frmx][frmy] = true;
      return;
   }
   over_voidfunction_fx(frmx, frmy, lev - 1);
   over_voidfunction_fx(frmx + over_signedintarray_pow3[lev - 2] * 2, frmy, lev - 1);
   over_voidfunction_fx(frmx + over_signedintarray_pow3[lev - 2], frmy + over_signedintarray_pow3[lev - 2], lev - 1);
   over_voidfunction_fx(frmx, frmy + over_signedintarray_pow3[lev - 2] * 2, lev - 1);
   over_voidfunction_fx(frmx + over_signedintarray_pow3[lev - 2] * 2, frmy + over_signedintarray_pow3[lev - 2] * 2, lev - 1);
   return;
}
signed int main()
{
   signed int main_signedint_n;
   over_voidfunction_fx(0, 0, 7);
   main_signedint_n = over_templatefunction_read<signed int>();
   while (main_signedint_n > 0)
   {
      for (signed int main_signedint_i = 0; main_signedint_i < over_signedintarray_pow3[main_signedint_n - 1]; ++main_signedint_i)
      {
         for (signed int main_signedint_j = 0; main_signedint_j < over_signedintarray_pow3[main_signedint_n - 1]; ++main_signedint_j)
         {
            if (over_boolarrayarray_res[main_signedint_i][main_signedint_j])
               putchar(88);
            else
               putchar(32);
         }
         putchar(10);
      }
      putchar(45);
      putchar(10);
      main_signedint_n = over_templatefunction_read<signed int>();
   }
   return 0;
}