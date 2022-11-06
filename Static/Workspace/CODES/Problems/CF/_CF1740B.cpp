#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int a,b,c=0;
        int ans=0;
        for(int i=1;i<=n;++i){
            scanf("%d%d",&a,&b);
            if(a<b)swap(a,b);
            c=max(c,a);
            ans+=b;
        }
        cout<<ans+c+c<<'\12';
    }
    return 0;
}
