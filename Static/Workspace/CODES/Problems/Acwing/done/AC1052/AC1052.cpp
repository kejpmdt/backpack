#include<bits/stdc++.h>
using namespace std;
int f[60][60];
string p;
int ne[60];
int main(){
    int n;
    cin>>n;
    cin>>p;
    p=' '+p;
    for(int i=2,j=0;i<=n;++i){
        while(j&&p[i]!=p[j+1])j=ne[j];
        if(p[i]==p[j+1])ne[i]=++j;
    }
    f[0][0]=1;
    for(int i=0;i<=n;++i){
        for(int r=0;r<(int)p.size()-1;++r){
            for(int j=0,k;j<26;++j){
                k=r;
                while(k&&p[k+1]!=j+97)k=ne[k];
                if(p[k+1]==j+97)++k;
                if(k<(int)p.size()) f[i+1][k]=(f[i+1][k]+f[i][r])%1000000007;
            }
        }
    }
    int ans=0;
    for(int i=0;i<(int)p.size()-1;++i){
        ans=(ans+f[n][i])%1000000007;
    }
    cout<<ans;
    return 0;
}