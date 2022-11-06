#include<bits/stdc++.h>
using namespace std;
int nums[100];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>nums[i];
    sort(nums+1,nums+n+1);
    long long ans=1;
    for(int i=1;i<=n;++i){
        if(nums[i]<i)ans=0;
        ans=ans*(nums[i]-i+1)%(1000000007);
    }
    cout<<ans;
    return 0;
}