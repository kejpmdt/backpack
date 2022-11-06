#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        if(n==1||m==1){
            cout<<"1 1\12";
        }
        else{
            cout<<"2 2\12";
        }
    }
    return 0;
}
