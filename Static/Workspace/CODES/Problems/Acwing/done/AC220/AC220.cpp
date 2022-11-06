#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000007
bool pd[MAXN];
long long phi[MAXN];
void init(int n){
    pd[1]=true;
    phi[1]=1;
    for(int i=2;i<=n;++i){
        if(!pd[i])phi[i]=i-1;
        for(int j=2;j<=n/i;++j){
            if(pd[j])continue;
            pd[i*j]=true;
            phi[i*j]=phi[i]*j;
            if(i%j==0)break;
            phi[i*j]=phi[i]*(j-1);  
        }
    }
    for(int i=1;i<=n;++i)phi[i]+=phi[i-1];
}
int main(){
    int n;
    cin>>n;
    init(n);
    long long ans=0;
    for(int i=1;i<=n;++i){
        if(pd[i])continue;
        ans+=phi[n/i]*2-1;
    }
    cout<<ans;
}
