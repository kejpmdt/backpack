#include<bits/stdc++.h>
using namespace std;
char c[8][8];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<8;++i){
            for(int j=0;j<8;++j){
                cin>>c[i][j];
            }
        }
        for(int i=0;i<8;++i){
            for(int j=0;j<8;++j){
                if(c[i][j]=='B')goto ct;
            }
            cout<<"R\12";
            goto ed;
ct:;
        }
        cout<<"B\12";
ed:;
    }
    return 0;
}
