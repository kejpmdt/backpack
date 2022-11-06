#include<iostream>
#include<cstdio>
using namespace std;
int fa[1005];
bool pd[1005];
bool sz[1005];
int getfa(int nw){
    if(fa[fa[nw]]!=fa[nw])fa[nw]=getfa(fa[nw]);
    return fa[nw];
}
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;++i){
        int u;
        scanf("%d",&u);
        pd[u]=true;
    }
    for(int i=1;i<=n;++i){
        fa[i]=i;
        pf[i]=true;
        sz[i]=1;
    }
    int u,v;
    for(int i=1;i<=m;++i){
        scanf("%d%d",&u,&v);
        if(getfa(u)==getfa(v))continue;
        fa[getfa(u)]=fa[getfa(v)];
        pd[fa[v]]|=pd[fa[u]];
        sz[fa[v]]+=sz[fa[u]];
    }
    int num=0,sum=0;
    for(int i=1;i<=n;++i){
        if(!pd[i]){
            sum+=sz[i];
        }
        else{
            if(pd
