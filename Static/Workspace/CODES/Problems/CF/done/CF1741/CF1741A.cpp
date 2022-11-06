#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    int t;
    scanf("%d",&t);
    while(t--){
        cin>>a>>b;
        if(a==b){
            cout<<"=\12";
            goto ed;
        }
        int va,vb;
        va=vb=0;
        if(a=="M")va=0;
        else va=a.size();
        if(b=="M")vb=0;
        else vb=b.size();
        if(a[a.size()-1]=='S')va=-va;
        if(b[b.size()-1]=='S')vb=-vb;
        cout<<(va>vb?">\12":"<\12");
ed:;
    }
    return 0;
}
