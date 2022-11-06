#include<bits/stdc++.h>
using namespace std;
struct line{
    int a,b;
    int nt;
};
line lines[500005];
int ans[500005];
int fa[500005];
int getfa(int x){
    if(fa[fa[x]]!=fa[x])fa[x]=getfa(fa[x]);
    return fa[x];
}
int main(){
    int n,m;
    int lst0=0,lst1=0;
    int fst0=0,fst1=0;
    int c;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",&lines[i].a,&lines[i].b,&c);
        if(c==0){
            lines[lst0].nt=i;
            if(fst0==0)fst0=i;
            lst0=i;
        }
        else{
            lines[lst1].nt=i;
            if(fst1==0)fst1=i;
            lst1=i;
        }
    }
    lines[lst0].nt=lines[lst1].nt=0;
    if(fst0==0){
        for(int i=1;i<=m;++i)printf("%d ",i);
        return 0;
    }
    for(int i=1;i<=n;++i)fa[i]=i;
    for(int i=1;i<=m;++i){
        if(fst0==0||lst0==0){
            if(fst0==0){
                ans[fst0]=i;
                fa[fa[lines[fst0].a]]=getfa(lines[fst0].b);
                fst0=lines[fst0].nt;
            }
            else{
                ans[fst1]=i;
                fa[fa[lines[fst1].a]]=getfa(lines[fst1].b);
                fst1=lines[fst1].nt;
            }
        }
        else{
            if(fst1<fst0){
                ans[fst1]=i;
                fa[fa[lines[fst1].a]]=getfa(lines[fst1].b);
                fst1=lines[fst1].nt;
            }
            else{
                if(getfa(lines[fst0].a)==getfa(lines[fst0].b)){
                    ans[fst0]=i;
                    fa[fa[lines[fst0].a]]=getfa(lines[fst0].b);
                    fst0=lines[fst0].nt;
                }
                else{
                    ans[fst1]=i;
                    fa[fa[lines[fst1].a]]=getfa(lines[fst1].b);
                    fst1=lines[fst1].nt;
                }
            }
        }
    }
    for(int i=1;i<=m;++i){
        printf("%d ",ans[i]);
    }
    return 0;
}
