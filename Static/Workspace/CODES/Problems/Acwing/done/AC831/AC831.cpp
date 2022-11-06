#include<bits/stdc++.h>
using namespace std;
string s,p;
int ne[100005];
int main(){
    int n,m;
    cin>>n>>p>>m>>s;
    p=' '+p;
    s=' '+s;
    for(int i=2,j=0;i<=n;++i){
        while(j&&p[i]!=p[j+1])j=ne[j];
        if(p[i]==p[j+1])ne[i]=++j;
    }
    for(int i=1,j=0;i<=m;++i){
        while(j&&s[i]!=p[j+1])j=ne[j];
        if(s[i]==p[j+1])++j;
        if(j==n){
            cout<<i-n<<' ';
            j=ne[j];
        }
    }
    return 0;
}