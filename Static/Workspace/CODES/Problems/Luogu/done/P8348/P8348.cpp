#include<bits/stdc++.h>
using namespace std;
int t,x,y,xx,yy,k;
void solve(int &a,int &b){
    static int u;
    while(1){
        if(a==b)break;
        if(a<b){
            u=(b-k)/a;
            if(!u)break;
            b-=u*a;
            if(u&1)swap(a,b);
        }
        else {
            u=(a-k)/b;
            if(!u)break;
            a-=u*b;
            if(u&1)swap(a,b);
        }
    }
}
int main(){
    cin>>t;
    while(t--){
        scanf("%d%d%d%d%d",&x,&y,&xx,&yy,&k);
        if(xx<k||yy<k||x<k|y<k||k<k){
            cout<<"no\12";
            continue;
        }
        solve(x,y);solve(xx,yy);
        if(xx!=x||yy!=y)cout<<"no\12";
        else cout<<"yes\12";
    }
}
