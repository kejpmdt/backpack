#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
using namespace std;
int num[500005];
int main(){
    int n,m,a,b,opt;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&num[i]);
    for(int i=1;i<=n;++i)if(i+lowbit(i)<=n)num[i+lowbit(i)]+=num[i];
    while(m--){
        scanf("%d%d%d",&opt,&a,&b);
        if(opt==1)while(a<=n)num[a]+=b,a+=lowbit(a);
        else{
            opt=0;
            while(b)opt+=num[b],b-=lowbit(b);
            --a;
            while(a)opt-=num[a],a-=lowbit(a);
            cout<<opt<<endl;
        }
    }
    return 0;
}