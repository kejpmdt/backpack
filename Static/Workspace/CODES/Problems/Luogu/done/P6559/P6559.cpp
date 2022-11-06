#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,bool>mp;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int ans=0;
    while(k--){
        int a,b;
        scanf("%d%d",&a,&b);
        if(mp[{a-1,b}])++ans;
        if(mp[{a,b-1}])++ans;
        if(mp[{a+1,b}])++ans;
        if(mp[{a,b+1}])++ans;
        mp[{a,b}]=true;
    }
    printf("%d",ans);
}