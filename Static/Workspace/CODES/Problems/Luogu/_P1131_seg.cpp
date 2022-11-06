#include<bits/stdc++.h>
#define MAXN 500005
#define MAXM 1000005
using namespace std;
int fst[MAXN],nt[MAXM];
int to[MAXM];
int v[MAXM];
int depth[MAXN];
int ndfsn[MAXN];
void addline(int a,int b,int c=1){
    static int i=0;
    to[++i]=b,nt[i]=fst[a],fst[a]=i,v[i]=c;
    to[++i]=a,nt[i]=fst[b],fst[b]=i,v[i]=c;
}
struct line{
    int l,r;
    bool operator<(const line&oth)const{
        return r-l>oth.r-oth.l;
    }
}lines[MAXN];
struct node{
    int l,r;
    int mx;
    int add;
    node*lc,*rc;
    void pushdown(){
        lc->mx+=add;
        rc->mx+=add;
        lc->add+=add;
        rc->add+=add;
        add=0;
    }
    void pushup(){
        mx=max(lc->mx,rc->mx);
    }
    void build(int L,int R){
        l=L,r=R;
        if(l==r){
            mx=depth[ndfsn[l]];
            add=0;
            lc=rc=nullptr;
            return;
        }
        lc=new node;
        rc=new node;
        pushdown();
        lc->build(L,L+R>>1);
        rc->build((L+R>>1)+1,R);
        pushup();
    }
    void addnum(int L,int R,int x){
        if(L<=l&&R>=r){
            add+=x;
            mx+=x;
            return;
        }
        pushdown();
        if(L<=l+r>>1)lc->addnum(L,R,x);
        if(R>l+r>>1)rc->addnum(L,R,x);
        pushup();
    }
    int askmax(int L,int R){
        if(L<=l&&R>=r){
            return mx;
        }
        pushdown();
        int lans=0,rans=0;
        if(L<=l+r>>1)lans=lc->askmax(L,R);
        if(R>l+r>>1)rans=rc->askmax(L,R);
        pushup();
        return max(lans,rans);
    }
};
int x;
void dfs(int nw,int f,int d,int&l,int&r){
    if(to[fst[nw]]==f)fst[nw]=nt[fst[nw]];
    depth[nw]=depth[f]+d;
    if(fst[nw]==0){
        ndfsn[++x]=nw;
        if(l==0)l=x;
        r=x;
    }
    int u;
    for(int i=fst[nw];i;i=nt[i]){
        if(to[nt[i]]==f)nt[i]=nt[nt[i]];
        u=0;
        dfs(to[i],nw,v[i],u,r);
        if(i==fst[nw])l=u;
    }
    lines[nw].l=l;
    lines[nw].r=r;
}
int main(){
    int n;
    scanf("%d",&n);
    int s;
    scanf("%d",&s);
    for(int i=1;i<n;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        addline(a,b,c);
    }
    int l,r;
    dfs(s,s,0,l,r);
    node*root;
    root=new node;
    root->build(1,x);
    sort(lines+1,lines+n+1);
    int tx=root->mx;
    int ans=0;
    int u;
    for(int i=1;i<=n;++i){
        u=tx-root->askmax(lines[i].l,lines[i].r);
        ans+=u;
        root->addnum(lines[i].l,lines[i].r,u);
    }
    printf("%d",ans);
    return 0;
}
