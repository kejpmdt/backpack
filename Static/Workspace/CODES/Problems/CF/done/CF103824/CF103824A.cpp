#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T&ans){
    ans=0;char us=getchar();bool f=false;
    while(us!=EOF&&(us<48||us>57)){f|=(us==45);us=getchar();}
    while(us>47&&us<58){ans=(ans<<1)+(ans<<3)+(us^48);us=getchar();}
    ans=f?-ans:ans;
}
template<typename T,typename ...O>void read(T&x,O&...oth){read(x);read(oth...);}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
int main(){
    long long a,b;
    int t;
    read(t);
    while(t--){
        read(a,b);
        cout<<a+a+b<<' '<<a+b<<endl;
    }
    return 0;
}