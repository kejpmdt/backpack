#include<cstdio>
#include<algorithm>
#define mi2(a,b) (a<b?a:b)
#define mx2(a,b) (a>b?a:b)
using namespace std;
int n;
int a[1000005];
template<typename T>
void read(T&ans)
{
    ans=0;
    char us=getchar();
    bool f=false;
    while(us<48||us>57){
        f|=(us==45);
        us=getchar();
    }
    while(us>47&&us<58){
        ans=(ans<<1)+(ans<<3)+(us^48);
        us=getchar();
    }
    ans*=f?-1:1;
    return;
}
template<typename T,typename ...O>
void read(T&x,O&...oth)
{
    read(x);
    read(oth...);
}
template<typename T=signed int>T read(void){T x;read(x);return x;}
int q[1000005];
int ss,tt;
bool check(int x){
    int l,r;
    for(int i=1;i+x-1<=n;++i){
        
    }
}
int main(){
    n=read();
    if(n==0){
        printf("0");
        return 0;
    }
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=n;++i)a[i]+=a[i-1];
    int l,r;
    l=0;r=n;
    while(l<r-1){
        if(check(l+r>>1)){
            l=l+r>>1;
        }
        else{
            r=l+r>>1;
        }
    }
    printf("%d",l);
    return 0;
}

