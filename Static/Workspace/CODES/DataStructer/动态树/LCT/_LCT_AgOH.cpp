#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=1e5+5;
#define ls(x) (spl[x].ch[0])//x的左儿子编号
#define rs(x) (spl[x].ch[1])
#define fa(x) (spl[x].fa)
#define ident(x,f) (rs(f)==x)
#define connect(x,f,s) spl[fa(x)=f].ch[s]=x
#define update(x) spl[x].res=spl[ls(x)].res^spl[rs(x)].res^spl[x].val
#define ntroot(x) (ls(fa(x))==x||rs(fa(x))==x)
#define reverse(x) std::swap(ls(x),rs(x)),spl[x].tag^=1
class node{
    public:
        int fa,ch[2],val,res;
        bool tag;
}spl[maxn];
inline void pushdw(int x){
    if(spl[x].tag){
        if(ls(x))reverse(ls(x));
        if(rs(x))reverse(rs(x));
    }
    spl[x].tag=0;
}
inline void rotate(int x){
    int f=fa(x),ff=fa(f),k=ident(x,f);
    connect(spl[x].ch[k^1],f,k);
    fa(x)=ff;
    if(ntroot(f))spl[ff].ch[ident(f,ff)]=x;
    connect(f,x,k^1);
    update(f),update(x);
}
inline void pushall(int x){
    if(ntroot(x))pushall(fa(x));
    pushdw(x);
}
inline void splaying(int x){
    pushall(x);
    while(ntroot(x)){
        int f=fa(x),ff=fa(f);
        if(ntroot(f))ident(f,ff)^ident(x,f)?rotate(x):rotate(f);
        rotate(x);
    }
}
inline void access(int x){
    for(int y=0;x;x=fa(y=x)){
        splaying(x);
        rs(x)=y;
        update(x);
    }
}
inline void mkroot(int x){
    access(x);
    splaying(x);
    reverse(x);
}
inline int findroot(int x){
    access(x);
    splaying(x);
    while(ls(x)){
        pushdw(x);
        x=ls(x);
    }
    splaying(x);
    return x;
}
inline void link(int x,int y){
    mkroot(x);
    if(findroot(y)==x)return;
    fa(x)=y;
}
inline void cut(int x,int y){
    mkroot(x);
    if(findroot(y)!=x||fa(y)!=x||ls(y))return;
    fa(y)=rs(x)=0;
    update(x);
}
inline void split(int x,int y){
    mkroot(x);
    access(y);
    splaying(y);
}
inline int read(void){
    int ans=0;
    char us=getchar();
    bool f=false;
    while(us<'0'||us>'9'){
        f|=(us=='-');
        us=getchar();
    }
    while(us>='0'&&us<='9'){
        ans=(ans<<1)+(ans<<3)+(us^48);
        us=getchar();
    }
    return f?-ans:ans;
}
int main(){
    int n,m;
    n=read();m=read();
    for(int i=1;i<=n;++i)spl[i].val=read();
    while(m--){
        int opt,x,y;
        opt=read();x=read();y=read();
        switch(opt){
            case 0:
                split(x,y);
                printf("%d\n",spl[y].res);
                break;
            case 1:
                link(x,y);
                break;
            case 2:
                cut(x,y);
                break;
            case 3:
                splaying(x);
                spl[x].val=y;
                update(x);
                break;
        }
    }
    return 0;
}