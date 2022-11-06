#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    int u;
    int ans;
    int a;
    int i,r,j;
    scanf("%d",&t);
    while(t--){
        u=0;
        scanf("%d",&n);
        for(i=1;i<=n;++i){
            scanf("%d",&a);
            while((a&1)==0){
                a>>=1;
                ++u;
            }
        }
        ans=0;
        if(u>=n){
            cout<<ans;
            goto ed;
        }
        i=0;
        while((1<<i)<=n)++i;
        --i;
        r=0;
        while(i){
            if(u>=n){
                cout<<ans;
                goto ed;
            }
            for(j=1;j<=(n>>i)-r;++j){
                u+=i;
                ++ans;
                if(u>=n){
                    cout<<ans;
                    goto ed;
                }
            }
            r=(n>>i);
            --i;
        }
        cout<<-1;
ed:
        cout<<'\12';
    }
    return 0;
}
