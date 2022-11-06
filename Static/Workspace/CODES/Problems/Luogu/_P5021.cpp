#include<bits/stdc++.h>
#define MAXN 50005
#define MAXM 100005
using namespace std;
int n,m;
int fst[MAXN],nt[MAXM];
int to[MAXM];
int v[MAXM];
int f[MAXN][2];
void addline(int a,int b,int c=1){
    static int i=0;
    to[++i]=b,nt[i]=fst[a],fst[a]=i,v[i]=c;
    to[++i]=a,nt[i]=fst[b],fst[b]=i,v[i]=c;
}
int s[MAXN];
int tp;
bool check(int k){
    tp=0;
    s[++tp]=1;
    int nw;
}
void dfs1(int nw,int f){
    if(to[fst[nw]]==f)fst[nw]=nt[fst[nw]];
    for(int i=fst[nw];i;i=nt[i]){
        if(to[nt[i]]==f)nt[i]=nt[nt[i]];
        dfs1(to[i],nw);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    int a,b,c;
    for(int i=1;i<n;++i){
        scanf("%d%d%d",&a,&b,&c);
        addline(a,b,c);
    }
    dfs1(1,1);
    int l,r;
    l=0,r=100000;
    while(l<r-1){
        if(check(l+r>>1))l=l+r>>1;
        else r=l+r>>1;
    }
    printf("%d",r);
}