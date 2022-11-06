#include <bits/stdc++.h>
using namespace std;
int exgcd(int a,int b,int&x,int&y){if(!b){x=1,y=0;return a;}int d=exgcd(b,a%b,y,x);y-=a/b*x;return d;}
int main() {
    int a,b,x,y;
    int m;
    cin>>m;
    while(m--){
        cin>>a>>b;  
        exgcd(a,b,x,y);
        cout<<x<<' '<<y<<'\12';
    }
    return 0;
}