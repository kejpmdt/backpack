#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n&1){
            cout<<1<<' ';
            for(int i=2;i<=n-2;++i){
                if(i%2==0)cout<<i+1<<' ';
                else cout<<i-1<<' ';
            }
        }
        else{
            for(int i=1;i<=n-2;++i){
                if(i%2==0)cout<<i-1<<' ';
                else cout<<i+1<<' ';
            }
        }
        cout<<n-1<<' '<<n<<'\12';
    }
    return 0;
}
