#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[105];
int main(){
    int n,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        for(int i=1;i<=n;++i)scanf("%d",&b[i]);
        int ans1=0,ans2=0;
        for(int i=1;i<=n;++i){
            if(a[i]!=b[i])++ans2;
            ans1+=a[i];
            ans1-=b[i];
        }
        ans1=abs(ans1);
        ++ans1;
        cout<<min(ans1,ans2)<<'\12';
    }
    return 0;
}
