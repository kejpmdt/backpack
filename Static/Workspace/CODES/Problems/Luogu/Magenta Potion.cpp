#include<bits/stdc++.h>
using namespace std;
long long inp[200005];
struct node{
    int l,r;
    long long sum,lmax,rmax,lmin,rmin,mx;
    bool _sum,_lmax,_rmax,_lmin,_rmin,_mx;
    bool _np,_hp;
    node*lc,*rc;
    void pushup(void){
        _hp=(lc->_hp)||(rc->_hp);
        _np=(lc->_np==rc->_np);
        _sum=(lc->_sum)||(rc->_sum)||(abs(lc->sum*rc->sum)>1073741824LL);
        _lmax=(lc->_lmax)||(lc->_sum&&lc->_np )||(lc->_sum&&rc->_hp)||(lc->_np&&rc->_lmax )||(!lc->_np&&rc->_lmin)||(lc->sum*rc->lmax>1073741824ll )||(lc->sum*rc->lmin>1073741824ll);
        _rmax=(rc->_rmax)||(rc->_sum&&rc->_np )||(rc->_sum&&lc->_hp)||(rc->_np&&lc->_rmax )||(!rc->_np&&lc->_rmin)||(rc->sum*lc->rmax>1073741824ll )||(rc->sum*lc->rmin>1073741824ll);
        _lmin=(lc->_lmin)||(lc->_sum&&!lc->_np)||(lc->_sum&&rc->_hp)||(!lc->_np&&rc->_lmax)||(lc->_np&&rc->_lmin )||(lc->sum*rc->lmax<-1073741824ll)||(lc->sum*rc->lmin<-1073741824ll);
        _lmin=(lc->_lmin)||(lc->_sum&&!lc->_np)||(lc->_sum&&lc->_hp)||(!lc->_np&&lc->_lmax)||(lc->_np&&lc->_lmin )||(lc->sum*lc->lmax<-1073741824ll)||(lc->sum*lc->lmin<-1073741824ll);
        _mx=(_sum&&_np)||(_lmax)||(_rmax)||(lc->_rmax)||(rc->_lmax)||(lc->rmax*rc->lmax>1073741824ll)||(lc->rmin*rc->lmin>1073741824ll);
        sum=_sum?1:lc->sum*rc->sum;
        lmax=_lmax?1:max(lc->lmax,lc->_np?lc->sum*rc->lmax:rc->_hp?lc->sum*rc->lmin:-1);
        rmax=_rmax?1:max(rc->rmax,rc->_np?rc->sum*lc->rmax:lc->_hp?rc->sum*lc->rmin:-1);
        lmin=_lmin?1:min(lc->lmin,lc->_np?rc->_hp?lc->sum*rc->lmin:1:lc->sum*rc->lmax);
        rmin=_rmin?1:min(rc->rmin,lc->_np?lc->_hp?rc->sum*lc->rmin:1:rc->sum*lc->rmax);
        mx=_mx?1:max(max(lc->mx,rc->mx),max(lc->rmax*rc->lmax,lc->rmin*rc->lmin));
    }
    void build(int L,int R){
        l=L,r=R;
        if(l==r){
            sum=inp[l];
            _np=sum>0;
            _hp=sum<0;
            if(_np){
                lmax=rmax=sum;
                lmin=rmin=1;
            }
            else{
                lmin=rmin=sum;
                lmax=rmax=1;
            }
            _sum=abs(sum)>1073741824ll;
            _lmax=lmax>1073741824ll;
            _rmax=rmax>1073741824ll;
            _lmin=lmin<-1073741824ll;
            _rmin=rmin<-1073741824ll;
            _mx=_sum&&_np;
            mx=_mx?1:sum>0?sum:1;
            lc=rc=NULL;
            return;
        }
        lc=new node;
        rc=new node;
        lc->build(l,(l+r)>>1);
        rc->build(((l+r)>>1)+1,r);
        pushup();
    }
    void change(int x,int k){
        if(x<l||x>r)return;
        if(l==r){
            sum=k;
            _np=sum>0;
            _hp=sum<0;
            if(_np){
                lmax=rmax=sum;
                lmin=rmin=1;
            }
            else{
                lmin=rmin=sum;
                lmax=rmax=1;
            }
            _sum=abs(sum)>1073741824ll;
            _lmax=lmax>1073741824ll;
            _rmax=rmax>1073741824ll;
            _lmin=lmin<-1073741824ll;
            _rmin=rmin<-1073741824ll;
            _mx=_sum&&_np;
            mx=_mx?1:sum>0?sum:1;
            return;
        }
        lc->change(x,k);
        rc->change(x,k);
        pushup();
    }
    node*ask(int L,int R){
        if(L<=l&&R>=r){
            return this;
        }
        node*res=new node;
        if(R<l||r<L){
            res->sum=res->lmin=res->rmin=res->lmax=res->rmax=1;
            res->_sum=res->_lmin=res->_rmin=res->_lmax=res->_rmax=res->_hp=false;
            res->_np=true;
            res->mx=1;
            res->_mx=false;
            return res;
        }
        res->lc=lc->ask(L,R);
        res->rc=rc->ask(L,R);
        res->pushup();
        return res;
    }
}*root;
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)scanf("%lld",&inp[i]);
    int opt,l,r;
    root=new node;
    root->build(1,n);
    node*u;
    while(q--){
        scanf("%d%d%d",&opt,&l,&r);
        if(opt==1)root->change(l,r),inp[l]=r;
        else {
            u=root->ask(l,r);
            if(u->_mx)cout<<"Too large\12";
            else cout<<u->mx<<'\12';
        }
    }
    return 0;
}
