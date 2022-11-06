#include<bits/stdc++.h>
using namespace std;
bool pd[1000006];
void init(){
    pd[1]=true;
    for(int i=2;i<=1000000;++i){
        for(int j=2;j<=1000000/i;++j){
            if(pd[j])continue;
            pd[i*j]=true;
            if(i%j==0)break;
        }
    }
}
void solve(int x){
    for(int i=3;i<=x;++i){
        if(!pd[i]&&!pd[x-i]){
            printf("%d = %d + %d\n",x,i,x-i);
            return;
        }
    }
}
int main(){
    init();
    int n;
    cin>>n;
    while(n){
        solve(n);
        cin>>n;
    }
}
        
