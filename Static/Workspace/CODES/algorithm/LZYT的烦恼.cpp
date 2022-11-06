#include <cstdio>
#define MAXN 1000005
using namespace std;
template<typename T>void read(T&ans){
    ans=0;char us=getchar();bool f=false;
    while(us<48||us>57){f|=(us==45);us=getchar();}
    while(us>47&&us<58){ans=(ans<<1)+(ans<<3)+(us^48);us=getchar();}
    ans=f?-ans:ans;
}
template<typename T,typename ...O>void read(T&x,O&...oth){read(x);read(oth...);}
template<typename T=signed int>T read(void){T x;read(x);return x;}
long long usarray[MAXN];
long long seed;
void srand(long long x){seed=x;}
long long randd(void){
    seed=(seed*seed%998244353)+seed;
    seed=seed*3%998244353;
}
long long rread(){
    
}

int main()
{
    freopen("lzyt.in","r",stdin);
    freopen("lzyt.out","w",stdout);
    int n, m, q;
    read(n,m,q);
    for (int i = 1; i <= n; ++i)
    {
        read(usarray[i]);
        usarray[i] %= 998244353;
    }
    for (int i = n; i >= 2; --i)
    {
        usarray[i] -= usarray[i - 1];
        usarray[i] %= 998244353;
    }
    for (int i = n; i >= 2; --i)
    {
        usarray[i] -= usarray[i - 1];
        usarray[i] %= 998244353;
    }
    int l, r, x;
    for (int i = 1; i <= m; ++i)
    {
        read(l,r,x);
        usarray[l] += x;
        usarray[r + 1] -= (r - l + 2) * x;
        usarray[r + 2] += (r - l + 1) * x;
        usarray[i] %= 998244353;
    }
    for (int i = 2; i <= n; ++i)
    {
        usarray[i] += usarray[i - 1];
        usarray[i] %= 998244353;
    }
    for (int i = 2; i <= n; ++i)
    {
        usarray[i] += usarray[i - 1];
        usarray[i] %= 998244353;
    }
    for (int i = n - 1; i >= 1; --i)
    {
        usarray[i] += usarray[i + 1];
        usarray[i] %= 998244353;
    }
    for (int i = n - 1; i >= 1; --i)
    {
        usarray[i] += usarray[i + 1];
        usarray[i] %= 998244353;
    }
    for (int i = 1; i <= q; ++i)
    {
        read(l,r,x);
        printf("%lld ", (998244353 + (x * usarray[l] - x * (r - l + 2) * usarray[r + 1] + x * (r - l + 1) * usarray[r + 2] - (x - 1) * (usarray[l] - usarray[l + 1] - usarray[r + 1] + usarray[r + 2])) % 998244353) % 998244353);
    }
    return 0;
}