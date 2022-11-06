#pragma gcc optimize(2);
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    int i;
    while(t--){
        long long a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        long long di;
        for(di=a*b;di<=c*d;di+=a*b){
            for(i=a+1;i<=c&&i<=di/i;++i){
                if(di%i!=0)continue;
                if(di/i>b&&di/i<=d){
                    cout<<i<<' '<<di/i<<'\12';
                    goto ed;
                }
            }
            for(i=b+1;i<=d&&i<=di/i;++i){
                if(di%i!=0)continue;
                if(di/i>a&&di/i<=c){
                    cout<<di/i<<' '<<i<<'\12';
                    goto ed;
                }
            }
        }
        cout<<"-1 -1\12";
ed:;
    }
    return 0;
}
