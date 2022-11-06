#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[3];
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        sort(a,a+3);
        if(a[0]+a[1]==a[2])cout<<"YES\12";
        else cout<<"NO\12";
    }
    return 0;
}
