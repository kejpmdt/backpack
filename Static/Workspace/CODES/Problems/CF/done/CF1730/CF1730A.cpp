#include<bits/stdc++.h>
using namespace std;
int num[105];
int main(){
    int t,n,k;
    int ans;
    int u;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        while(n--){
            scanf("%d",&u);
            ++num[u];
        }
        ans=0;
        for(int i=1;i<=100;++i){
            ans+=min(k,num[i]);
            num[i]=0;
        }
        cout<<ans<<'\12';
    }
    return 0;
}
