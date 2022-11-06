#include <iostream>
#include <cstdio>
#include <set>
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
set<int> s;
int main()
{
   int n;
   read(n);
   int u;
   while (n--)
   {
      read(u);
      s.insert(u);
   }
   if (s.size() > 3)
   {
      printf("-1");
      return 0;
   }
   auto i = s.begin();
   if (s.size() == 3)
   {
      ++i;
      if (*++i - *--i != *i - *--i)
      {
         printf("-1");
      }
      else
      {
         printf("%d", *++i - *--i);
      }
      return 0;
   }
   if (s.size() == 2)
   {
      if ((*(++i) - *(--i)) % 2 == 0)
      {
         printf("%d", (*++i - *--i) / 2);
      }
      else
      {
         printf("%d", *++i - *--i);
      }
      return 0;
   }
   printf("0");
}
