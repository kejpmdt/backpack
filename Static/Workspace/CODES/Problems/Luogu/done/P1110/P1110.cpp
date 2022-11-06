#include<bits/stdc++.h>
using namespace std;
int fst[500005],lst[500005];
int main(){
    multiset<int>s;
    multiset<int>cf;
    string inp; 
    int a,b;
    int n,m;
    int ans1=0x7fffffff;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&a);
        fst[i]=lst[i]=a;
        auto u=s.insert(a);
        if(u!=s.begin()){
            ans1=min(ans1,*(u--)-*(u++));
        }
        if(u!=--s.end()){
            ans1=min(ans1,*(++u)-*(--u));
        }
        if(i>1){
            cf.insert(abs(fst[i]-fst[i-1]));
        }
    }
    for(int u=1;u<=m;++u){
        cin>>inp;
        if(inp=="INSERT"){
            scanf("%d%d",&a,&b);
            if(a!=n){
                cf.erase(cf.find(abs(fst[a+1]-lst[a])));
                cf.insert(abs(fst[a+1]-b));
                cf.insert(abs(lst[a]-b));
            }
            else{
                cf.insert(abs(lst[a]-b));
            }
            lst[a]=b;
            auto u=s.insert(b);
            if(u!=s.begin()){
                ans1=min(ans1,*(u--)-*(u++));
            }
            if(u!=--s.end()){
                ans1=min(ans1,*(++u)-*(--u));
            }
        }
        if(inp=="MIN_GAP"){
            printf("%d\n",*cf.begin());
        }
        if(inp=="MIN_SORT_GAP"){
            printf("%d\n",ans1);
        }
    }
    return 0;
}


