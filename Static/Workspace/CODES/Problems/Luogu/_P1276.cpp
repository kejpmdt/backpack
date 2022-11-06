#include<bits/stdc++.h>
using namespace std;
struct node{
    mutable int l,r,x;
    node(int L,int R,int X):l(L),r(R),x(X){}
    bool operator<(const node&oth)const{return l<oth.l;}
};
set<node>odt;

