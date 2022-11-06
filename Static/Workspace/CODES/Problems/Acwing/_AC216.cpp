#include <cstdio>
#define MAXN 100005
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
signed int over_signedint_n;
signed int over_signedintarray_inp[MAXN];

signed int main()
{
   over_signedint_n = over_templatefunction_read<int>();
   signed int main_signedint_i;
   for (main_signedint_i = 1; main_signedint_i <= over_signedint_n; ++main_signedint_i)
      over_signedintarray_inp[main_signedint_i] = over_templatefunction_read<int>();
   signed int main_signedint_j;
   signed long long main_signedlonglong_ans1 = 0;
   signed long long main_signedlonglong_ans2 = 0;
   signed long long main_signedlonglong_ans3 = 0;
   signed int main_signedint_us1;
   signed int main_signedint_us2;
   signed int main_signedint_us3;
   for (main_signedint_i = 1; main_signedint_i <= over_signedint_n; ++main_signedint_i)
   {
      main_signedint_us1 = main_signedint_us2 = main_signedint_us3 = over_signedintarray_inp[main_signedint_i];
      for (main_signedint_j = main_signedint_i + 1; main_signedint_j <= over_signedint_n; ++main_signedint_j)
      {
         main_signedint_us1 ^= over_signedintarray_inp[main_signedint_j];
         main_signedint_us2 &= over_signedintarray_inp[main_signedint_j];
         main_signedint_us3 |= over_signedintarray_inp[main_signedint_j];
         main_signedlonglong_ans1 += main_signedint_us1;
         main_signedlonglong_ans2 += main_signedint_us2;
         main_signedlonglong_ans3 += main_signedint_us3;
      }
   }
   main_signedlonglong_ans1 <<= 1;
   main_signedlonglong_ans2 <<= 1;
   main_signedlonglong_ans3 <<= 1;
   for (main_signedint_i = 1; main_signedint_i <= over_signedint_n; ++main_signedint_i)
   {
      main_signedlonglong_ans1 += over_signedintarray_inp[main_signedint_i];
      main_signedlonglong_ans2 += over_signedintarray_inp[main_signedint_i];
      main_signedlonglong_ans3 += over_signedintarray_inp[main_signedint_i];
   }
   printf("%.3f %.3f %.3f", 1.0 * main_signedlonglong_ans1 / ((over_signedint_n * over_signedint_n << 1) - over_signedint_n), 1.0 * main_signedlonglong_ans1 / ((over_signedint_n * over_signedint_n << 1) - over_signedint_n), 1.0 * main_signedlonglong_ans1 / ((over_signedint_n * over_signedint_n << 1) - over_signedint_n));
   return 0;
}