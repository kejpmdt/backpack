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
int costs[1000006];
int main(){
    int n;
    read(n);
    long long ans=0;
    int l,r;
    for(int i=1;i<=n;++i){
        read(l,r);
        ans+=r;
        costs[i]=r+l;
    }
    sort(costs+1,costs+n+1);
    for(int i=1;i<=n/2;++i){
        ans-=costs[i];
    }
    cout<<ans;
}