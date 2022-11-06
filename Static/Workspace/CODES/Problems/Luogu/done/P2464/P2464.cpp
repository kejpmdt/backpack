#include<cstdio>
#include <algorithm>
#include <cmath>
#define belong(x) ((x-1)/sqrtn+1)
#define begin(x) ((x-1)*sqrtn+1)
#define end(x) ((x)*sqrtn)
using namespace std;
int ori[101005];
int sot[101005];
int main(){
    int n,m;
    int sqrtn;
    scanf("%d%d",&n,&m);
    sqrtn=sqrt(n);
    int i,j;
    for(i=1;i<=n;++i)scanf("%d",&ori[i]),sot[i]=ori[i];
    for(j=1;begin(j)<=n;++j)sort(sot+begin(j),sot+end(j)+1);
    int l,r,k;
    int ans;
    char opt;
    while(m--){
        do{
            opt=getchar();
        }while(opt!='Q'&&opt!='C');
        if(opt=='C'){
            scanf("%d%d",&l,&k);
            ori[l]=k;
            for(i=begin(belong(l));i<=end(belong(l));++i)sot[i]=ori[i];
            sort(sot+begin(belong(l)),sot+end(belong(l))+1);
        }
        else{
            scanf("%d%d%d",&l,&r,&k);
            ans=0;
            if(belong(l)==belong(r)){
                for(i=l;i<=r;++i)if(ori[i]==k)++ans;
            }
            else{
                for(i=l;i<=end(belong(l));++i)if(ori[i]==k)++ans;
                for(j=belong(l)+1;j<belong(r);++j)ans+=upper_bound(sot+begin(j),sot+end(j)+1,k)-lower_bound(sot+begin(j),sot+end(j)+1,k);
                for(i=begin(belong(r));i<=r;++i)if(ori[i]==k)++ans;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

