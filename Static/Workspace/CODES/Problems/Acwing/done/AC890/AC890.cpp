#include<bits/stdc++.h>
using namespace std;
long long p[20];
int main(){
    int n,m;
    cin>>n>>m;
    long long u;
    int ans=0;
    for(int i=1;i<=m;++i)cin>>p[i];
    for(int i=1;i<1<<m;++i){
        u=-1;
        for(int j=1;j<=m;++j){
            if(((1<<(j-1))&i)!=0){
                u*=-1;
                u*=p[j];
                if(u>n){
                    u=n+1;
                    break;
                }
            }
        }
        ans+=n/u;
    }
    cout<<ans;
}

