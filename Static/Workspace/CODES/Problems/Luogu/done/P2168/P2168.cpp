#include<bits/stdc++.h>
using namespace std;
#define MAXN 400005
#define int long long
int times[MAXN];
struct object{
    int num;
    int height;
    unordered_map<unsigned char,object*>sons;
    object(int x):num(x),height(0),sons(){}
};
priority_queue<pair<pair<int,int>,object*>,vector<pair<pair<int,int>,object*>>,greater<pair<pair<int,int>,object*>>>q;
int n,k;
int dfs(object*nw){
    static int deep=-1;
    ++deep;
    if(nw->num){
        
        return times[nw->num]*deep--;
    }
    else{
        int ans=0;
        for(int i=1;i<=k;++i){
            ans+=dfs(nw->sons[i]);
        }
        --deep;
        return ans;
    }
}
void show(object*nw){
    static int deep=-1;
    ++deep;
    for(int i=0;i<deep;++i)printf("|   ");
    printf("%d %d-\n",nw->num,times[nw->num]);
    if(!nw->num)for(int i=1;i<=k;++i)show(nw->sons[i]);
    --deep;
}
signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i){cin>>times[i];q.push({{times[i],0},new object(i)});}
    while((n-1)%(k-1)!=0)++n,q.push({{0,0},new object(n)});
    object*u;
    int nw;
    for(int i=1;i<=(n-1)/(k-1);++i){
        u=new object(0);
        nw=0;
        for(int j=1;j<=k;++j){
            u->sons.insert({j,q.top().second});
            nw+=q.top().first.first;
            u->height=max(u->height,q.top().first.second+1);
            q.pop();
        }
        q.push({{nw,u->height},u});
    }
    u=q.top().second;
    q.pop();
    //show(u);
    cout<<dfs(u)<<endl;
    cout<<u->height<<endl;
}