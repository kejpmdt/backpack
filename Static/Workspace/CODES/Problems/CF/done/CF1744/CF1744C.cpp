#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    string s;
    char nw;
    int n;
    cin>>t;
    int ans,u;
    while(t--){
        ans=0;
        cin>>n>>nw;
        cin>>s;
        s+=s;
        n+=n;
        u=0;
        for(int i=n-1;i>=0;--i){
            if(s[i]=='g'){
                u=0;
            }
            else{
                ++u;
            }
            if(s[i]==nw){
                ans=max(ans,u);
            }
        }
        cout<<ans<<'\12';
    }
    return 0;
}
