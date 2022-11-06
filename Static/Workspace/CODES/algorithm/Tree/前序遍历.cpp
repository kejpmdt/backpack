#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000006
#define MAXM 2000006
int fst[MAXN],to[MAXM],nt[MAXM];
int dfsn[MAXN];
void dfs1(int nw,int f){
    if(to[fst[nw]]==f){
        fst[nw]=nt[fst[nw]];
    }
    for(int i=fst[nw];i;i=nt[i]){
        if(to[nt[i]]==f){
            nt[i]=nt[nt[i]];
        }
        if(to[i]!=f)dfs1(to[i],nw);
    }
}
void dfs2(int nw){
    static int cnt=0;
    dfsn[nw]=++cnt;
    for(int i=fst[nw];i;i=nt[i])dfs2(to[i]);
}
void addline(int a,int b){
    static int i=0;
    to[++i]=b;nt[i]=fst[a];fst[a]=i;
    to[++i]=a;nt[i]=fst[b];fst[b]=i;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<n;++i){
        int a,b;
        cin>>a>>b;
        addline(a,b);
    }
    dfs1(1,1);
    dfs2(1);
    for(int i=1;i<=n;++i)cout<<dfsn[i]<<' ';
    return 0;
}