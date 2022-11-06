#include <cstdio>
#include <queue>
using namespace std;
bool pd[2000];
queue<int> q;
int main()
{
   int n, m;
   scanf("%d%d", &m, &n);
   int ans = 0;
   int u;
   int nw = 0;
   for (int i = 0; i < n; ++i)
   {
      scanf("%d", &u);
      if (!pd[u])
      {
         ++nw;
         ++ans;
         q.push(u);
         pd[u] = true;
      }
      if (nw > m)
      {
         pd[q.front()] = false;
         q.pop();
         --nw;
      }
   }
   printf("%d", ans);
   return 0;
}
