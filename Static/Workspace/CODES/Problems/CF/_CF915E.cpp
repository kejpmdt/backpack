#include<bits/stdc++.h>
using namespace std;
struct node{mutable int l,r,x;bool operator<(const node&oth)const{return l<oth.l;};};
set<node>odt;
set<node>::iterator split(int x){
    set<node>::iterator u=--odt.upper_bound({x,0,0});
    if(u->l==x)return u;
    int r=u->r;u->r=x-1;
    return odt.insert({x,r,u->x}).first;
}
int nw;
void assign(int l,int r,int x){
    set<node>::iterator R=split(r+1),L=split(l);
    for(set<node>::iterator it=L;it!=R;++it)nw+=(it->r-it->l+1)*(x-it->x);
    odt.erase(L,R);
    odt.insert({l,r,x});
}
int main(){
    int q,l,r,k;
    scanf("%d%d",&nw,&q);
    odt.insert({1,nw,1});
    while(q--){
        scanf("%d%d%d",&l,&r,&k);
        assign(l,r,k-1);
        cout<<nw<<'\12';
    }
    return 0;
}
