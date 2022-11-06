#include<bits/stdc++.h>
using namespace std;
const int N=10010,S=55,M=1000010;
int n;
int tr[N*S][26],cnt[N*S],idx;
char str[M];
int q[N*S],ne[N*S];
template<typename T>void read(T&ans){
    ans=0;char us=getchar();bool f=false;
    while(us!=EOF&&(us<48||us>57)){f|=(us==45);us=getchar();}
    while(us>47&&us<58){ans=(ans<<1)+(ans<<3)+(us^48);us=getchar();}
    ans=f?-ans:ans;
}
template<typename T,typename ...O>void read(T&x,O&...oth){read(x);read(oth...);}
template<typename T=signed int>T read(void){T x;read(x);return x;}
void insert(){
    int p=0;
    for(int i=0;str[i];++i){
        int t=str[i]-'a';
        if(!tr[p][t])tr[p][t]=++idx;
        p=tr[p][t];
    }
    cnt[p]++;
}
void build(){
    int hh=0,tt=-1;
    for(int i=0;i<26;++i)
        if(tr[0][i])q[++tt]=tr[0][i];
    while(hh<=tt){
        int t=q[hh++];
        for(int i=0;i<26;++i){
            int p=tr[t][i];
            if(!p){
                tr[t][i]=tr[ne[t]][i];
            }
            else{
                ne[p]=tr[ne[t]][i];
                q[++tt]=p;
            }
        }
    }
}
int main(){
    int T;
    read(T);
    while(T--){
        memset(tr,0x00,sizeof tr);
        memset(cnt,0x00,sizeof cnt);
        memset(ne,0x00,sizeof ne);
        idx=0;
        read(n);
        for(int i=0;i<n;++i){
            scanf("%s",str);
            insert();
        }
        build();
        scanf("%s",str);
        int res=0;
        for(int i=0,j=0;str[i];++i){
            int t=str[i]-'a';
            j=tr[j][t];

            for(int r=j;r;r=ne[r]){
                res+=cnt[r];
                cnt[r]=0;
            }
        }
        cout<<res<<endl;
    }

}