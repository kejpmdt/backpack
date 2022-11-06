#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n==3){
            cout<<"-1\12";
            goto ed;
        }
        for(int i=3;i<=n;++i)cout<<i<<' ';
        cout<<"2 1\12";
ed:;
    }
    return 0;
}
