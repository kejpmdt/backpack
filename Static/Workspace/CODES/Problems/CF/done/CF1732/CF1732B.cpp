#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    int n;
    string s;
    bool pd;
    int nw;
    int u;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        pd=false;
        nw=0;
        int ans=0;
        cin>>s;
        for(int i=0;i<s.size();++i){
            u=s[i]-'0';
            if(u==1)pd=true;
            if(u!=nw)continue;
            if(pd&&u==nw){
                ++ans;
                nw=1-nw;
            }
        }
        cout<<ans<<'\12';
    }
    return 0;
}
