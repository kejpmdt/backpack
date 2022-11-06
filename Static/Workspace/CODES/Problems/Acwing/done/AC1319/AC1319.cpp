#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int>tos[2005];
int ssg[2005];
int sg(int x){
    if(ssg[x]!=-1)return ssg[x];
    unordered_set<int>ss;
    for(auto i:tos[x])ss.insert(sg(i));
    for(int i=0;;++i)if(!ss.count(i))return ssg[x]=i;
}
int main(){
    cin>>n>>m>>k;
    int x,y;
    while(m--)cin>>x>>y,tos[x].push_back(y);
    while(n--)if(tos[n+1].empty())ssg[n+1]=0;
    y=0,memset(ssg,0xff,sizeof ssg);
    while(k--)cin>>x,y^=sg(x);
    cout<<(y?"win":"lose");
    return 0;
}

