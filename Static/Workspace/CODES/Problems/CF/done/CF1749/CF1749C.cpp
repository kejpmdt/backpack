#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T&ans){
    ans=0;char us=getchar();bool f=false;
    while(us!=EOF&&(us<48||us>57)){f|=(us==45);us=getchar();}
    while(us>47&&us<58){ans=(ans<<1)+(ans<<3)+(us^48);us=getchar();}
    ans=f?-ans:ans;
}
template<typename T,typename ...O>void read(T&x,O&...oth){read(x);read(oth...);}
template<typename T=signed int>T read(void){T x;read(x);return x;}
multiset<int>s,u;
bool check(int x){
    u=s;
    while(x--){
        if(u.empty()||*u.begin()>x+1)return false;
        u.erase(--u.upper_bound(x+1));
        u.insert(*u.begin()+x+1);
        u.erase(u.begin());
    }
    return true;
}
int main(){
    int t,n;
    read(t);
    int l,r;
    while(t--){
        read(n);
        s.clear();
        for(int i=1;i<=n;++i){
            read(l);
            s.insert(l);
        }
        l=0,r=n+1;
        while(l<r-1){
            if(check((l+r)>>1))l=(l+r)>>1;
            else r=(l+r)>>1;
        }
        cout<<l<<endl;
    }
}