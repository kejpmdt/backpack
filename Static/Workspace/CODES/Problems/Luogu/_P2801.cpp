#include<bits/stdc++.h>
using namespace std;
#define belong(x) ((x-1)/sqrtn+1)
#define begin(x) ((x-1)*sqrtn+1)
#define end(x) ((x)*sqrtn)
int ori[1002000],sot[1002000],add[2000];
int main(){
    int n,m,l,r,w,ans;
    scanf("%d%d",&n,&m);
    register int sqrtn=sqrt(n),i;
    for(i=1;i<=n;++i)scanf("%d",ori+i),sot[i]=ori[i];
    for(i=1;begin(i)<=n;++i)sort(sot+begin(i),sot+end(i)+1);
    unsigned char opt;
    while(m--){
        do{opt=getchar();}while(opt!=77&&opt!=65);
        scanf("%d%d%d",&l,&r,&w);
        if(opt==77){
            if(belong(l)==belong(r)){
                for(i=begin(belong(l));i<=end(belong(l));++i)ori[i]+=add[belong(l)];
                add[belong(l)]=0;
                for(i=l;i<=r;++i)ori[i]+=w;
                for(i=begin(belong(l));i<=end(belong(l));++i)sot[i]=ori[i];
                sort(sot+begin(belong(l)),sot+end(belong(l))+1);
            }
            else{
                for(i=begin(belong(l));i<=end(belong(l));++i)ori[i]+=add[belong(l)];
                for(i=begin(belong(r));i<=end(belong(r));++i)ori[i]+=add[belong(r)];
                add[belong(l)]=add[belong(r)]=0;
                for(i=l;i<=end(belong(l));++i)ori[i]+=w;
                for(i=begin(belong(r));i<=r;++i)ori[i]+=w;
                for(i=belong(l)+1;i<belong(r);++i)add[i]+=w;
                for(i=begin(belong(l));i<=end(belong(l));++i)sot[i]=ori[i];
                for(i=begin(belong(r));i<=end(belong(r));++i)sot[i]=ori[i];
                sort(sot+begin(belong(l)),sot+end(belong(l))+1);
                sort(sot+begin(belong(r)),sot+end(belong(r))+1);
            }
        }
        else{
            ans=0;
            if(belong(l)==belong(r)){
                for(i=begin(belong(l));i<=end(belong(l));++i)ori[i]+=add[belong(l)],sot[i]+=add[belong(l)];
                add[belong(l)]=0;
                for(i=l;i<=r;++i)if(ori[i]>=w)++ans;
            }
            else{
                for(i=l;i<=end(belong(l));++i)if(ori[i]>=w-add[belong(i)])++ans;
                for(i=begin(belong(r));i<=r;++i)if(ori[i]>=w-add[belong(i)])++ans;
                for(i=belong(l)+1;i<belong(r);++i)ans+=sot+end(i)+1-lower_bound(sot+begin(i),sot+end(i)+1,w-add[i]);
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}


