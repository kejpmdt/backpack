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
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename A,typename B>A qpow(A a,B n){A ans=1;while(n){if(n%(B)2)ans*=a;a*=a,n>>=1;}return ans;}
template<typename A,typename B,typename C>C qpow(A a,B n,C p){C ans=1;a%=p;while(n){if(n%(B)2)ans=(ans*a)%p;a=(C)a*a%p,n>>=1;}return ans%p;}
template<typename T1,typename T2,typename T3,typename T4=T3,class T0=T1>T0 exgcd(T1 a,T2 b,T3&x,T4&y=*new T3){if(!b){x=1,y=0;return a;}T0 d=exgcd(b,a%b,y,x);y-=a/b*x;return d;}
template<typename T>T phi(T x){set<int>s;T ans=x;for(int i=2;i<=x/i;++i)while(x%i==0){if(s.insert(i).second)ans=ans*(i-1)/i;x/=i;}if(x>1)if(s.insert(x).second)ans=ans*(x-1)/x;return ans;}
template<typename T1,typename T2=signed int>map<T1,T2>cf(T1 x){map<T1,T2>res;for(T1 i=2;i<=x/i;++i)while(x%i==0)++res[i],x/=i;if(x>1)++res[x];return res;}
int main(){
    long long n;
    read(n);
    long long a,b;
    for(int i=1;i<n;++i)read(a,b);
    long long t;
    read(t);
    long long x;
    while(t--){
        read(x);
        //cout<<"|";
        if(x%(n-1)==1)cout<<((x-1)/(n-1))*2+3<<'\12';
        else cout<<(x-1)/(n-1)*2+4<<'\12';
        //cout<<x+n-1<<'\12';
    }
    return 0;
}
/*
5
1 1 1 1 1 2
2 1 1 1 1 3 1
2 2 1 1 1 4 2
2 2 2 1 1 4 3
2 2 2 2 1 4 4
2 2 2 2 2 4 5
3 2 2 2 2 5
3 3 2 2 2 6
3 3 3 2 2 6
3 3 3 3 2 6
3 3 3 3 3 6

3 1
4 2
4 3
4 4
4 5

5
6
6
6
6


*/