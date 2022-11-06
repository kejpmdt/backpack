#include<bits/stdc++.h>
using namespace std;
template<typename A,typename B>A qpow(A a,B n){A ans=1;while(n){if(n%(B)2)ans*=a;a*=a,n>>=1;}return ans;}
template<typename A,typename B,typename C>C qpow(A a,B n,C p){C ans=1;a%=p;while(n){if(n%(B)2)ans=(ans*a)%p;a=(C)a*a%p,n>>=1;}return ans%p;}
template<typename A,typename B,typename T>T C(A a,B b,T p){T ans=1;for(A i=a-b+1;i<=a;++i)ans=ans*i%p;for(A i=1;i<=b;++i)ans=ans*qpow(i,p-2,p)%p;return ans;}
template<typename A,typename B>A C(A a,B b){A ans=1;for(A i=a-b+1;i<=a;++i)ans=ans*i;for(A i=1;i<=b;++i)ans=ans/i;return ans;}
int main(){
    long long a,b;
    cin>>a>>b;
    long long ans=0;
    for(long long i=0;i<b;++i){
        if(i&1)ans-=C(b,i)*qpow(b-i,a);
        else ans+=C(b,i)*qpow(b-i,a);
    }
    cout<<ans;
    return 0;
}