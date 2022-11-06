#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,x,y,nw,en;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&x,&y);
        if(x>y)swap(x,y);
        if(x!=0){
            cout<<-1;
            goto ed;
        }
        if(y==0||(n-1)%y!=0){
            cout<<-1;
            goto ed;
        }
        nw=1,en=0;
        for(int i=2;i<=n;++i){
            if(en==y)nw=i,en=0;
            cout<<nw<<' ';
            ++en;
        }
ed:;
        cout<<'\12';
    }
    return 0;
}
