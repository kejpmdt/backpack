#include<bits/stdc++.h>
using namespace std;
#define MAXN 5005
#define MAXM 10005
int fst[MAXN],nt[MAXM];
int to[MAXM];
int sz[MAXN];
int f[MAXN];
int ff[MAXN];
void addline(int a,int b){
    static int i=0;
    to[++i]=b,nt[i]=fst[a],fst[a]=i;
    to[++i]=a,nt[i]=fst[b],fst[b]=i;
}
int dps(int x){
    int t;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;++i)scanf("%d",&f[i+1]);
    int a,b;
    for(int i=1;i<n;++i){
        scanf("%d%d",&a,&b);
        addline(a,b);
    }
