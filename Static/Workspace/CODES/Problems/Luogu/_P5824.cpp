#include<bits/stdc++.h>
#define C(n,m) (jc[n]*jcny[m]%MOD*jcny[n-m]%MOD)
#define MOD 998244353ll
using namespace std;
template<typename A,typename B>A qpow(A a,B n){A ans=1;while(n){if(n&1)ans*=a;a*=a,n>>=1;}return ans;}
template<typename A,typename B,typename C>C qpow(A a,B n,C p){C ans=1;a%=p;while(n){if(n&1)ans*=a%=p;a*=a%=p,n>>=1;}return ans%p;}
long long jc[500005];
long long jcny[500005];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    jc[0]=1;
    for(int i=1;i<=n+m+2;++i)jc[i]=jc[i-1]*i%MOD;
    jcny[n+m+2]=qpow(jc[n+m+2],MOD-2,MOD);
    for(int i=n+m+2;i>0;--i)jcny[i-1]=jcny[i]*i%MOD;
    for(int i=0;i<=n+m+2;++i)
        cout<<jc[i]*jcny[i]%MOD<<endl;
    cout<<qpow(m,n,MOD)<<'\12';
    cout<<((m>=n)?jc[m]*jcny[m-n]%MOD:0)<<'\12';
    cout<<((m<=n)?-1:0)<<'\12';

    cout<<-1<<'\12';
    cout<<((m>=n)?-1:0)<<'\12';
    cout<<((m<=n)?-1:0)<<'\12';

    cout<<C(n+m-1,m-1)<<'\12';
    cout<<((m>=n)?-1:0)<<'\12';
    cout<<((m<=n)?C(n-1,m-1):0)<<'\12';

    cout<<-1<<'\12';
    cout<<((m>=n)?-1:0)<<'\12';
    cout<<((m<=n)?-1:0)<<'\12';
    return 0;
}