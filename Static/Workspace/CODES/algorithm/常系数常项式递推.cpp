#include <cstdio>
#include <iostream>
#define mod 998244353
using namespace std;
int ans[2][26];
long long g[26][26];
long long bs[26][26];
long long us[26][26];
int k;
char n[300];
int dy(char c)
{
   if (c >= '0' && c <= '9')
   {
      return c - '0';
   }
   if (c >= 'a' && c <= 'f')
   {
      return c - 'a' + 10;
   }
   if (c >= 'A' && c <= 'F')
   {
      return c - 'A' + 10;
   }
}
void times(void)
{
   int a, b, c;
   for (a = 1; a <= k; ++a)
   {
      for (b = 1; b <= k; ++b)
      {
         us[a][b] = 0;
      }
   }
   for (a = 1; a <= k; ++a)
   {
      for (b = 1; b <= k; ++b)
      {
         for (c = 1; c <= k; ++c)
         {
            us[a][b] += bs[a][c] * g[c][b];
            us[a][b] %= mod;
         }
      }
   }
   for (a = 1; a <= k; ++a)
   {
      for (b = 1; b <= k; ++b)
      {
         bs[a][b] = us[a][b];
      }
   }
}
void d(void)
{
   int a, b, c;
   for (a = 1; a <= k; ++a)
   {
      for (b = 1; b <= k; ++b)
      {
         us[a][b] = 0;
      }
   }
   for (a = 1; a <= k; ++a)
   {
      for (b = 1; b <= k; ++b)
      {
         for (c = 1; c <= k; ++c)
         {
            us[a][b] += g[a][c] * g[c][b];
            us[a][b] %= mod;
         }
      }
   }
   for (a = 1; a <= k; ++a)
   {
      for (b = 1; b <= k; ++b)
      {
         g[a][b] = us[a][b];
      }
   }
}
void pow(int u)
{
   int nw, l;
   for (nw = 1; nw <= u; ++nw)
   {
      l = dy(n[nw]);
      if (l & 1)
      {
         times();
      }
      d();
      if (l & 2)
      {
         times();
      }
      d();
      if (l & 4)
      {
         times();
      }
      d();
      if (l & 8)
      {
         times();
      }
   }
   d();
}

int main()
{
   int i;
   for (i = 1; i <= 25; ++i)
   {
      bs[i][i] = 1;
   }
   long long p, q, r;
   scanf("%d%lld%lld%lld", &k, &p, &q, &r);
   p %= mod;
   q %= mod;
   r %= mod;
   for (i = 0; i < k; ++i)
   {
      scanf("%lld", &g[k - i][k + 1]);
   }
   for (i = 1; i <= k; ++i)
   {
      scanf("%d", &ans[1][i]);
   }
   g[k + 2][k + 1] = p;
   g[k + 3][k + 1] = q;
   g[k + 4][k + 1] = 1;
   g[k + 2][k + 2] = 1;
   g[k + 3][k + 2] = 2;
   g[k + 5][k + 2] = 1;
   g[k + 3][k + 3] = 1;
   g[k + 5][k + 3] = 1;
   g[k + 4][k + 4] = 1;
   g[k + 5][k + 5] = 1;
   ans[1][k + 2] = 1;
   ans[1][k + 3] = 1;
   ans[1][k + 4] = r;
   ans[1][k + 5] = 1;
   for (i = 1; i <= k; ++i)
   {
      g[i + 1][i] = 1;
   }
   for (i = 0; n[i - 1] != '&'; ++i)
   {
      scanf("%1c", &n[i]);
   }
   int u = -- --i;
   for (i = 1; (i << 1) <= u; ++i)
   {
      swap(n[i], n[u - i + 1]);
   }
   int a, b, c;
   ++ ++ ++ ++ ++k;
   for (a = 1; a <= 1; ++a)
   {
      for (b = 1; b <= k; ++b)
      {
         printf("%d ", ans[a][b]);
      }
      printf("\n");
   }
   printf("\n");
   printf("\n");
   for (a = 1; a <= k; ++a)
   {
      for (b = 1; b <= k; ++b)
      {
         printf("%d ", g[a][b]);
      }
      printf("\n");
   }
   printf("\n");
   printf("\n");
   for (a = 1; a <= k; ++a)
   {
      for (b = 1; b <= k; ++b)
      {
         printf("%d ", bs[a][b]);
      }
      printf("\n");
   }
   for (i = 1; i <= u; ++i)
      printf("%c", n[i]);
   pow(u);
   for (a = 1; a <= k; ++a)
   {
      for (b = 1; b <= k; ++b)
      {
         printf("%d ", bs[a][b]);
      }
      printf("\n");
   }
   for (a = 1; a <= k; ++a)
   {
      for (b = 1; b <= k; ++b)
      {
         us[a][b] = 0;
      }
   }
   for (a = 1; a <= 1; ++a)
   {
      for (b = 1; b <= k; ++b)
      {
         for (c = 1; c <= k; ++c)
         {
            us[a][b] += ans[a][c] * bs[c][b];
            us[a][b] %= mod;
         }
      }
   }
   -- -- -- -- --k;
   printf("\n%lld", us[1][k + 1]);
}
