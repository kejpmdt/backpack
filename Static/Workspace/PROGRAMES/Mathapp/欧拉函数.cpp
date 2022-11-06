#include<bits/stdc++.h>
using namespace std;
template<typename T>T phi(T x){set<int>s;T ans=x;for(int i=2;i<=x/i;++i)while(x%i==0){if(s.insert(i).second)ans=ans*(i-1)/i;x/=i;}if(x>1)if(s.insert(x).second)ans=ans*(x-1)/x;return ans;}
int main(){
    long long a;
    cin>>a;
    long long ans=phi(a);
    cout<<ans<<endl;
}