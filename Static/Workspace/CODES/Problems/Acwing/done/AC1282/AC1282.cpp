#include<bits/stdc++.h>
using namespace std;
struct node{
    int sons[26];
    int cnt;
    int fail;
}nodes[500005];
int cnt=0;
void ins(string&s){
    int nw=0;
    for(int i=0;i<s.size();++i){
        if(nodes[nw].sons[(int)(s[i]-'a')]==0)nodes[nw].sons[(int)(s[i]-'a')]=++cnt;
        nw=nodes[nw].sons[(int)(s[i]-'a')];
    }
    ++nodes[nw].cnt;
}
void findne(void){
    deque<int>q;
    for(int i=0;i<26;++i)if(nodes[0].sons[i])q.push_back(nodes[0].sons[i]);
    while(!q.empty()){
        for(int i=0,k=0;i<26;++i){
            if(nodes[q.front()].sons[i]==0){
                nodes[q.front()].sons[i]=nodes[nodes[q.front()].fail].sons[i];
            }
            else{
                nodes[nodes[q.front()].sons[i]].fail=nodes[nodes[q.front()].fail].sons[i];
                q.push_back(nodes[q.front()].sons[i]);
            }
        }
        q.pop_front();
    }
}
int main(){
    int t;
    int n;
    cin>>t;
    string s;
    while(t--){
        memset(nodes,0x00,sizeof nodes);
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>s;
            ins(s);
        }
        findne();
        cin>>s;
        int ans=0;
        for(int i=0,j=0;i<s.size();++i){
            j=nodes[j].sons[(int)(s[i]-'a')];
            for(int k=j;k;k=nodes[k].fail){
                ans+=nodes[k].cnt;
                nodes[k].cnt=0;
            }
        }
        cout<<ans<<endl;
    }
}
