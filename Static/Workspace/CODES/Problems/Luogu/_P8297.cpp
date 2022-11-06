#include<iostream>
#include<algorithm>
using namespace std;
int u[200005];
int main(){
    int n;
    cin>>n;
    int ans=0;
    int l;
    for(int i=1;i<=n;++i){
        cin>>u[i];
    }
    sort(u+1,u+n+1);
    l=1;
    while(l<n){
        ++ans;
        --u[l];
        if(u[l]==0)n-=2,++l;
        else n--;
    }
    printf("%d",ans);
}