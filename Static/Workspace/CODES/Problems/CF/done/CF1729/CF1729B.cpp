#include<bits/stdc++.h>
using namespace std;
string s;
char tran(int l,int r){
    char ans=0;
    for(;l<=r;++l){
        ans=ans*10+s[l]-'0';
    }
    return ans+'`';
}
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        cin>>s;
        string res="";
        --n;
        while(n>=0){
            if(s[n]!='0'){
                res=(char)(s[n]-'0'+'`')+res;
                --n;
            }
            else{
                res=tran(n-2,n-1)+res;
                ------n;
            }
        }
        cout<<res<<'\12';
    }
    return 0;
}

