#include<bits/stdc++.h>
using namespace std;
#define MOD 9901LL
map<int,int>cf(int x){map<int,int>res;for(int i=2;i<=x/i;++i)while(x%i==0)++res[i],x/=i;if(x>1)++res[x];return res;}
template<typename A,typename B,typename C>C qpow(A a,B n,C p){C ans=1;a%=p;while(n){if(n&1)ans=(ans*a)%p;a=(C)a*a%p,n>>=1;}return ans%p;}
int sum(int p,int k){
    if(k==1)return 1;
    if(k&1)return (p%MOD*sum(p,k-1)%MOD+1)%MOD;
    else return(qpow(p,k/2,MOD)+1)%MOD*sum(p,k/2)%MOD;
}
map<int,int>ca;
int main(){
    int a,b;
    cin>>a>>b;
    if(a==0){
        cout<<0;
        return 0;
    }
    ca=cf(a);
    int ans=1;
    for(auto i:ca){
        ans*=sum(i.first,i.second*b+1);
        ans%=MOD;
    }
    cout<<ans;
}