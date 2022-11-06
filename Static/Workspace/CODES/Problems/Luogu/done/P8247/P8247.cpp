#include <cstdio>
#define MAXNM 2000095
#define mp(a, b) (xlc[a * m + b])
#define mx2(a, b) (a > b ? a : b)
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
int n, m;
short xlc[MAXNM];
void sp(int &a, int &b)
{
   a ^= b;
   b ^= a;
   a ^= b;
}
int gcd(int b, int a)
{
   while (a && b)
   {
      if (a > b)
         a %= b;
      else
         b %= a;
   }
   return a ? a : b;
}
void show(void)
{
   for (int i = 0; i < n; ++i)
   {
      for (int j = 0; j < m; ++j)
         putchar(mp(i, j));
      putchar(10);
   }
   putchar(10);
}
int main()
{
   n = over_templatefunction_read<int>();
   m = over_templatefunction_read<int>();
   char us = getchar();
   while (us != '.' && us != 'S' && us != 'K')
      us = getchar();
   for (int i = 0; i < n; ++i)
   {
      for (int j = 0; j < m; ++j)
      {
         mp(i, j) = us;
         us = getchar();
      }
      while (us != '.' && us != 'S' && us != 'K' && us != EOF)
         us = getchar();
   }
   int x = 0, y = 0;
   for (int i = 0; i < n; ++i)
   {
      for (int j = 0; j < m; ++j)
      {
         if (mp(i, j) == 'S')
         {
            x = i;
            y = j;
         }
      }
   }
   int deltax, deltay;
   int movex, movey;
   int ans = 0;
   for (int i = 0; i < x; ++i)
   {
      for (int j = 0; j < m; ++j)
      {
         if (mp(i, j) == 'K')
         {
            ++ans;
            deltax = x - i;
            deltay = mx2(y - j, j - y);
            movex = deltax / gcd(deltax, deltay);
            movey = deltay / gcd(deltax, deltay);
            if (j > y)
               movey = -movey;
            deltax = i;
            deltay = j;
            while (deltax != x)
            {
               mp(deltax, deltay) = '.';
               deltax += movex;
               deltay += movey;
            }
         }
      }
   }
   for (int i = n; i > x; --i)
   {
      for (int j = 0; j < m; ++j)
      {
         if (mp(i, j) == 'K')
         {
            ++ans;
            deltax = i - x;
            deltay = mx2(y - j, j - y);
            movex = deltax / gcd(deltax, deltay);
            movey = deltay / gcd(deltax, deltay);
            if (j > y)
               movey = -movey;
            movex = -movex;
            deltax = i;
            deltay = j;
            while (deltax != x)
            {
               mp(deltax, deltay) = '.';
               deltax += movex;
               deltay += movey;
            }
         }
      }
   }
   for (int i = 0; i < y; ++i)
   {
      if (mp(x, i) == 'K')
      {
         ++ans;
         break;
      }
   }
   for (int i = y + 1; i < m; ++i)
   {
      if (mp(x, i) == 'K')
      {
         ++ans;
         break;
      }
   }
   put(ans);
}
