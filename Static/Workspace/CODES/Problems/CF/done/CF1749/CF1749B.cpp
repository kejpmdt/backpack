#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,a,b;
    scanf("%d",&t);
    long long ans=0;
    while(t--){
        scanf("%d",&n);
        ans=0;b=0;
        for(int i=1;i<=n;++i){
            scanf("%d",&a);
            ans+=a;
        }
        for(int i=1;i<=n;++i){
            scanf("%d",&a);
            ans+=a;
            b=max(b,a);
        }
        cout<<ans-b<<'\12';
    }
    return 0;
}
