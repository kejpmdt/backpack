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
#define mi2(a, b) (a < b ? a : b)
#define mx2(a, b) (a > b ? a : b)
int main()
{
   int q;
   read(q);
   int a, b, c;
   while (q--)
   {
      read(a, b, c);
      c = a + b + c;
      printf("%d\n", mi2(mi2(a, b), c / 3));
   }
   return 0;
}