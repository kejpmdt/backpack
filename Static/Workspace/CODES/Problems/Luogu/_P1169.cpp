#include<cstdio>
using namespace std;
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
#define MAXN 2005
bool color[MAXN][MAXN];
int main(){
    int n,m;
    read(n,m);
    int u;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            read(u);
            color[i][j]=(u+i-j+10000)%2;
        }
    }
    