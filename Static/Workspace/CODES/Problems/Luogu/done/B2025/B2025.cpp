#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            if(i+j<2||4-i+j<2||8-i-j<2||4-j+i<2)cout<<' ';
            else cout<<'*';
        }
        cout<<'\12';
    }
}