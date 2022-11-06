#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 10005
#define MAXM 200010
#define INF 2000000
#define mi2(a,b) (a<b?a:b)
int fst[MAXN],nt[MAXM],to[MAXM],v[MAXM];
int dq[MAXN];
int n,m,s,t;
void addline(int i,int a,int b,int c){
   to[i]=b;
   to[i^1]=a;
   v[i]=c;
   v[i^1]=0;
   nt[i]=fst[a];
   nt[i^1]=fst[b];
   fst[a]=i;
   fst[b]=i^1;
}
queue<int>q;
int wei[MAXN];
bool bfs(){
   while(!q.empty()){
      q.pop();
   }
   memset(wei,0x00,sizeof 0);
   wei[s]=1;
   q.push(s);
   int u,i;
   dq[s]=fst[s];
   while(!q.empty()){
      u=q.front();
      q.pop();
      for(i=dq[u];i;i=nt[i]){
         if(!wei[to[i]]&&v[i]>0){
            wei[to[i]]=wei[u]+1;
            dq[to[i]]=fst[to[i]];
            if(to[i]==t){
               return true;
            }
            q.push(to[i]);
         }
      }
   }
   return false;
}
int find(int nw,int li){
   if(nw==t){
      return li;
   }
   int r=0;
   int u;
   for(int i=dq[nw];i&&r<li;i=nt[i]){
      dq[nw]=i;
      if(wei[to[i]]==wei[nw]+1&&v[i]>0){
         u=find(to[i],mi2(li-r,v[i]));
         if(u==0){
            wei[to[i]]=-1;
         }
         v[i]-=u;
         v[i^1]+=u;
         r+=u;
      }
   }
   return r;
}
int dinic(){
   int r=0,u;
   while(bfs()){
      while(u=find(s,INF)){
         r+=u;
      }
   }
   return r;
}
int main(){
   scanf("%d%d%d%d",&n,&m,&s,&t);
   int a,b,c;
   for(int i=1;i<=m;++i){
      scanf("%d%d%d",&a,&b,&c);
      addline(i<<1,a,b,c);
   }
   printf("%d\n",dinic());
   return 0;
}