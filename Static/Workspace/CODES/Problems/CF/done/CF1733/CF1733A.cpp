#include<bits/stdc++.h>
using namespace std;
int a[205];
int main(){
    int t,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        int u;
        for(int i=1;i<=n;++i){
            scanf("%d",&u);
            if(i<=k||u>a[i%k])a[i%k]=u;
        }
        long long sum=0;
        for(int i=0;i<k;++i){
            sum+=a[i];
        }
        cout<<sum<<'\12';
    }
    return 0;
}
