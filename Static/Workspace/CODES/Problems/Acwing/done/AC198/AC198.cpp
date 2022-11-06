#include<bits/stdc++.h>
using namespace std;
long long ans=0,ans1=0;
long long primes[9]={2,3,5,7,11,13,17,19,23};
int n;
void dfs(int t,long long nw,int r,long long rr){
    if(t==9)return;
    if((rr>ans1)||(rr==ans1&&nw<ans))ans=nw,ans1=rr;
    for(int i=1;i<=r;++i){
        if(nw*primes[t]>n)return;
        nw*=primes[t];
        dfs(t+1,nw,i,rr*(i+1));
    }
    return;
}   
int main(){
    cin>>n;
    dfs(0,1,30,1);
    cout<<ans;
    return 0;
}
