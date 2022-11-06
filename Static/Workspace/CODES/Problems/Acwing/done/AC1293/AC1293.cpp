#include<bits/stdc++.h>
using namespace std;
bool pd[100015];
void init(){
    pd[1]=true;
    for(int i=2;i<=100005;++i){
        for(int j=2;j<=100005/i;++j){
            if(pd[j])continue;
            pd[i*j]=true;
            if(i%j==0)break;
        }
    }
}
int main(){
    int n;
    init();
    cin>>n;
    cout<<(n>2)+1<<endl;
    for(int i=2;i<=n+1;++i)cout<<pd[i]+1<<' ';
}