这道题目的前置芝士：

> 线段树、简单DP（递推）、离散化

---

讲一下解题过程：

首先，我们审视一下题面：

> 维护一个序列，长度为n，序列中的数只有 `10` 种，操作分 `2` 种：
>
> 1.区间推平。
>
> 2.查询区间中的元素能否拼成给定整数。

看到第一个操作，首先想到 `ODT`。

可惜数据范围有些不友好，没敢用。

然后就是更为朴素的维护方法：线段树。

`1e6` 的数据范围，怎么看都和线段树脱不了关系。

然后考虑第二个操作。

我们有一个朴素的想法：利用线段树（或 `ODT`）查询该区间有哪些数，然后暴力跑一遍 $\mathcal O(m)$ 的DP。

可惜时间会假掉。

那我们考虑一下题目给的限制：最多只有 `10` 种数。

我们可以发现，在这种情况下，总共可能出现的情况数也就 `1024` 种，可以预处理。

那我们的时间复杂度就从 $\mathcal O(nmlogn)$ 优化成了 $\mathcal O(m+nlogn)$，完全可以接受。

---

那么，就上代码吧。

```cpp
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
```

这里为了缩短代码，我使用了 `STL` 来进行离散化。

---

updated: 写完后`5`min

`ODT`可以，比线段树快。