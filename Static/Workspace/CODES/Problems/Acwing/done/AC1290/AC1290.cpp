#include<bits/stdc++.h>
using namespace std;
#define MOD(a,b) ((a)%b+b)%b
#define ll long long
ll qpow(ll a,ll b,ll p){
    ll ans=1;
    a%=p;
    while(b){
        if(b&1)ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ans%p;
}
int main(){
    ll m,n;
    ll p=100003;
    cin>>m>>n;
    cout<<MOD(qpow(m,n,p)-m*qpow(m-1,n-1,p),p);
}