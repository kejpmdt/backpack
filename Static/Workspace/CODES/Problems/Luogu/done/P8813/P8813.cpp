#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,u;
    u=1;
    scanf("%lld%lld",&a,&b);
    if(a==1){
        cout<<1;
        return 0;
    }
    while(b--){
        u*=a;
        if(u>1000000000){
            cout<<-1;
            return 0;
        }
    }
    cout<<u;
    return 0;
}
