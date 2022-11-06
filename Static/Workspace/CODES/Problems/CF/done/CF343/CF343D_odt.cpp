#include<bits/stdc++.h>
using namespace std;
struct node{
    int l;
    mutable int r,color;
    bool operator<(const node&oth)const{
        return l<oth.l;
    }
};
set<node>odt;
#define MAXN 500005
#define MAXM 1000005
int fst[MAXN],nt[MAXM];
int to[MAXM];
int zpld[MAXN],bigc[MAXN],depth[MAXN],fa[MAXN],dfsn[MAXN];
int weight[MAXN];
int data[MAXN];
void addline(int a,int b,int c=1){
    static int i=0;
    to[++i]=b,nt[i]=fst[a],fst[a]=i;
    to[++i]=a,nt[i]=fst[b],fst[b]=i;
}
void dfs1(int nw,int f){
    weight[nw]=1;
    fa[nw]=f;
    depth[nw]=depth[f]+1;
    if(to[fst[nw]]==f)fst[nw]=nt[fst[nw]];
    int i;
    for(i=fst[nw];i;i=nt[i]){
        if(to[nt[i]]==f)nt[i]=nt[nt[i]];
        dfs1(to[i],nw);
        weight[nw]+=weight[to[i]];
        if(weight[to[i]]>weight[bigc[nw]])bigc[nw]=to[i];
    }
}
void dfs2(int nw,int ld){
    static int x=0;
    dfsn[nw]=++x;
    zpld[nw]=ld;
    if(!bigc[nw])return;
    dfs2(bigc[nw],ld);
    int i;
    for(i=fst[nw];i;i=nt[i])if(to[i]!=bigc[nw])dfs2(to[i],to[i]);
}
set<node>::iterator split(int pos){
    auto x=--odt.upper_bound({pos});
    if(pos==x->l)return x;
    odt.insert({pos,x->r,x->color});
    x->r=pos-1;
    return ++x;
}
void assign(int l,int r,int color){
    auto lx=split(l),rx=split(r+1);
    odt.erase(lx,rx);
    odt.insert({l,r,color});
}
void changesubtree(int u){
    assign(dfsn[u],dfsn[u]+weight[u]-1,1);
}
void changepath(int u){
    while(1){
        if(zpld[u]==1){
            assign(dfsn[1],dfsn[u],0);
            return;
        }
        else {
            assign(dfsn[zpld[u]],dfsn[u],0);
            u=fa[zpld[u]];
        }
    }
}
int ask(int u){
    return (--odt.upper_bound({dfsn[u]}))->color;
}
int n;
int main(){
    int a,b;
    scanf("%d",&n);
    odt.insert({1,n,0});
    for(int i=1;i<n;++i)scanf("%d%d",&a,&b),addline(a,b);
    dfs1(1,1);
    dfs2(1,1);
    int m;
    scanf("%d",&m);
    while(m--){
        scanf("%d%d",&a,&b);
        switch(a){
            case 1:changesubtree(b);break;
            case 2:changepath(b);break;
            case 3:printf("%d\n",ask(b));break;
        }
    }
}
