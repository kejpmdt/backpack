#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n<=8)cout<<"0\12";
        else cout<<(int)floor((n-6)/3)<<'\12';
    }
    return 0;
}
