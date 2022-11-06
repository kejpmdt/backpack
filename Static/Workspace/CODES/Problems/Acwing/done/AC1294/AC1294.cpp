#include<bits/stdc++.h>
using namespace std;
bool pd[1000006];
int mim[1000006];
void init(int n){
    pd[1]=true;
    for(int i=2;i<=n;++i){
        for(int j=2;j<=n;++j){
            if(pd[j])continue;
            pd[i*j]=true;
            mim[i*j]=j;
            if(i%j==0)break;
        }
    }
}
int cf[1000006];
int solve(int n){
    for(int i=1;i<=n;++i)cf[i]=2;
    long long ans=1;
    for(int i=n;i>=1;--i){
        if(!pd[i])ans=ans*(cf[i]+1)%1000000007;
        cf[i/mim[i]]+=cf[i];
        cf[mim[i]]+=cf[i];
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    init(n);
    cout<<solve(n);
}