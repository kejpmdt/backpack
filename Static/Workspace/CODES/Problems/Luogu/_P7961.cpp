#include<bits/stdc++.h>
using namespace std;
const int MOD =998244353;
int v[105];
int C[35][35];
int f[105][35][35][105];
int n,m,x;
int qpow(long long a,int n){
    int ans=1;
    while(n){
        if(n&1)ans=ans*a%MOD;
        a=a*a%MOD;
        n>>=1;
    }
    return ans%MOD;
}
int main(){
    scanf("%d%d%d",&n,&m,&x);
    int i,j,k,l,u;
    for(i=0;i<=m;++i)scanf("%d",&v[i]);
    C[0][0]=1;
    for(i=1;i<=n;++i){
        C[i][0]=1;
        for(j=1;j<=n;++j)
            C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    for(i=0;i<=n;i++)
		f[0][i][n-i][0]=C[n][i]*qpow(v[0],n-i)%MOD;
    for(i=0;i<=m;++i)
        for(j=0;j<=n;++j)
            for(k=0;k<=x;++k)
                for(l=0;l<=n;++l)
                    for(u=0;u<=j;++u)
                        f[i+1][j-u][(k>>1)+u][l+(k&1)]+=f[i][j][k][l]*C[j][u]%MOD*qpow(v[i+1],u)%MOD;
    long long ans=0;
    for(k=0;k<=n;++k)
        for(l=0;l<=x;++l)
            ans+=f[m][0][k][l];
    printf("%lld",ans);
    return 0;
}