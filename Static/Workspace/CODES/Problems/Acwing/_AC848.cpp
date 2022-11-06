#include<cstdio>
#include<iostream>
#define MAXN 100005
#define MAXM 100005
using namespace std;
int fst[MAXN],nt[MAXM];
int to[MAXM];
int ins[MAXN];
int topsort[MAXN];
void addline(int a,int b){
    static int i=0;
    to[++i]=b,nt[i]=fst[a],fst[a]=i;
    ++ins[b];
}
void dfs(int nw){
    static int x=0;
    topsort[++x]=nw;
    ins[nw]=-1;
    for(int i=fst[nw];i;i=nt[i]){
        --ins[to[i]];
        if(ins[to[i]]==0)dfs(to[i]);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        addline(a,b);
    }
    for(int i=1;i<=n;++i){
        if(ins[i]==0)dfs(i);
    }
    if(topsort[n]==0)printf("-1");
    else for(int i=1;i<=n;++i)printf("%d ",topsort[i]);
}