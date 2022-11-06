#include<bits/stdc++.h>
using namespace std;
int a[300];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int ans=0x7fffffff;
        for(int i=2;i<n;++i){
            ans=min(ans,a[i+1]-a[i-1]);
        }
        cout<<ans<<'\12';
    }
    return 0;
}
