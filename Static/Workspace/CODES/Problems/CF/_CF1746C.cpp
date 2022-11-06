#include<bits/stdc++.h>
using namespace std;
multiset<pair<int,int>>s;
int main(){
    int t,n;
    int u,l;
    scanf("%d",&t);
    multiset<pair<int,int>>::iterator it;
    while(t--){
        s.clear();
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",&u);
            if(i)s.insert({l-u,i+1});
            l=u;
        }
        s.insert({0,1});
        for(int i=1;i<=n;++i){
            it=--s.upper_bound({i,n+1});
            cout<<it->second<<' ';
            s.insert({it->first-i,it->second});
            s.erase(it);
        }
        cout<<'\12';
    }
    return 0;
}
