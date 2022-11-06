#include<bits/stdc++.h>
using namespace std;
int nw[1000];
int k;
int nums[26];
int cnts[26];
int cnt;
void check(void){
    memset(nums,0x00,sizeof nums);
    for(int i=0;i<cnt;++i){
        nums[nw[i]]++;
        for(int j=0;j<k;++j){
            if(nums[j]==nums[nw[i]]&&j!=nw[i])return;
        }
    }
    memset(nums,0x00,sizeof nums);
    for(int i=cnt-1;i>=0;--i){
        nums[nw[i]]++;
        for(int j=0;j<k;++j){
            if(nums[j]==nums[nw[i]]&&j!=nw[i])return;
        }
    }
    for(int j=0;j<k;++j){
        if(nums[j]==0)return;
    }
    for(int i=0;i<cnt;++i)putchar(nw[i]+'a');
    ++k;
}
void dfs(int limit,int x){
    check();
    if(x==limit)return;
    ++cnt;
    bool pd;
    for(int i=0;i<k;++i){
        pd=false;
        for(int j=0;j<k;++j){
            if(cnts[i]+1==cnts[j]&&i!=j){
                pd=true;
                break;
            }
        }
        if(pd)continue;
        ++cnts[i];
        nw[x]=i;
        dfs(limit,x+1);
        --cnts[i];
    }
    --cnt;
}
int main(){
    //freopen("anss.txt","w",stdout);
    k=1;
    for(int i=1;k<=26;++i)
        dfs(i,0);
}