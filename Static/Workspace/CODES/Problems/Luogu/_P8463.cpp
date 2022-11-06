#include<bits/stdc++.h>
using namespace std;
template<typename a,typename b>struct mpair{a first;mutable b second;bool operator<(const mpair&oth)const{return first<oth.first;}};
set<mpair<int,int>>tree;
pair<int,mpair<int,int>>lines[500005];
int main(){
    int n,m,i,x,u,ans=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)scanf("%d%d%d",&lines[i].second.first,&lines[i].second.second,&lines[i].first);
    for(i=1;i<=n;++i){
        scanf("%d",&x);
        ++tree.insert({x,0}).first->second;
    }
    ans=n%998244353;
    sort(lines+1,lines+m+1);
    set<mpair<int,int>>::iterator l,r,j;
    for(i=m;i>=1;--i){
        u=0;
        l=tree.lower_bound({lines[i].second.first,0});
        r=tree.upper_bound({lines[i].second.second,0});
        for(j=l;j!=r;++j)u+=j->second,u%=998244353,ans+=j->second,ans%=998244353;
        tree.erase(l,r);
        tree.insert({lines[i].second.first,0}).first->second+=u;
        tree.insert({lines[i].second.second,0}).first->second+=u;
        tree.insert({lines[i].second.first,0}).first->second%=998244353;
        tree.insert({lines[i].second.second,0}).first->second%=998244353;
    }
    cout<<ans%998244353;
    return 0;
}
