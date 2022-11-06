#include<bits/stdc++.h>
using namespace std;
template<class A,class B>struct mpair{mutable A first;mutable B second;bool operator<(const mpair&oth)const{return first<oth.first;}};
#define MAXN 100005
vector<int>tos[MAXN];
int zpld[MAXN],sz[MAXN],bigc[MAXN],dfsn[MAXN],fa[MAXN];
void dfs1(int nw){
    sz[nw]=1;
    for(auto i:tos[nw]){
        dfs1(i);
        sz[nw]+=sz[i];
        if((sz[i]>sz[bigc[nw]])||bigc[nw]==0)bigc[nw]=i;
    }
}
void dfs2(int nw,int ld){
    static int x=0;
    zpld[nw]=ld;
    dfsn[nw]=++x;
    if(!bigc[nw])return;
    dfs2(bigc[nw],ld);
    for(auto i:tos[nw]){
        if(i==bigc[nw])continue;
        dfs2(i,i);
    }
}
set<mpair<mpair<int,int>,int>>odt;
auto split(int x){
    auto u=--odt.upper_bound({{x,x},0});
    if(x==u->first.first)return u;
    int r=u->first.second;
    u->first.second=x-1;
    return odt.insert({{x,r},u->second}).first;
}
int ask(int l,int r){
    auto R=split(r+1),L=split(l);
    int ans=0;
    for(auto i=L;i!=R;++i)ans+=(i->first.second-i->first.first+1)*i->second;
    return ans;
}
void assign(int l,int r,int x){
    auto R=split(r+1),L=split(l);
    odt.erase(L,R);
    odt.insert({{l,r},x});
}
int uninstall(int x){
    int res=ask(dfsn[x],dfsn[x]+sz[x]-1);
    assign(dfsn[x],dfsn[x]+sz[x]-1,0);
    return res;
}
int install(int x){
    int ans=0;
    ans=ans+dfsn[x]-dfsn[zpld[x]]+1-ask(dfsn[zpld[x]],dfsn[x]);
    assign(dfsn[zpld[x]],dfsn[x],1);
    do{
        x=fa[zpld[x]];
        ans=ans+dfsn[x]-dfsn[zpld[x]]+1-ask(dfsn[zpld[x]],dfsn[x]);
        assign(dfsn[zpld[x]],dfsn[x],1);
    }while(x);
    
    return ans;
}
int n;
int main(){
    string opt;
    int u;
    scanf("%d",&n);
    int q;
    odt.insert({{1,n},0});
    for(int i=1;i<n;++i){
        scanf("%d",&fa[i]);
        tos[fa[i]].push_back(i);
    }
    dfs1(0);
    dfs2(0,0);
    scanf("%d",&q);
    while(q--){
        cin>>opt;
        scanf("%d",&u);
        if(opt=="install")
            cout<<install(u)<<'\12';
        else 
            cout<<uninstall(u)<<'\12';
    }
    return 0;
}
