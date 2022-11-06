#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x)&-(x))
#define MAXN 100005
long long ori[MAXN];
long long timed[MAXN];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    for(i=1;i<=n;++i)scanf("%lld",&ori[i]);
    for(i=n;i>=1;--i)ori[i]-=ori[i-1];
    for(i=1;i<=n;++i)if(i+lowbit(i)<=n)ori[i+lowbit(i)]+=ori[i];
    for(i=1;i<=n;++i)timed[i]=ori[i]*i;
    char C;
    int l,r,d;
    long long ans,u;
    while(m--){
        do{
            C=getchar();
        }while(C!='C'&&C!='Q');
        if(C=='C'){
            scanf("%d%d%d",&l,&r,&d);
            for(i=l;i<=n;i+=lowbit(i)){
                ori[i]+=d;
                timed[i]=(i-1)*ori[i];
            }
            for(i=r+1;i<=n;i+=lowbit(i)){
                ori[i]-=d;
                timed[i]=i*ori[i];
            }
        }
        else{
            scanf("%d%d",&l,&r);
            u=0;
            ans=0;
            for(i=r;i;i-=lowbit(i))u+=ori[i];
            ans+=u*(r+1);
            for(i=r;i;i-=lowbit(i))ans-=timed[i];
            u=0;
            for(i=l-1;i;i-=lowbit(i))u+=ori[i];
            ans-=u*l;
            for(i=l-1;i;i-=lowbit(i))ans+=timed[i];
            cout<<ans<<'\12';
        }
    }
    return 0;
}