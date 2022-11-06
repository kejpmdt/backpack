#include<bits/stdc++.h>
using namespace std;
bool f[25005];
int a[105];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        memset(f,0x00,sizeof f);
        f[0]=true;
        for(int i=1;i<=n;++i){
            if(!f[a[i]])++ans;
            else continue;
            for(int j=0;j+a[i]<=25000;++j){
                f[j+a[i]]|=f[j];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}