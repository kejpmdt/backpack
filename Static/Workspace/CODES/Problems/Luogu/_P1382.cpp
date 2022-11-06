#include<bits/stdc++.h>
using namespace std;
struct block{
    int l,r;
    int h;
    bool operator<(const block&oth)const{
        return h<oth.h;
    }
};
template<class A,class B>struct mpair{mutable A first;mutable B second;bool operator<(const mpair&oth)const{return first<oth.first;}};
set<mpair<mpair<int,int>,int>>ODT;
auto split(int x){
    auto u=--ODT.upper_bound({{x,x},0});
    if(x==u->first.first)return u;
    int r=u->first.second;
    u->first.second=x-1;
    return ODT.insert({{x,r},u->second}).first;
}
void assign(int l,int r,int x){
    auto R=split(r+1),L=split(l);
    ODT.erase(L,R);
    ODT.insert({{l,r},x});
}
block blocks[1000005];
pair<int,int>anss[2000015];
int cnt;
int main(){
    int n;
    scanf("%d",&n);
    ODT.insert({{-1000000005,1000000005},0});
    for(int i=1;i<=n;++i){
        scanf("%d%d%d",&blocks[i].h,&blocks[i].l,&blocks[i].r);
    }
    sort(blocks+1,blocks+n+1);
    for(int i=1;i<=n;++i){
        assign(blocks[i].l,blocks[i].r-1,blocks[i].h);
    }
    int h=0;
    for(auto i:ODT){
        if(i.second==h)continue;
        else{
            anss[++cnt]={i.first.first,h};
            anss[++cnt]={i.first.first,i.second};
            h=i.second;
        }
    }
    cout<<cnt<<'\12';
    for(int i=1;i<=cnt;++i)cout<<anss[i].first<<' '<<anss[i].second<<'\12';
    return 0;
}

