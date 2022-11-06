#include<bits/stdc++.h>
using namespace std;
int inp[100005];
int p;
struct node{
    int l,r;
    node*lc,*rc;
    long long add;
    long long times;
    long long sum;
    void build(int L,int R){
        l=L,r=R;
        add=0;
        times=1;
        if(l==r){
            sum=inp[l];
            lc=rc=nullptr;
            return;
        }
        lc=new node;
        rc=new node;
        lc->build(l,l+r>>1);
        rc->build((l+r>>1)+1,r);
        pushup();
    }
    void pushup(void){
        sum=(lc->sum+rc->sum)%p;
    }
    void pushdown(void){
        lc->times*=times;
        lc->add*=times;
        lc->sum*=times;
        rc->times*=times;
        rc->add*=times;
        rc->sum*=times;
        times=1;
        lc->add+=add;
        lc->sum+=(lc->r-lc->l+1)*add;
        rc->add+=add;   
        rc->sum+=(rc->r-rc->l+1)*add;
        add=0;
        lc->times%=p;
        lc->add%=p;
        lc->sum%=p;
        rc->times%=p;
        rc->add%=p;
        rc->sum%=p;
    }
    int ask(int L,int R){
        if(L<=l&&R>=r){
            return sum;
        }
        if(L>r||R<l)return 0;
        pushdown();
        return (lc->ask(L,R)+rc->ask(L,R))%p;
    }
    void addd(int L,int R,int x){
        if(L<=l&&R>=r){
            add+=x;
            sum+=(r-l+1)*x;
            add%=p;
            sum%=p;
            return;
        }
        if(R<l||L>r){
            return;
        }
        pushdown();
        lc->addd(L,R,x);
        rc->addd(L,R,x);
        pushup();
        return;
    }
    void timess(int L,int R,int x){
        if(L<=l&&R>=r){
            add*=x;
            sum*=x;
            times*=x;
            add%=p;
            sum%=p;
            times%=p;
            return;
        }
        if(R<l||L>r){
            return;
        }
        pushdown();
        lc->timess(L,R,x);
        rc->timess(L,R,x);
        pushup();
        return;
    }
}*root;
int n,m;
int main(){
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;++i)scanf("%d",&inp[i]);
    int opt,l,r,x;
    root=new node;
    root->build(1,n);
    while(m--){
        scanf("%d%d%d",&opt,&l,&r);
        switch(opt){
            case 1:
                scanf("%d",&x);
                root->timess(l,r,x%p);
                break;
            case 2:
                scanf("%d",&x);
                root->addd(l,r,x%p);
                break;
            case 3:
                cout<<root->ask(l,r)<<'\12';
                break;
        }
    }
}



