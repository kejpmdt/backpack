#include<bits/stdc++.h>
using namespace std;
template<typename A,typename B>A qpow(A a,B n){A ans=1;while(n){if(n&1)ans*=a;a*=a,n>>=1;}return ans;}
template<typename A,typename B,typename C>C qpow(A a,B n,C p){C ans=1;a%=p;while(n){if(n&1)ans=(ans*a)%p;a=(C)a*a%p,n>>=1;}return ans%p;}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,c,k,p=200907;
        cin>>a>>b>>c>>k;
        if(a-b==b-c)cout<<((b-a)*(k-1)+a)%p<<endl;
        else cout<<a*qpow(b/a,k-1,p)%p<<endl;
    }
    return 0;
}

