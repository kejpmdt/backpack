#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=i;++j){
                if(j==i||j==1)cout<<"1 ";
                else cout<<"0 ";
            }
            cout<<'\12';
        }
    }
    return 0;
}
