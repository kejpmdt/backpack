#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T&ans){
    ans=0;char us=getchar();bool f=false;
    while(us!=EOF&&(us<48||us>57)){f|=(us==45);us=getchar();}
    while(us>47&&us<58){ans=(ans<<1)+(ans<<3)+(us^48);us=getchar();}
    ans=f?-ans:ans;
}
template<typename T,typename ...O>void read(T&x,O&...oth){read(x);read(oth...);}
template<typename T=signed int>T read(void){T x;read(x);return x;}
#define MAXN 3005
#define MAXM 6005
int fst[MAXN],nt[MAXM];
int to[MAXM];
int f[MAXN][MAXN];
void addline(int a,int b){
    static int i=0;
    to[++i]=b,nt[i]=fst[a],fst[a]=i;
    to[++i]=a,nt[i]=fst[b],fst[b]=i;
}
int main(){
}