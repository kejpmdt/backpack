#include<bits/stdc++.h>
using namespace std;
bool pd[1000006];
struct node{
    node*sons[256];
    node*ne;
    node*fa;
    int cnt;
    vector<int>nums;
    node(void){fa=ne=nullptr;memset(sons,0x00,sizeof sons);}
    void ins(string,int,int);
    void show(int x,unsigned char c){
        for(int i=1;i<=x;++i)cout<<"|---";
        printf("%c|%d(",c,cnt);
        bool pd=false;
        for(auto i:nums){   
            if(pd)cout<<",";
            cout<<i;
            pd=true;
        }
        cout<<")->"<<ne->cnt<<":\n";
        unsigned char i=0;
        do{
            if(sons[i])sons[i]->show(x+1,i);
            ++i;
        }while(i);
    }
}*root;
vector<node*>v;
node*newnode(void){
    static int x=-1;
    v.push_back(new node);
    ++x;
    v[x]->cnt=x;
    return v[x];
}
void node::ins(string s,int x,int n){
    if(!ne){
        ne=fa->ne;
        while(ne->fa&&ne->sons[(int)s[x-1]]==nullptr)ne=ne->ne;
        if(ne->sons[(int)s[x-1]])ne=ne->sons[(int)s[x-1]];
    }
    if(x==(int)s.size())nums.push_back(n);
    else{
        if(sons[(int)s[x]]==nullptr)sons[(int)s[x]]=newnode(),sons[(int)s[x]]->fa=this;
        sons[(int)s[x]]->ins(s,x+1,n);
    }
}

int main(){
    int n;
    cin>>n;
    string s;
    root=newnode();
    root->ne=root;
    for(int i=1;i<=n;++i){
        cin>>s;
        root->ins(s,0,i);
        root->show(0,0);
    }
    cin>>s;
    for(int i=0;i<n;++i){
        while(root->fa&&root->sons[(int)s[i]]==nullptr)root=root->ne;
        if(root->sons[(int)s[i]]!=nullptr)root=root->sons[(int)s[i]];
        for(auto j:root->nums)pd[j]=true;
    }
    int ans=0;
    for(int i=1;i<=n;++i)if(pd[i])++ans;
    cout<<ans;
}