#include<bits/stdc++.h>
using namespace std;
template<class A,class B>struct mpair{mutable A first;mutable B second;bool operator<(const mpair&oth)const{return first<oth.first;}};
set<mpair<mpair<int,int>,char>>odt;
auto split(int x){
    auto u=--odt.upper_bound({{x,x},0x00});
    if(x==u->first.first)return u;
    int r=u->first.second;
    u->first.second=x-1;
    return odt.insert({{x,r},u->second}).first;
}
int ask(int l,int r,char x){
    auto R=split(r+1),L=split(l);
    int ans=0;
    for(auto i=L;i!=R;++i){
        if(i->second==x)ans+=(i->first.second-i->first.first+1);
    }
    return ans;
}
void assign(int l,int r,char x){
    auto R=split(r+1),L=split(l);
    odt.erase(L,R);
    odt.insert({{l,r},x});
}
void odtsort(int l,int r){
    int nums[26];
    memset(nums,0x00,sizeof nums);
    auto R=split(r+1),L=split(l);
    for(auto i=L;i!=R;++i)nums[(int)(i->second-'a')]+=(i->first.second-i->first.first+1);
    odt.erase(L,R);
    int nw=l;
    for(int i=0;i<26;++i)if(nums[i])odt.insert({{nw,nw+nums[i]-1},(char)(i+'a')}),nw+=nums[i];
}
char gc(void){
    static char us;
    do us=getchar();while(us<'A'||us>'z');
    return us>'Z'?us:us+'\40';
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)odt.insert({{i,i},gc()});
    int opt,l,r;
    while(m--){
        scanf("%d%d%d",&opt,&l,&r);
        if(opt==1){
            cout<<ask(l,r,gc())<<'\12';
        }
        if(opt==2){
            assign(l,r,gc());
        }
        if(opt==3){
            odtsort(l,r);
        }
    }
    return 0;
}
            

