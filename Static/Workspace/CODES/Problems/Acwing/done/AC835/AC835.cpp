#include<bits/stdc++.h>
using namespace std;
struct node{
    node*sons[26];
    signed int num;
    node():num(0){memset(sons,0x00,sizeof sons);}
    void ins(string&s,int x){
        if(x==(int)s.size())++num;
        else{
            if(sons[s[x]-'a']==nullptr)
                sons[s[x]-'a']=new node;
            sons[s[x]-'a']->ins(s,x+1);
        }
    }
    int ask(string&s,int x){
        if(x==(int)s.size())return num;
        if(sons[s[x]-'a']==nullptr)return 0;
        return sons[s[x]-'a']->ask(s,x+1);
    }
}*root;
int main(){
    root=new node;
    string s;
    string opt;
    int n;
    cin>>n;
    while(n--){
        cin>>opt>>s;
        if(opt=="I")root->ins(s,0);
        else cout<<root->ask(s,0)<<endl;
    }
    return 0;
}