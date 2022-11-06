#include<bits/stdc++.h>
#define MAXN 500005
#define MAXM 1000005
using namespace std;
#define int long long
int fst[MAXN],nt[MAXM];
int to[MAXM];
int depth[MAXN],fa[MAXN];
int up[MAXN];
struct line{
    int a,b,c;
    int ans;
    int nt;
}lines[MAXN];
void addline(int a,int b,int x){
    int i=(x<<1)-1;
    to[++i]=b,nt[i]=fst[a],fst[a]=i,fa[i]=i;
    to[++i]=a,nt[i]=fst[b],fst[b]=i,fa[i]=i;
}
void dfs(int nw,int f){
    depth[nw]=depth[f]+1;
    if(to[fst[nw]]==f)up[nw]=fst[nw],fst[nw]=nt[fst[nw]];
    int i;
    for(i=fst[nw];i;i=nt[i]){
        if(to[nt[i]]==f)up[nw]=nt[i],nt[i]=nt[nt[i]];
        dfs(to[i],nw);
    }
}
int getfa(int x){
    if(fa[fa[x]]!=fa[x])fa[x]=getfa(fa[x]);
    return fa[x];
}
void change(int a,int b){
    a=up[a],b=up[b];
    while(1){
        if(to[a]==to[b]){
            if(lines[a>>1].ans==0)lines[a>>1].ans=-1;
            if(lines[b>>1].ans==0)lines[b>>1].ans=-1;
            return;
        }
        if(depth[to[a]]<depth[to[b]]){
            swap(a,b);
        }
        if(lines[a>>1].ans==0)lines[a>>1].ans=-1;
        fa[a]=up[to[a]];
        a=getfa(a);
    }
}
int n,m;
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;++i){
        lines[i-1].nt=i;
        scanf("%lld%lld%lld",&lines[i].a,&lines[i].b,&lines[i].c);
        if(lines[i].c==1)addline(lines[i].a,lines[i].b,i);
    }
    dfs(1,1);
    int num=0;
    for(int i=1;i<=m;++i){
        if(lines[i].ans!=0)continue;
        if(lines[i].c==1)lines[i].ans=++num;
        else{
            change(lines[i].a,lines[i].b);
            for(int nw=0;lines[nw].nt!=0;nw=lines[nw].nt){
                if(lines[lines[nw].nt].ans==-1){
                    lines[lines[nw].nt].ans=++num;
                    lines[nw].nt=lines[lines[nw].nt].nt;
                }
            }
            lines[i].ans=++num;
        }
    } 
    for(int i=1;i<=m;++i){
        printf("%lld ",lines[i].ans);
    }
    return 0;
}