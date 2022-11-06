#include <bits/stdc++.h>
using namespace std;
template<class T1,class T2>class ODT {
protected:
    struct node{const T1 l;mutable T1 r;mutable T2 x;bool operator<(const node&oth)const{return l<oth.l;};};
    set<node>data;
public:
    friend class ODT_actor;
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
};