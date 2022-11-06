#include<cstdio>
#include<algorithm>
#define mi2(a,b) (a<b?a:b)
#define mx2(a,b) (a>b?a:b)
using namespace std;
int n;
long long a[1000005];
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

int main(){
    n=read();
    if(n<=1){
        printf("0");
        return 0;
    }
    long long sum=0;
    int ans=0;
    for(int i=1;i<=n;++i)a[i]=read();
    sort(a+1,a+n+1);
    int nw=1;
    for(int i=1;i<=n;++i){
        sum+=a[i];
        while(a[nw]*i<=sum&&nw<i)++nw;
        ans=mx2(ans,i-nw+1);
    }
    printf("%d\n",ans);
    return 0;
}

