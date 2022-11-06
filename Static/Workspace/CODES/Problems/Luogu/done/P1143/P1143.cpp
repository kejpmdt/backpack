#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int trans(char x){
    if(x<'\72'){
        return x-'\60';
    }
    else return x-'\67';
}
char trans(int x){
    if(x<11){
        return x+'\60';
    }
    else return x+'\67';
}
int main(){
    int n,m;
    string s;
    cin>>n>>s>>m;
    int r=0;
    for(int i=0;i<(int)s.size();++i){
        r*=n;
        r+=trans(s[i]);
    }
    s="";
    do{
        s=trans(r%m)+s;
        r/=m;
    }while(r);
    cout<<s;
    return 0;
}