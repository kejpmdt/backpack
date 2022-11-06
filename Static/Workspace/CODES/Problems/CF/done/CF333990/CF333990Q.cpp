#include <iostream>
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
int times[10] = {1, 10, 5, 10, 5, 2, 5, 10, 5, 10};
int add[10][11] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {45, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
        {20, 2, 4, 6, 8, 0, 0, 0, 0, 0, 0},
        {45, 3, 6, 9, 2, 5, 8, 1, 4, 7, 0},
        {20, 4, 8, 2, 6, 0, 0, 0, 0, 0, 0},
        {5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {20, 6, 2, 8, 4, 0, 0, 0, 0, 0, 0},
        {45, 7, 4, 1, 8, 5, 2, 9, 6, 3, 0},
        {20, 8, 6, 4, 2, 0, 0, 0, 0, 0, 0},
        {45, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
};
int main()
{
   int q;
   long long a, b;
   read(q);
   long long ans;
   while (q--)
   {
      read(a, b);
      ans = a / b / times[b % 10] * add[b % 10][0];
      a %= (b * times[b % 10]);
      for (int i = 1; a >= b; ++i)
      {
         a -= b;
         ans += add[b % 10][i];
      }
      printf("%lld\n", ans);
   }
   return 0;
}
