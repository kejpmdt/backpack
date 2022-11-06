#include<set>
#include<cstdio>
#include<iostream>
using namespace std;
template<class A,class B>struct mpair{mutable A first;mutable B second;bool operator<(const mpair&oth)const{return first<oth.first;}};
set<mpair<int,mpair<int,long long>>>odt;
int n,m;
auto split(int x){
    auto u=--odt.upper_bound({x,{x,0x7fffffffll}});
    if(x==u->first)return u;
    int p=u->second.first;
    u->second.first=x-1;
    return odt.insert({x,{p,u->second.second}}).first;
}
void assign(int l,int r,long long x){
    auto R=split(r+1),L=split(l);
    odt.erase(L,R);
    odt.insert({l,{r,x}});
}
void add(int l,int r,long long x){
    auto R=split(r+1),L=split(l);
    for(auto i=L;i!=R;++i)i->second.second+=x;
}
long long kth(int l,int r,int k){
    set<mpair<long long,int>>u;
    u.clear();
    auto R=split(r+1),L=split(l);
    for(auto i=L;i!=R;++i)u.insert({i->second.second,0}).first->second+=(i->second.first-i->first+1);
    for(auto i:u)if(i.second>=k)return i.first;else k-=i.second;
    return --u.end()->second;
}
long long qpow(long long a,int n,long long p){
    a%=p;
    long long ans=1;
    while(n){
        if(n&1)ans=ans*a%p;
        a=a*a%p;
        n>>=1;
    }
    return ans%p;
}
long long ask(int l,int r,int x,long long y){
    auto R=split(r+1),L=split(l);
    long long ans=0;
    for(auto i=L;i!=R;++i){
        ans=(ans+qpow(i->second.second,x,y)*(i->second.first-i->first+1)%y)%y;
    }
    return ans;
}
signed long long seed,vmax;
signed long long rnd(void){
    signed long long u;
    u=seed;
    seed=(seed*7+13)%1000000007;
    return u;
}
int main(){
    scanf("%d%d%lld%lld",&n,&m,&seed,&vmax);
    int i;
    for(i=1;i<=n;++i)odt.insert({i,{i,rnd()%vmax+1}});
    signed long long opt,l,r,x,y;
    while(m--){
        opt=rnd()%4+1;
        l=rnd()%n+1;
        r=rnd()%n+1;
        if(l>r)swap(l,r);
        if(opt==3)x=rnd()%(r-l+1)+1;
        else x=rnd()%vmax+1;
        if(opt==4)y=rnd()%vmax+1;
        if(opt==1)add(l,r,x);
        if(opt==2)assign(l,r,x);
        if(opt==3)cout<<kth(l,r,x)<<'\12';
        if(opt==4)cout<<ask(l,r,x,y)<<'\12';
    }
    return 0;
}