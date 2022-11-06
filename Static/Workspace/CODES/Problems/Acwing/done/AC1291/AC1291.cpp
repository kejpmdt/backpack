#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MAXX 1000006
int inp[MAXN],cnt[MAXX],cnts[MAXX],n;
void init(){cin>>n;for(int i=1;i<=n;++i)cin>>inp[i],++cnt[inp[i]];}
void solve(){for(int i=1;i<MAXX;++i)for(int j=i;j<MAXX;j+=i)cnts[j]+=cnt[i];}
int main(){init();solve();for(int i=1;i<=n;++i)cout<<cnts[inp[i]]-1<<endl;}