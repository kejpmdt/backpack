#include<bits/stdc++.h>
using namespace std;
short cnt[10][10];
int main(){
    int t,n,m,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(cnt,0x00,sizeof cnt);
        while(m--){
            scanf("%d%d",&a,&b);
            for(int i=1;i<=n;++i){
                ++cnt[i][b];
                ++cnt[a][i];
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(cnt[i][j]==1){
                    cout<<"Yes\12";
                    goto ed;
                }
            }
        }
        cout<<"No\12";
ed:;
    }
    return 0;
}
