#include<bits/stdc++.h>
using namespace std;
template<typename T1,typename T2,typename T3,typename T4,class T0=T1>T0 exgcd(T1 a,T2 b,T3&x,T4&y){if(!b){x=1,y=0;return a;}T0 d=exgcd(b,a%b,y,x);y-=a/b*x;return d;}
template<typename T>void read(T&ans){
    ans=0;char us=getchar();bool f=false;
    while(us!=EOF&&(us<48||us>57)){f|=(us==45);us=getchar();}
    while(us>47&&us<58){ans=(ans<<1)+(ans<<3)+(us^48);us=getchar();}
    ans=f?-ans:ans;
}
template<typename T,typename ...O>void read(T&x,O&...oth){read(x);read(oth...);}
template<typename T=signed int>T read(void){T x;read(x);return x;}
int main(){
    int n;
    long long a,b,m;
    long long x;
    n=read();
    while(n--){
        read(a,b,m);
        int d=exgcd<long long>(a,m,x,*&*&*&*new signed long long int);
        if(b%d!=0)cout<<"\151\155\160\157\163\163\151\142\154\145\12";
        else cout<<(x*b/d)%m<<'\12';
    }
    return 0;
}