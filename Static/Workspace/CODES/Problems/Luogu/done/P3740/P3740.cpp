#include<bits/stdc++.h>
using namespace std;
template<typename A,typename B>struct mpair{mutable A first;mutable B second;bool operator <(const mpair&oth)const{return first<oth.first;}};
set<mpair<mpair<int,int>,short>>ODT;
auto split(int x){
    auto u=--ODT.upper_bound({{x,x},0});
    if(x==u->first.first)return u;
    int r=u->first.second;
    u->first.second=x-1;
    return ODT.insert({{x,r},u->second}).first;
}
void assign(int l,int r,short x){
    auto R=split(r+1),L=split(l);
    ODT.erase(L,R);
    ODT.insert({{l,r},x});
}
bool pd[2005];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    ODT.insert({{1,n},0});
    int l,r;
    for(short i=1;i<=m;++i){
        scanf("%d%d",&l,&r);
        assign(l,r,i);
    }
    short ans=0;
    for(auto i:ODT){
        if(i.second&&!pd[i.second])++ans;
        pd[i.second]=true;
    }
    cout<<ans<<'\12';
    return 0;
}
