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
template <typename T, typename A, typename B>
T qpow(A a, B n, T MOD)
{
   T ans = 1;
   T u = a;
   while (n)
   {
      if (n & 1)
      {
         ans *= u;
         ans %= MOD;
      }
      u = u * u % MOD;
      n >>= 1;
   }
   return ans;
}
int main()
{
   int t;
   read(t);
   long long n, k;
   long long P = 1000000007ll;
   while (t--)
   {
      read(n, k);
      printf("%lld\n", qpow(n, k, P));
   }
}
