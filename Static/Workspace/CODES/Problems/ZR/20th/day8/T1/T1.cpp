#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int chg=0;
    int ans=0;
    for(auto i:s){
        if(i==')'&&chg==0)++ans;
        else if(i==')')--chg;
        else ++chg;w
    }
    cout<<ans+chg;
}