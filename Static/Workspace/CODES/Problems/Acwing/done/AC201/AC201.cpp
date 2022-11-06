#include<bits/stdc++.h>
using namespace std;
int anss[1005];
int main(){
    int n,c;
    cin>>c;
    int ans=3;anss[1]=1;
    for(int i=1;i<=1000;++i){
        for(int j=1;j<i;++j){
            if(__gcd(i,j)!=1)continue;
            ++++ans;
        }
        anss[i]=ans;
    }
    for(int i=1;i<=c;++i){
        cin>>n;
        cout<<i<<' '<<n<<' '<<anss[n]<<endl;
    }
}