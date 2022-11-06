#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int x[2][100005];
int main(){
    int t;
    scanf("%d",&t);
    long long ans;
    while(t--){
        x[0][0]=x[1][0]=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        for(int i=1;i<=n;++i)scanf("%d",&x[a[i]][++x[a[i]][0]]);
        sort(x[0]+1,x[0]+x[0][0]+1);
        sort(x[1]+1,x[1]+x[1][0]+1);
        ans=0;
        int i,j;
        i=j=1;
        while(i<=x[0][0]-x[1][0])ans+=x[0][i++];
        while(j<=x[1][0]-x[0][0])ans+=x[1][j++];
        while(i<=x[0][0])ans+=2*x[0][i++];
        while(j<=x[1][0])ans+=2*x[1][j++];
        if(x[0][0]==x[1][0])ans-=min(x[0][1],x[1][1]);;
        cout<<ans<<'\12';
    }
    return 0;
}
        
        
