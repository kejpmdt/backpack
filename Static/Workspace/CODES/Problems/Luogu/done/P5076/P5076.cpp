#include<bits/stdc++.h>
using namespace std;
struct node{
    int lc,rc,fa;
    int sz;
    int num;
    int sum;
    int cnt;
}nodes[10004];
int cnt=1;
void ins(int x){
    int nw=1;
    while(1){
        if(nodes[nw].num==x){
            ++nodes[nw].cnt;
            while(nw){
                ++nodes[nw].sum;
                nw=nodes[nw].fa;
            }
            ++nodes[nw].sum;
            return;
        }
        if(nodes[nw].num<x){
            if(nodes[nw].rc==0){
                nodes[nw].rc=++cnt;
                nodes[cnt].fa=nw;
                nodes[cnt].num=x;
            }
            nw=nodes[nw].rc;
        }
        else{
            if(nodes[nw].lc==0){
                nodes[nw].lc=++cnt;
                nodes[cnt].fa=nw;
                nodes[cnt].num=x;
            }
            nw=nodes[nw].lc;
        }
    }
}
int Rank(int x){
    int nw=1;
    int ans=0;
    while(1){
        if(nodes[nw].num==x)return ans+1;
        if(nodes[nw].num<x)ans=ans+nodes[nw].sum-nodes[nodes[nw].rc].sum,nw=nodes[nw].rc;
        else nw=nodes[nw].lc;
    }
}
int ranker(int x){
    int nw=1;
    while(1){
        if(nodes[nodes[nw].lc].sum>=x){
            nw=nodes[nw].lc;
            continue;
        }
        else x-=nodes[nodes[nw].lc].sum;
        if(nodes[nw].cnt>=x){
            return nodes[nw].num;
        }
        else{
            x-=nodes[nw].cnt;
            nw=nodes[nw].rc;
        }
    }
}
int pre(int x){
    int nw=1;
    int ans=0xffffffff;
    while(1){
        if(nodes[nw].num==x){
            nw=nodes[nw].lc;
            while(nw){
                ans=nodes[nw].num;
                nw=nodes[nw].rc;
            }
            return ans;
        }
        if(nodes[nw].num<x){
            ans=nodes[nw].num;
            nw=nodes[nw].rc;
        }
        else{
            nw=nodes[nw].lc;
        }
    }
}
int nxt(int x){
    int nw=1;
    int ans=0x7fffffff;
    while(1){
        if(nodes[nw].num==x){
            nw=nodes[nw].rc;
            while(nw){
                ans=nodes[nw].num;
                nw=nodes[nw].lc;
            }
            return ans;
        }
        if(nodes[nw].num<x){
            nw=nodes[nw].rc;
        }
        else{
            ans=nodes[nw].num;
            nw=nodes[nw].lc;
        }
    }
}
int main(){
    int q;
    cin>>q;
    int op,x;
    nodes[1].num=0x7fffffff;
    nodes[1].cnt=nodes[1].sum=1;
    while(q--){
        cin>>op>>x;
        if(op==1){
            cout<<Rank(x)<<endl;
        }
        if(op==2){
            cout<<ranker(x)<<endl;
        }
        if(op==3){
            cout<<pre(x)<<endl;
        }
        if(op==4){
            cout<<nxt(x)<<endl;
        }
        if(op==5){
            ins(x);
        }
    }
}