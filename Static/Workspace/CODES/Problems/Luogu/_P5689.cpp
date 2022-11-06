#include <cstdio>
#include <iostream>
#define MAXN 300005
#define MOD 1000000007
using namespace std;
int fa[MAXN];
int sz[MAXN];
int getfa(int nw)
{
   if (fa[fa[nw]] != fa[nw])
   {
      fa[nw] = getfa(fa[nw]);
   }
   return fa[nw];
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
long long jc[MAXN];
long long jcny[MAXN];
long long qpow(long long a, long long n)
{
   long long ans = 1;
   while (n)
   {
      if (n & 1)
      {
         ans *= a;
         ans %= MOD;
      }
      a = a * a % MOD;
      n >>= 1;
   }
   return ans;
}
int main()
{
   int n, q;
   long long ans;
   long long a, b, opt;
   read(n, q);
   ans = 0;
   jc[0] = 1;
   for (int i = 0; i < n; ++i)
   {
      fa[i] = i;
      sz[i] = 1;
   }
   for (int i = 1; i <= n; ++i)
   {
      jc[i] = jc[i - 1] * i % MOD;
   }
   jcny[n] = qpow(jc[n], MOD - 2);
   for (int i = n; i >= 1; --i)
   {
      jcny[i - 1] = jcny[i] * i % MOD;
   }
   while (q--)
   {
      read(opt);
      if (opt == 1)
      {
         read(a, b);
         a = (a + ans) % MOD;
         b = (b + ans) % MOD;
         sz[getfa(b)] += sz[getfa(a)];
         fa[fa[a]] = fa[b];
      }
      else
      {
         read(a);
         a = (a + ans) % MOD;
         ans = jc[sz[getfa(a)]] % MOD;
         printf("%lld\n", ans);
      }
   }
}
