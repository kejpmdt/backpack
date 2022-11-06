#include <iostream>
#include <cstdio>
#define MAXN 200005
#define MAXM 600005
#define abs(x) (x > 0 ? x : -(x))
using namespace std;
long long gcd(long long a, long long b)
{
   if (a > b)
   {
      swap(a, b);
   }
   return b % a == 0 ? a : gcd(b % a, a);
}
struct frac
{
   long long a, b;
   frac(long long c, long long d) : a(c), b(d) {}
   void operator=(const frac &oth)
   {
      a = oth.a;
      b = oth.b;
      if (a == 0)
      {
         b = 0;
         return;
      }
      long long u = gcd(abs(a), abs(b));
      a /= u;
      b /= u;
   }
   frac() : a(0), b(1) {}
};
bool operator<(const frac &a, const frac &b)
{
   return a.a * b.b < b.a * a.b;
}
frac operator+(const frac &a, const frac &b)
{
   return frac(a.a * b.b + b.a * a.b, a.b * b.b);
}
frac operator-(const frac &a, const frac &b)
{
   return frac(a.a * b.b - b.a * a.b, a.b * b.b);
}
frac operator*(const frac &a, const frac &b)
{
   return frac(a.a * b.a, a.b * b.b);
}
frac operator/(const frac &a, const frac &b)
{
   return frac(a.a * b.b, a.b * b.a);
}
frac operator*(const frac &a, int &b)
{
   return frac(a.a * b, a.b);
}
frac operator/(const frac &a, int &b)
{
   return frac(a.a, a.b * b);
}
void operator+=(frac &a, const frac &b)
{
   a = a + b;
}
void operator-=(frac &a, const frac &b)
{
   a = a - b;
}
void operator*=(frac &a, const frac &b)
{
   a = a * b;
}
void operator/=(frac &a, const frac &b)
{
   a = a / b;
}
int fst[MAXN], nt[MAXM], to[MAXM];
int ins[MAXN];
int outs[MAXN];
frac ans[MAXN];
void addline(int i, int a, int b)
{
   to[i] = b;
   nt[i] = fst[a];
   fst[a] = i;
   ++ins[b];
   ++outs[a];
}
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
void dfs(int nw)
{
   if (ins[nw])
   {
      return;
   }
   int i;
   for (i = fst[nw]; i; i = nt[i])
   {
      --ins[to[i]];
      ans[to[i]] += ans[nw] / outs[nw];
      dfs(to[i]);
   }
}
void print(long long n)
{
   if (n > 9)
      print(n / 10);
   putchar(n % 10 + 48);
}
int main()
{
   int n, m;
   int d;
   int i;
   int u;
   read(n, m);

   int nw = 0;
   for (i = 1; i <= n; ++i)
   {
      read(d);
      while (d--)
      {
         read(u);
         addline(++nw, i, u);
      }
   }
   for (i = 1; i <= n; ++i)
   {
      if (ins[i] == 0)
      {
         ans[i] = frac(1, 1);
         addline(++nw, 0, i);
      }
   }
   dfs(0);
   for (i = 1; i <= n; ++i)
   {
      if (outs[i] == 0)
      {
         print(ans[i].a);
         putchar(32);
         print(ans[i].b);
         putchar(10);
      }
   }
   return 0;
}
