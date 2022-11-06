#include<bits/stdc++.h>
using namespace std;
map<int,int>cf(int x){
    map<int,int>res;
    res.clear();
    for(int i=2;i*i<=x;++i)while(x%i==0)++res.insert({i,0}).first->second,x/=i;
    if(x>1)++res.insert({x,0}).first->second;
    return res;
}
int main(){
    int n;
    cin>>n;
    int a0,a1,b0,b1;
    while(n--){
        cin>>a0>>a1>>b0>>b1;
        auto ca0=cf(a0),ca1=cf(a1);
        auto cb0=cf(b0),cb1=cf(b1);
        if(b1%a1!=0){
            cout<<0<<endl;
            continue;
        }
        int ans=1;
        for(auto i:cb1){
            if(cb0[i.first]!=cb1[i.first]||ca0[i.first]!=ca1[i.first]){
                if(cb0[i.first]!=cb1[i.first]&&ca0[i.first]!=ca1[i.first]&&cb1[i.first]!=ca1[i.first]){
                    ans=0;
                    break;
                }
                continue;
            }
            ans*=(cb1[i.first]-ca1[i.first]+1);
        }
        cout<<ans<<endl;
    }
}
