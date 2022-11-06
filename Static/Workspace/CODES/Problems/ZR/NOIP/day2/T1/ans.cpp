#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int inp[1000006];
bool pd[1024][100005];
int u[2000006];
struct node{
    int l,r;
    node*lc,*rc;
    int change;
    int nums[11];
    void build(int L,int R){
        l=L,r=R;
        change=-1;
        if(l==r){
            memset(nums,0x00,sizeof nums);
            nums[inp[l]]=1;
            lc=rc=nullptr;
            return;
        }
        lc=new node;
        rc=new node;
        lc->build(l,l+r>>1);
        rc->build((l+r>>1)+1,r);
        for(int i=1;i<=10;++i)nums[i]=lc->nums[i]+rc->nums[i];
    }
    void assign(int L,int R,int x){
        if(L<=l&&R>=r){
            change=x;
            memset(nums,0x00,sizeof nums);
            nums[x]=r-l+1;
            return;
        }
        if(l>R||r<L)return;
        pushdown();
        lc->assign(L,R,x);
        rc->assign(L,R,x);
        pushup();
    }
    void pushdown(void){
        if(change>=0){
            lc->change=rc->change=change;
            memset(lc->nums,0x00,sizeof lc->nums);
            memset(rc->nums,0x00,sizeof rc->nums);
            lc->nums[change]=lc->r-lc->l+1;
            rc->nums[change]=rc->r-rc->l+1;
            change=-1;
        }
    }
    void pushup(void){
        for(int i=1;i<=10;++i)nums[i]=lc->nums[i]+rc->nums[i];
    }
    int ask(int L,int R){
        int ans=0;
        if(L<=l&&R>=r){
            int u=1;
            for(int i=1;i<=10;++i,u<<=1)
                if(nums[i]>0)
                    ans|=u;
            return ans;
        }
        if(l>R||r<L)return 0;
        pushdown();
        return lc->ask(L,R)|rc->ask(L,R);
    }
}*root;
struct ask{
    int opt,l,r,x;
}asks[1000005];
int main(){
    scanf("%d%d%d",&n,&m,&q);
    register int i,j,k;
    for(i=1;i<=n;++i)
        scanf("%d",&inp[i]),u[i]=inp[i];
    for(i=1;i<=q;++i)
        scanf("%d%d%d%d",&asks[i].opt,&asks[i].l,&asks[i].r,&asks[i].x);
    k=n;
    for(i=1;i<=q;++i)
        if(asks[i].opt==1)
            u[++k]=asks[i].x;
    sort(u+1,u+k+1);
    int len=unique(u+1,u+k+1)-u;
    int nw=1;
    for(i=1;i<1024;++i)pd[i][0]=true;
    for(k=1;k<len;++k,nw<<=1){
        for(i=1;i<1<<(len-1);++i){
            if(!(i&nw))continue;
            for(j=0;j+u[k]<=m;++j)
                pd[i][j+u[k]]|=pd[i][j];
        }
    }
    for(i=1;i<=n;++i)inp[i]=lower_bound(u+1,u+len,inp[i])-u;
    for(i=1;i<=q;++i)
        if(asks[i].opt==1)
            asks[i].x=lower_bound(u+1,u+len,asks[i].x)-u;
    root=new node;
    root->build(1,n);
    for(i=1;i<=q;++i){
        if(asks[i].opt==1){
            root->assign(asks[i].l,asks[i].r,asks[i].x);
        }
        else{
            j=root->ask(asks[i].l,asks[i].r);
            if(pd[j][asks[i].x])cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}