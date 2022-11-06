#include<bits/stdc++.h>
using namespace std;
int u[200005];
int main(){
    int t,n,i,j;
    scanf("%d",&t);
    int ans;
    while(t--){
        ans=0;
        scanf("%d",&n);
        for(i=1;i<=n;++i)scanf("%d",&u[i]);
        i=0,j=n+1;
        while(i<j){
            do{++i;}while(i<j&&!u[i]);
            do{--j;}while(i<j&&u[j]);
            ++ans;
        }
        cout<<ans-1<<'\12';
    }
    return 0;
}

