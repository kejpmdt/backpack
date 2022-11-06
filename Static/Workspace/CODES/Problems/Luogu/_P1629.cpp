#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 1005
#define MAXM 100005
using namespace std;
int dis[MAXN];
int fst[MAXN];
int nt[MAXM];
int to[MAXM];
int v[MAXM];
int ndis[MAXN];
int nfst[MAXN];
int nnt[MAXN];
int nto[MAXN];
struct node
{
   int num;
   bool operator<(node x) const
   {
      return dis[x.num] > dis[num];
   }
};
struct nnode
{
   int num;
   bool operator<(nnode x) const
   {
      return ndis[x.num] > ndis[num];
   }
};
priority_queue<node> q;
priority_queue<nnode> nq;
node newnode(int num)
{
   node x;
   x.num = num;
   return x;
}
nnode newnnode(int num)
{
   nnode x;
   x.num = num;
   return x;
}  
bool used[MAXN];
int main()
{
   int n, m;
   scanf("%d%d", &n, &m);
   memset(dis, 0x3f, sizeof dis);
   memset(ndis, 0x3f, sizeof ndis);
   dis[1] = ndis[1] = 0;
   int i;
   for (i = 1; i <= m; i++)
   {
      scanf("%d%d%d", &nto[i], &to[i], &v[i]);
      nt[i] = fst[nto[i]];
      nnt[i] = nfst[to[i]];
      fst[nto[i]] = i;
      nfst[to[i]] = i;
   }
   q.push(newnode(1));
   nq.push(newnnode(1));
   int u;
   while (!q.empty())
   {
      u = q.top().num;
      q.pop();
      for (i = fst[u]; i; i = nt[i])
      {
         if (dis[u] + v[i] < dis[to[i]])
         {
            dis[to[i]] = dis[u] + v[i];
            if (!used[to[i]])
            {
               q.push(newnode(to[i]));
               used[to[i]] = true;
            }
         }
      }  
   }
   memset(used, 0, sizeof used);
   while (!nq.empty())
   {
      u = nq.top().num;
      nq.pop();
      for (i = fst[u]; i; i = nt[i])
      {
         if (ndis[u] + v[i] < ndis[to[i]])
         {
            ndis[to[i]] = ndis[u] + v[i];
            if (!used[to[i]])
            {
               nq.push(newnnode(to[i]));
               used[to[i]] = true;
            }
         }
      }
   }
   int ans = 0;
   for (i = 1; i <= n; ++i)
   {
      ans += dis[i];
      ans += ndis[i];
   }
   printf("%d\n", ans);
   return 0;
}
 