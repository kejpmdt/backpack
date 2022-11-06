#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        cout<<((a-1)<c+abs(b-c)-1?1:(a-1)==c+abs(b-c)-1?3:2)<<'\12';
    }
    return 0;
}
