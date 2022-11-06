#include<bits/stdc++.h>
using namespace std;
template<typename T>
vector<T> radixsort(vector<T> nums){
#define radix 8
    vector<T> cnt(1<<radix,0);
    vector<T> u1(nums.size(),0);
    vector<T> u2=nums;
    T basic=1<<radix,lbasic=0;
    u2=nums;
    int sz=nums.size();
    while(1){
        cnt=vector<T>(1<<radix,0);
        for(auto i:u2)++cnt[(i>>lbasic)&(basic-1)];
        for(auto i:cnt)if(i==sz)return u2;
        for(int i=1;i<(int)cnt.size();++i)cnt[i]+=cnt[i-1];
        for(int i=(int)u2.size()-1;i>=0;--i)
            u1[--cnt[(u2[i]>>lbasic)&(basic-1)]]=u2[i];
        u2=u1;
        lbasic+=radix;
    }
#undef radix
}
int main(){
    int n;
    scanf("%d",&n);
    vector<int>v(n);
    for(int i=0;i<n;++i)scanf("%d",&v[i]);
    v=radixsort(v);
    for(auto i:v)printf("%d ",i);
    return 0;
}