#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#define lowbit(x) ((x) & (-(x)))
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
int n;
template <class T, class... O>
void read(T &x, O &...oth)
{
   read(x);
   read(oth...);
}
#define MAXN 100005
signed char opts[MAXN];
signed int nums[MAXN];
int change(int a, int b, int c)
{
   static int i = 0;
   ++i;
   if (a == 0)
   {
      if (b > c)
      {
         opts[i] = 3;
      }
      else
      {
         opts[i] = 4;
      }
   }
   else
   {
      if (a > 0)
      {
         opts[i] = 1;
         nums[i] = ceil((c - b) / a);
      }
      else
      {
         opts[i] = 2;
         nums[i] = floor((c - b) / a);
      }
   }
   return i;
}
int data[MAXN];
void add(int, bool);
int ask(int);
struct operation
{
   signed char opt;
   int a;
} operations[MAXN];
int nw;
int main()
{
   read(n);
   int i;
   int a, b, c;
   string s;
   for (i = 1; i <= n; ++i)
   {
      cin >> s;
      switch (s[0])
      {
      case 65:
         operations[i].opt = 1;
         break;
      case 81:
         operations[i].opt = 2;
         break;
      default:
         operations[i].opt = 3;
         break;
      }
      if (operations[i].opt == 1)
      {
         read(a, b, c);
         operations[i].a = change(a, b, c);
      }
      else
      {
         read(operations[i].a);
      }
   }
   nw = 0;
   for (i = 1; i <= n; ++i)
   {
      if (operations[i].opt == 1)
      {
         data[++nw] = nums[operations[i].a];
      }
      if (operations[i].opt == 3)
      {
         data[++nw] = operations[i].a;
      }
   }
   sort(data + 1, data + nw + 1);
   nw = unique(data + 1, data + nw + 1) - data;
   for (i = 1; i <= n; ++i)
   {
      if (operations[i].opt == 1)
      {
         nums[operations[i].a] = lower_bound(data + 1, data + nw + 1, nums[operations[i].a]) - data;
      }
      if (operations[i].opt == 3)
      {
         operations[i].a = lower_bound(data + 1, data + nw + 1, operations[i].a) - data;
      }
   }
   memset(data, 0x00, sizeof data);
   for (i = 1; i <= n; ++i)
   {
      if (operations[i].opt == 1)
      {
         add(operations[i].a, true);
      }
      if (operations[i].opt == 2)
      {
         add(operations[i].a, false);
      }
      if (operations[i].opt == 3)
      {
         printf("%d\n", ask(operations[i].a));
      }
   }
   return 0;
}
void add(int x, bool pd)
{
   int u;
   if (pd)
   {
      if (opts[x] == 1)
      {
         u = nums[x];
         while (u <= nw)
         {
            ++data[u];
            u += lowbit(u);
         }
      }
      if (opts[x] == 2)
      {
         u = nums[x] + 1;
         while (u <= nw)
         {
            --data[u];
            u += lowbit(u);
         }
         u = 1;
         while (u <= nw)
         {
            ++data[u];
            u += lowbit(u);
         }
      }
      if (opts[x] == 3)
      {
         u = 1;
         while (u)
         {
            ++data[u];
            u -= lowbit(u);
         }
      }
   }
   else
   {
      if (opts[x] == 1)
      {
         u = nums[x];
         while (u <= nw)
         {
            --data[u];
            u += lowbit(u);
         }
      }
      if (opts[x] == 2)
      {
         u = nums[x] + 1;
         while (u <= nw)
         {
            ++data[u];
            u += lowbit(u);
         }
         u = 1;
         while (u <= nw)
         {
            --data[u];
            u += lowbit(u);
         }
      }
      if (opts[x] == 3)
      {
         u = 1;
         while (u)
         {
            --data[u];
            u -= lowbit(u);
         }
      }
      opts[x] = 4;
   }
}
int ask(int x)
{
   int ans = 0;
   while (x)
   {
      ans += data[x];
      x -= lowbit(x);
   }
   return ans;
}
