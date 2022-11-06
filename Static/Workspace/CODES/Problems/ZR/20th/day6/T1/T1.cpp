#include<bits/stdc++.h>
using namespace std;
unsigned long long n,seed,k;
template<typename T>void read(T&ans){
    ans=0;char us=getchar();bool f=false;
    while(us!=EOF&&(us<48||us>57)){f|=(us==45);us=getchar();}
    while(us>47&&us<58){ans=(ans<<1)+(ans<<3)+(us^48);us=getchar();}
    ans=f?-ans:ans;
}
template<typename T,typename ...O>void read(T&x,O&...oth){read(x);read(oth...);}
template<typename T=signed int>T read(void){T x;read(x);return x;}
unsigned long long a[400005];
unsigned long long f[10];
//i0,i1,j0,j1,k0,k1,p0,p1,q0,q1
void turn(bool x){
    if(x){
        f[9]+=f[7];
        f[8]+=f[6];
        f[7]+=f[4];
        f[6]+=f[5];
        f[5]+=f[3];
        f[5]+=f[2];
        f[3]+=f[0];
        f[2]+=f[1];
        f[1]+=1;
    }
    else{
        f[8]+=f[7];
        f[8]+=f[6];
        f[7]+=f[5];
        f[6]+=f[4];
        f[5]+=f[3];
        f[4]+=f[2];
        f[3]+=f[1];
        f[2]+=f[0];
        f[0]+=1;
    }
}
int main(){
    unsigned long long i,j;
    read(n,seed,k);
    unsigned long long mod;
    mod=((k==64)?0:(1<<k));
    --mod;
    std::mt19937_64 rnd(seed);
    for(i=1;i<=n;++i)a[i]=rnd()&mod;
    unsigned long long ans=0;
    mod=1;
    for(i=0;i<k;++i,mod<<=1){
        memset(f,0x00,sizeof f);
        for(j=1;j<=n;++j)
            turn(a[j]&mod);
        ans+=(f[9]<<i);
    }
    cout<<ans;
    return 0;
}