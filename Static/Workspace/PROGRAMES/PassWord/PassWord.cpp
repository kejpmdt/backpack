#include<bits/stdc++.h>
using namespace std;
vector<unsigned char>chars;
set<unsigned char>resorces[5];
int randd(int l,int r){return (rand()*rand()%(r-l)+(r-l))%(r-l)+l;}
int main(){
    for(unsigned char i='0';i<='9';++i)resorces[0].insert(i);
    for(unsigned char i='a';i<='z';++i)resorces[1].insert(i);
    for(unsigned char i='A';i<='Z';++i)resorces[2].insert(i);
    resorces[3].insert('!'),resorces[3].insert('@');
    resorces[3].insert('#'),resorces[3].insert('$');
    resorces[3].insert('%'),resorces[3].insert('^');
    resorces[3].insert('&'),resorces[3].insert('*');
    resorces[3].insert('('),resorces[3].insert(')');
    resorces[3].insert('['),resorces[3].insert(']');
    resorces[3].insert('{'),resorces[3].insert('}');
    resorces[3].insert('\''), resorces[3].insert('\"');
    resorces[3].insert('\\'),resorces[3].insert('|');
    resorces[3].insert(';'),resorces[3].insert(':');
    resorces[3].insert('/'),resorces[3].insert('?');
    resorces[3].insert('.'),resorces[3].insert('>');
    resorces[3].insert(','),resorces[3].insert('<');
    resorces[3].insert('='),resorces[3].insert('+');
    resorces[3].insert('-'),resorces[4].insert('_');
    string u;
    cout<<"0aA*_\12";
    cin>>u;
    if(u[0]=='1'){for(auto i:resorces[0])chars.push_back(i);}
    if(u[1]=='1'){for(auto i:resorces[1])chars.push_back(i);}
    if(u[2]=='1'){for(auto i:resorces[2])chars.push_back(i);}
    if(u[3]=='1'){for(auto i:resorces[3])chars.push_back(i);}
    if(u[4]=='1'){for(auto i:resorces[4])chars.push_back(i);}
    srand(time(0));
    int n;
    cin>>n;
    freopen("password.txt","w",stdout);
    while(n--)putchar(chars[randd(0,chars.size())]);
}