#include<bits/stdc++.h>
using namespace std;
template<class A,class B>struct mpair{mutable A first;mutable B second;bool operator<(const mpair&oth)const{return first<oth.first;}};
set<mpair<mpair<int,int>,long long>>ODT;
int n,m;
auto split(int x){
    auto u=--ODT.upper_bound({{x,x},0});
    if(x==u->first.first)return u;
    int r=u->first.second;
    u->first.second=x-1;
    return ODT.insert({{x,r},u->second}).first;
}
void assign(int l,int r,long long x){
    auto R=split(r+1),L=split(l);
    ODT.erase(L,R);
    ODT.insert({{l,r},x});
}
void add(int l,int r,long long x){
    auto R=split(r+1),L=split(l);
    for(auto i=L;i!=R;++i)i->second+=x;
}
long long ask(int l,int r){
    auto R=split(r+1),L=split(l);
    long long ans=0x8000000000000000;
    for(auto i=L;i!=R;++i)ans=max(ans,i->second);
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    int u;
    long long x;
    for(int i=1;i<=n;++i){
        scanf("%lld",&x);
        ODT.insert({{i,i},x});
    }
    int l,r;
    while(m--){
        scanf("%d",&u);
        if(u==1){
            scanf("%d%d%lld",&l,&r,&x);
            assign(l,r,x);
        }
        if(u==2){
            scanf("%d%d%lld",&l,&r,&x);
            add(l,r,x);
        }
        if(u==3){
            scanf("%d%d",&l,&r);
            cout<<ask(l,r)<<'\12';
        }
    }
    return 0;
}
