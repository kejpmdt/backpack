#include <cstdio>
#include <algorithm>
#define MAXN 10
#define MAXM 5
#define MAXX 10
using namespace std;
int main()
{
   int n;
   freopen("seed.txt", "r", stdin);
   scanf("%d", &n);
   srand(n);
   fclose(stdin);
   freopen("seed.txt", "w", stdout);
   printf("%d", n);
   freopen("in.txt", "w", stdout);
   n = rand() % MAXN;
   int m = rand() % MAXM;
   printf("%d %d\n", n, m);
   for (int i = 1; i < n; ++i)
   {
      printf("%d %d %d\n", i + 1, rand() % i + 1, rand() % MAXX + 1);
   }
   for (int i = 1; i <= m; ++i)
   {
      printf("%d %d\n", rand() % n + 1, rand() % n + 1);
   }
   return 0;
}