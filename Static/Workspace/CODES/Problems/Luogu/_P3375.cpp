#include <cstdio>
#include <iostream>
using namespace std;
class stringKMP
{
public:
   const string s;
   int *f;
   void build(void);
   int kmp(string, int);
   stringKMP(string n) : s(" " + n), f(new int[s.size() + 5]) {}
};
void stringKMP::build(void)
{
   f[1] = 0;
   int nw = 1, k = 0;
   while (nw <= s.size())
   {
      if (k == 0 || s[nw] == s[k])
      {
         f[++nw] = ++k;
      }
      else
      {
         k = f[k];
      }
   }
}
int stringKMP::kmp(string c, int t)
{
   int nw = 0;
   for (; t < c.size(); ++t)
   {
      while (nw && c[t] != s[nw + 1])
      {
         nw = f[nw];
      }
      if (c[t] == s[nw + 1])
      {
         ++nw;
      }
      if (nw == s.size() - 1)
      {
         return t - nw + 1;
      }
   }
   return -1;
}

int main()
{
   string e;
   string b;
   cin >> b>>e;
   stringKMP a(e);
   a.build();
   int p = -1;
   do
   {
      p = a.kmp(b, p + 1);
      if (p >= 0)
      {
         printf("%d\n", p+1);
      }
   } while (p >= 0);
   for (int i = 1; i <= e.size(); ++i)
   {
      printf("%d ", a.f[i]);
   }

   return 0;
}