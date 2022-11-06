#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k;
    scanf("%d",&t);
    int u;
    bool pd,pd2;
    while(t--){
        pd=false,pd2=true;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;++i){
            scanf("%d",&u);
            pd|=u;
            pd2&=u;
        }
        if((pd&&n>=k)||pd2){
            cout<<"YES\12";
        }
        else{
            cout<<"NO\12";
        }
    }
    return 0;
}
