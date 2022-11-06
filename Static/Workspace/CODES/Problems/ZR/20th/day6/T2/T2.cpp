#include<bits/stdc++.h>
using namespace std;
multiset<int>s;
template<typename T>void read(T&ans){
    ans=0;char us=getchar();bool f=false;
    while(us!=EOF&&(us<48||us>57)){f|=(us==45);us=getchar();}
    while(us>47&&us<58){ans=(ans<<1)+(ans<<3)+(us^48);us=getchar();}
    ans=f?-ans:ans;
}
template<typename T,typename ...O>void read(T&x,O&...oth){read(x);read(oth...);}
template<typename T=signed int>T read(void){T x;read(x);return x;}
int a[500005];

int main(){
    int n,k;
    read(n,k);
    int i;
    for(i=1;i<=n;++i)read(a[i]);
    s.clear();
    for(i=1;i<k;++i)s.insert(a[i]+a[i+1]);
    int ans=0x7fffffff;
    for(i=k;i<=n;++i){
        ans=min(ans,max(*--s.end(),a[i]+a[i-k+1]));
        s.erase(s.find(a[i-k+1]+a[i-k+2]));
        s.insert(a[i]+a[i+1]);
    }
    cout<<ans;
}