#include<bits/stdc++.h>
using namespace std;
struct nodea{mutable unsigned int l,r,x;bool operator<(const nodea&oth)const{return l<oth.l;};};
struct nodeb{mutable unsigned int l,r,x,v;bool operator<(const nodeb&oth)const{return l<oth.l;};};
set<nodea>a;
set<nodeb>b;
unsigned int n,m;
set<nodea>::iterator asplit(unsigned int x){
    if(x>n)return a.end();
    set<nodea>::iterator u=--a.upper_bound({x,0,0});
    if(u->l==x)return u;
    unsigned int r=u->r;u->r=x-1;
    return a.insert({x,r,u->x}).first;
}
set<nodeb>::iterator bsplit(unsigned int x){
    set<nodeb>::iterator u=--b.upper_bound({x,0,0});
    if(u->l==x)return u;
    unsigned int r=u->r;u->r=x-1;
    return b.insert({x,r,u->x}).first;
}
void aassign(unsigned int l,unsigned int r,unsigned int x){
    set<nodea>::iterator R=asplit(r+1),L=asplit(l);
    for(set<nodea>::iterator i=L;i!=R;++i){
        for(set<nodeb>::iterator j=b.begin();j!=b.end();++j){
            if(j->x<=i->l)j->v+=(x-i->x)*(i->r-i->l+1);
            else if(j->x<=i->r)j->v+=(x-i->x)*(i->r-j->x+1);
        }
    }
    a.erase(L,R);
    a.insert({l,r,x});
}
void bassign(unsigned int l,unsigned int r,unsigned int x){
    set<nodeb>::iterator R=bsplit(r+1),L=bsplit(l);
    b.erase(L,R);
    b.insert({l,r,x});
}
unsigned int ask(int l,int r){
    unsigned int ans=0;
    set<node>::iterator aR;
    set<node>::iterator bR=bsplit(r+1),bL=bsplit(l);
    set<node>::iterator i,j;
    unsigned int u;
    for(i=bL;i!=bR;++i){
        u=0;
        aR=asplit(i->x+1);
        for(j=a.begin();j!=aR;++j)
            u+=(j->r-j->l+1)*j->x;
        ans+=u*(i->r-i->l+1);
    }
    return ans;
}
template<typename T>void read(T&ans){
    ans=0;char us=getchar();bool f=false;
    while(us<48||us>57){f|=(us==45);us=getchar();}
    while(us>47&&us<58){ans=(ans<<1)+(ans<<3)+(us^48);us=getchar();}
    ans=f?-ans:ans;
}
template<typename T,typename ...O>void read(T&x,O&...oth){read(x);read(oth...);}
template<typename T=signed int>T read(void){T x;read(x);return x;}
int main(){
    unsigned int opt,l,r,x;
    read(n,m);
    for(unsigned int i=1;i<=n;++i){
        read(x);
        a.insert({i,i,x});
    }
    for(unsigned int i=1;i<=n;++i){
        read(x);
        b.insert({i,i,x});
    }
    for(unsigned int i=1;i<=m;++i){
        read(opt,l,r);
        if(opt==3){
            cout<<ask(l,r)<<'\12';
            continue;
        }
        read(x);
        if(opt==1)aassign(l,r,x);
        else bassign(l,r,x);
    }
    return 0;
}




