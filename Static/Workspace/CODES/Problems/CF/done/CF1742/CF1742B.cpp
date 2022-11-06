#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        if(unique(a+1,a+n+1)!=a+n+1){
            cout<<"NO\12";
        }
        else {
            cout<<"YES\12";
        }
    }
    return 0;
}
