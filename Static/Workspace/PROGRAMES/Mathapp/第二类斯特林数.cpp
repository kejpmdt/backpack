#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long s[1005][1005];
long long S(int n,int k){
    s[1][1]=1;
    for(int i=1;i<n;++i){
        for(int j=1;j<=k;++j){
            s[i+1][j+1]+=s[i][j];
            s[i+1][j+1]%=MOD;
            s[i+1][j]+=s[i][j]*j;
            s[i+1][j]%=MOD;
        }
    }
    return s[n][k]%MOD;
}
int main(){
    int n,k;
    cin>>n>>k;
    
    cout<<S(n,k);
}