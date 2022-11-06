#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    int mx,k;
    scanf("%d",&t);
    int u;
    while(t--){
        scanf("%d",&n);
        mx=0;
        for(int i=1;i<=n;++i){
            scanf("%d",&u);
            if(u>mx)k=i,mx=u;
        }
        cout<<k<<'\12';
    }
    return 0;
}
