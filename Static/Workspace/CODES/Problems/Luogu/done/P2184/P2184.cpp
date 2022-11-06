#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
using namespace std;
#define MAXN 100005
int had[MAXN],nw[MAXN];
int n,m;
int get(int*u,int x){int ans=0;while(x)ans+=u[x],x-=lowbit(x);return ans;}
void add(int*u,int x,int k){while(x<=n)u[x]+=k,x+=lowbit(x);}
int main(){
    scanf("%d%d",&n,&m);
    int q,l,r;
    while(m--){
        scanf("%d%d%d",&q,&l,&r);
        if(q==1)add(had,l,1),add(nw,l,1),add(nw,r+1,-1);
        else cout<<get(nw,l)+get(had,r)-get(had,l)<<endl;
    }
}