#include<bits/stdc++.h>
using namespace std;
int fa[400005];
vector<int>to[400005];
int rem[400005];
int ans[400005];
int pd[400005];
int getfa(int x){
    if(fa[fa[x]]!=fa[x])fa[x]=getfa(fa[x]);
    return fa[x];
}
int n,m;
void show(void){
    for(int i=0;i<n;++i)
        printf("%d ",fa[i]);
    printf("\n");
}
int main(){
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i=1;i<=m;++i){
        scanf("%d%d",&x,&y);
        to[x].push_back(y);
        to[y].push_back(x);
    }
    for(int i=0;i<n;++i)
        fa[i]=i;
    int k;
    scanf("%d",&k);
    for(int i=1;i<=k;++i)
        scanf("%d",&rem[i]),pd[rem[i]]=i;
    ans[k]=n-k;
    for(int i=1;i<=n;++i)
        if(!pd[i])
            for(int j:to[i])
                if(!pd[j]&&getfa(i)!=getfa(j))
                    --ans[k],fa[fa[j]]=fa[i];
    for(int i=k-1;i>=0;--i){
        ans[i]=ans[i+1]+1;
        for(int j:to[rem[i+1]])
            if((pd[j]>i||pd[j]==0)&&getfa(rem[i+1])!=getfa(j))
                --ans[i],fa[fa[j]]=fa[rem[i+1]];
    }
    for(int i=0;i<=k;++i)
        printf("%d\n",ans[i]);
    return 0;
}

