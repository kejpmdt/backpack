#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    int n;
    int ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",&ans);
        if(n>8){
            cout<<"0\12";
            goto ed;
        }
        n=10-n;
        cout<<3*n*(n-1)<<'\12';
ed:;
    }
    return 0;
}
