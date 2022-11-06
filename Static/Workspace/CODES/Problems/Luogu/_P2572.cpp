#include<set>
#include<cstdio>
#include<iostream>
using namespace std;
template<class A,class B>struct mpair{mutable A first;mutable B second;bool operator<(const mpair&oth)const{return first<oth.first;}};
set<mpair<int,mpair<int,bool>>>odt;
auto split(int x){
    auto u=--odt.upper_bound({x,{0,false}});
    if(x==u->first)return u;
    auto p=u->second.first;
    u->second.first=x-1;
    return odt.insert({x,{p,u->second.second}}).first;
}
void assign(int l,int r,bool x){
    auto R=split(r+1),L=split(l);
    odt.erase(L,R);
    odt.insert({l,{r,x}});
}
void reserve(int l,int r){
    auto R=split(r+1),L=split(l);
    for(auto i=L;i!=R;++i)i->second.second^=1;
}
int sum(int l,int r){
    auto R=split(r+1),L=split(l);
    int ans=0;
    for(auto i=L;i!=R;++i)if(i->second.second)ans+=i->second.first-i->first+1;
    return ans;
}
int ask(int l,int r){
    auto R=split(r+1),L=split(l);
    int ans=0;
    int nw=0;
    for(auto i=L;i!=R;++i){
        if(i==L||i->second.second!=(--i)->second.second)nw=(++i)->second.first-i->first+1;
        else nw+=(++i)->second.first-i->first+1;
        if(i->second.second)ans=max(ans,nw);
    }
    return ans;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int opt,l,r;
    for(int i=0;i<n;++i){
        scanf("%d",&opt);
        odt.insert({i,{i,opt==1}});
    }
    while(m--){
        scanf("%d%d%d",&opt,&l,&r);
        if(opt==0)assign(l,r,0);
        if(opt==1)assign(l,r,1);
        if(opt==2)reserve(l,r);
        if(opt==3)cout<<sum(l,r)<<'\12';
        if(opt==4)cout<<ask(l,r)<<'\12';
    }
    return 0;
}