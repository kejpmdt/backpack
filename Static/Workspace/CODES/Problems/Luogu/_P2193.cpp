#include<bits/stdc++.h>
using namespace std;
int P;
template<typename A,typename B>A qpow(A a,B n){A ans=1;a%=p;while(n){if(n&1)ans*=a%=p;a*=a%=p,n>>=1;}return ans%p;}
int main(){
    int n,p;
    scanf("%d%d",&p,&n);
    if(n>
