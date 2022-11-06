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
template<typename A,typename B>A qpow(A a,B n){A ans=1;while(n){if(n%(B)2)ans*=a;a*=a,n>>=1;}return ans;}
template<typename A,typename B,typename C>C qpow(A a,B n,C p){C ans=1;a%=p;while(n){if(n%(B)2)ans=(ans*a)%p;a=(C)a*a%p,n>>=1;}return ans%p;}
template<typename T>T phi(T x){set<int>s;T ans=x;for(int i=2;i<=x/i;++i)while(x%i==0){if(s.insert(i).second)ans=ans*(i-1)/i;x/=i;}if(x>1)if(s.insert(x).second)ans=ans*(x-1)/x;return ans;}
int main(){
    int t;
    cin>>t;
    long long l,r;
    while(t--){
        read(l,r);
        cout<<(l+r)%9*(r-l+1)%9*qpow(2,phi(9)-1,9)%9<<endl;
    }

}