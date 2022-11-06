#include<bits/stdc++.h>
using namespace std;
set<int>s;
int main(){
    int n;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        s.clear();
        long long ans=a;
        for(int i=2;i<=a/i;++i){
            while(a%i==0){
                if(s.insert(i).second)ans=ans*(i-1)/i;
                a/=i;
            }
        }
        if(a>1)if(s.insert(a).second)ans=ans*(a-1)/a;
        cout<<ans<<endl;
    }
}