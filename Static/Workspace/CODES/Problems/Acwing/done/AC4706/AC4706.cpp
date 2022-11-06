#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define MAXM 2000005
int fst[MAXN],nt[MAXM];
int to[MAXM];
int v[MAXM];
void addline(int a,int b,int c=1){
    static int i=0;
    to[++i]=b,nt[i]=fst[a],fst[a]=i,v[i]=c;
    to[++i]=a,nt[i]=fst[b],fst[b]=i,v[i]=c;
}
long long dis[MAXN];
long long mx;
void dfs(int nw,int f){
    for(int i=fst[nw];i;i=nt[i]){
        if(to[i]==f)continue;
        dis[to[i]]=dis[nw]+v[i];
        mx=max(mx,dis[to[i]]);
        dfs(to[i],nw);
    }
}
int main(){
    int n;
    cin>>n;
    int x,y,w;
    long long ans=0;
    for(int i=1;i<n;++i){
        cin>>x>>y>>w;
        addline(x,y,w);
        ans+=w*2;
    }
    dfs(1,1);
    cout<<ans-mx;
    return 0;
}