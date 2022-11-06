#include<bits/stdc++.h>
using namespace std;
bool f[105][105];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)for(int j=0;j<=n;++j)cin>>f[i][j];
    for(int i=0;i<n;++i
        for(int j=i+1;j<=n;++j)if(f[j][i]==1)for(int k=i;k<=n;++k)swap(f[j][k],f[i+1][k]);
        for(int j=i+2;j<=n;++j)if(f[j][i]==f[i+1][i])for(int k=i;k<=n;++k)f[j][k]^=f[i+1][k];
    }
    for(int i=n;i>0;--i){
        if(f[i][i-1]==0){
            if(f[i][n]==0)cout<<"Multiple sets of solutions";
            else cout<<"No solution";
            return 0;
        }
        for(int j=1;j<i;++j)if(f[j][i-1])for(int k=j-1;k<=n;++k)f[j][k]^=f[i][k];
    }
    for(int i=1;i<=n;++i)cout<<f[i][n]<<endl;
    return 0;
}