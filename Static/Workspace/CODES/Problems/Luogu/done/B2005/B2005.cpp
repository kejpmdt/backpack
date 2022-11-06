#include<bits/stdc++.h>
using namespace std;
int main(){
    char c=getchar();
    for(int i=0;i<3;++i){
        for(int j=0;j<5;++j){
            if(i+j<2||4-i+j<2||8-i-j<2||4-j+i<2)cout<<' ';
            else cout<<c;
        }
        cout<<'\12';
    }
}