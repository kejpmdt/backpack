#include<bits/stdc++.h>
using namespace std;
bool pd[1000006];
int primes[1000006],cnt;
template<class T1,class T2>class ODT {
protected:
public:
    struct node{const T1 l;mutable T1 r;mutable T2 x;bool operator<(const node&oth)const{return l<oth.l;};};
    set<node>data;
    typename set<node>::iterator split(const T1&x){
        typename set<node>::iterator u=--data.upper_bound({x,0,0});
        if(u->l==x)return u;
        T1 r=u->r;u->r=x-1;
        return data.insert({x,r,u->x}).first;
    }
    void assign(const T1 l,const T1 r,const T2 x){
        typename set<node>::iterator R=split(r+1),L=split(l);
        data.erase(L,R);
        data.insert({l,r,x});
    }
    ODT(T1 l,T1 r,T2 x=0){data.clear();data.insert({l,r,x});}
    ODT(set<node>s){data=s;}
    ODT(void){data.clear();}
    void operator=(ODT oth){data=oth.Data();}
    const set<node>Data(void){return data;}
    int ask(T1 l,T1 r){
        auto R=split(r+1),L=split(l);
        int ans=0;
        for(auto i=L;i!=R;++i){
            if(i->x)ans+=(i->r-i->l+1);
        }
        return ans;
    }
};

void init(int n){
    pd[1]=true;
    for(int i=2;i<=n;(++i)){
        if(!pd[i])primes[++cnt]=i;
        for(int j=1;primes[j]<=n/i;++j){
            pd[i*primes[j]]=true;
            if(i%primes[j]==0)break;
        }
    }
}
template<typename T>void read(T&ans){
    ans=0;char us=getchar();bool f=false;
    while(us!=EOF&&(us<48||us>57)){f|=(us==45);us=getchar();}
    while(us>47&&us<58){ans=(ans<<1)+(ans<<3)+(us^48);us=getchar();}
    ans=f?-ans:ans;
}
template<typename T,typename ...O>void read(T&x,O&...oth){read(x);read(oth...);}
template<typename T=signed int>T read(void){T x;read(x);return x;}
int main(){
    int t;
    read(t);
    int n,q;
    int i,j;
    ODT<int,bool> u;
    init(1000005);
    int opt,a,b,c;
    while(t--){
        u.data.clear();
        read(n,q);
        for(i=1;i<=n;(++i)){
            read(j);
            u.data.insert({i,i,!pd[j]});
        }
        while(q--){
            read(opt);
            if(opt==0){
                read(a,b,c);
                u.assign(a,b,!pd[c]);
            }
            else{
                read(a,b);
                cout<<u.ask(a,b);
            }
        }
    }
}