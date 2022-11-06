#include<bits/stdc++.h>
using namespace std;
bool pd[1000006];
int phi[1000006];
int main(){
    int n;
    long long ans=1;
    cin>>n;
    for(int i=2;i<=n;++i){
        if(!pd[i])phi[i]=i-1;
        ans+=phi[i];
        for(int j=2;j<=n/i;++j){
            if(pd[j])continue;
            pd[i*j]=true;
            phi[i*j]=phi[i]*j;
            if(i%j==0)break;
            phi[i*j]=phi[i*j]*(j-1)/j;
        }
    }
    cout<<ans;
    return 0;
}