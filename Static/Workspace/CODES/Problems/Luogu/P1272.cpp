#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 201;
struct Edge
{
   int to, next;
} e[N * 2];
int du[N], a[N], dp[N][N];
int n, k, res = INF, EdgeCnt = 0;
void addedge(int u, int v)
{
   int p = ++EdgeCnt;
   e[p].to = v;
   e[p].next = a[u];
   a[u] = p;
}
void dfs(int nw, int fa)
{
   dp[nw][1] = du[nw];
   for (int p = a[nw]; p; p = e[p].next)
   {
      int v = e[p].to;
      if (v != fa)
      {
         dfs(v, nw);
         for (int j = k; j >= 1; j--)
            for (int k = 1; k <= j; k++)
               dp[nw][j] = min(dp[nw][j], dp[nw][j - k] + dp[v][k] - 2);
      }
   }
   res = min(res, dp[nw][k]);
}
int main()
{
   scanf("%d%d", &n, &k);
   memset(dp, 0x3f, sizeof(dp));
   for (int i = 1; i < n; i++)
   {
      int u, v;
      scanf("%d%d", &u, &v);
      addedge(u, v);
      addedge(v, u);
      du[u]++;
      du[v]++;
   }
   dfs(1, 0);
   printf("%d", res);
   return 0;
}