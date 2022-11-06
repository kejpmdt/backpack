#include<bits/stdc++.h>
using namespace std;
unsigned long long C[105][105];
int main(){
    C[0][0]=1;
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=1;i<=100;++i){
        C[i][0]=1;
        for(int j=1;j<=100;++j){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    long long ans=1;
    for(int i=0;i<=a;++i){
        for(int j=0;j<=b;++j){
            ans=ans+C[n+i-1][n-1]*C[n+j-1][n-1];
        }
    }
    cout<<ans;
}