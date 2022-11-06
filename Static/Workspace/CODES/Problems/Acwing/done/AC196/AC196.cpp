#include<bits/stdc++.h>
using namespace std;
bool pd[50006];
bool u[1000006];
#define int long long
void init(int x){
    pd[1]=true;
    for(int i=2;i<=x;++i){
        for(int j=2;j<=x/i;++j){
            if(pd[j])continue;
            pd[i*j]=true;
            if(i%j==0)break;
        }
    }
    return;
}
pair<pair<long long,long long>,pair<long long,long long>>solve(int l,int r){
    memset(u,0x00,sizeof u);
    for(int i=2;i<=50000;++i){
        if(pd[i])continue;
        for(long long j=max(2*i,((l+i-1)/i)*i);j<=r;j+=i){
            u[j-l]=true;
        }
    }
    long long mia=0,mib=0x7fffffff,mxa=0,mxb=0,lst=0;
    for(long long i=l;i<=r;++i){
        if(i<=50000&&pd[i])continue;
        if(u[i-l])continue;
        if(lst){
            if(i-lst<mib-mia){
                mib=i;
                mia=lst;
            }
            if(i-lst>mxb-mxa){
                mxb=i;
                mxa=lst;
            }
        }
        lst=i;
    }
    return {{mia,mib},{mxa,mxb}};
}
signed main(){
    init(50000);
    long long l,r;
    while(cin>>l>>r){
        auto x=solve(l,r);
        if(x.first.first==0)cout<<"There are no adjacent primes."<<endl;
        else cout<<x.first.first<<","<<x.first.second<<" are closest, "<<x.second.first<<","<<x.second.second<<" are most distant."<<endl;
    }
    return 0;
}