#include <cstdio>
#include <queue>
#include <cstring>
#define INF 0x3f3f3f3f
#define MAXN 300000
#define MAXM 600000
using namespace std;
#define mi2(a, b) (a < b ? a : b)
int fst[MAXN],nt[MAXM], wei[MAXN],dq[MAXN];
int to[MAXM];
int v[MAXM];
int S, T;
void addline(int i, int a, int b, int c)
{
   to[i] = b;
   to[i ^ 1] = a;
   v[i] = c;
   v[i ^ 1] = 0;
   nt[i] = fst[a];
   nt[i ^ 1] = fst[b];
   fst[a] = i;
   fst[b] = i ^ 1;
}
bool bfs()
{
   queue<int> q;
   int u;
   int i;
   memset(wei, 0x00, sizeof wei);
   q.push(S);
   wei[S] = 1;
   dq[S] = fst[S];
   while (!q.empty())
   {
      u = q.front();
      q.pop();
      for (i = fst[u]; i; i = nt[i])
      {
         if (wei[to[i]] == 0 && v[i] > 0)
         {
            wei[to[i]] = wei[u] + 1;
            dq[to[i]] = fst[to[i]];
            if (to[i] == T)
            {
               return true;
            }
            q.push(to[i]);
         }
      }
   }
   return false;
}
int find(int nw, int li)
{
   if (nw == T)
   {
      return li;
   }
   if (li == 0)
   {
      return 0;
   }
   int ans = 0;
   int u;
   for (int i = dq[nw]; i && ans < li; i = nt[i])
   {
      dq[nw] = i;
      if (wei[to[i]] != wei[nw] + 1 || v[i] == 0)
         continue;
      u = find(to[i], mi2(v[i], li - ans));
      ans += u;
      v[i] -= u;
      v[i ^ 1] += u;
      if (u == 0)
      {
         wei[to[i]] = -1;
      }
   }
   return ans;
}
int dinic()
{
   int ans = 0;
   int x;
   while (bfs())
   {
      while (x = find(S, INF))
      {
         ans += x;
      }
   }
   return ans;
}
template<class T>
void read(T&ans){
   ans=0;
   char us=getchar();
   bool f=false;
   while(us<48||us>57){
      f|=(us==45);
      us=getchar();
   }
   while(us>47&&us<58){
      ans=(ans<<1)+(ans<<3)+(us^48);
      us=getchar();
   }
   ans*=f?-1:1;
   return;
}
template<class T,class ...O>
void read(T&x,O&...oth){
   read(x);
   read(oth...);
}
int main(){
   int n,m,t;
   read(n,m,t);
   int i,j;
   int u;
   int nw=0;
   for(i=1;i<n;++i){
      for(j=1;j<=m;++j){
         read(u);
         addline((++nw)<<1,(i-1)*m+j,i*m+j,u);
      }
   }
   for(i=1;i<=n;++i){
      for(j=1;j<m;++j){
         read(u);
         addline((++nw)<<1,(i-1)*m+j,(i-1)*m+j+1,u);
      }
   }
   int k;
   while(t--){
      read(k){
         
