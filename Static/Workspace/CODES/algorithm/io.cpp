#include <cstdio>
using namespace std;
template <class T>
void read(T &x)
{
   x = 0;
   int flag = 1;
   char c = getchar();
   while (c < '0' || c > '9')
   {
      if (c == '-')
         flag = 0;
      c = getchar();
   }
   while (c >= '0' && c <= '9')
   {
      x = (x << 1) + (x << 3) + (c ^ 48);
      c = getchar();
   }
   x = flag ? x : -x;
}
template <class T, typename... Args>
void read(T &x, Args &...args)
{
   read(x);
   read(args...);
}
template <typename T>
void put(T x)
{
   if (x < 0)
      return putchar(45), put(-x);
   else
      putchar(x > 9 ? put(x / 10), x % 10 | 48 : x % 10 | 48);
}