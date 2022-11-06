#include<bits/stdc++.h>
#define MAXN 1000000
#define MAXM 100000
#define MAXQ 1000000
using namespace std;
int nums[10];
int main(){
    freopen("seed.txt","r",stdin);
    int n;
    cin>>n;
    fclose(stdin);
    freopen("seed.txt","w",stdout);
    srand(n);
    cout<<rand();
    freopen("T1.in","w",stdout);
    int R=10;
    n=MAXN;
    int m=MAXM;
    int q=MAXQ;
    for(int i=0;i<R;++i){
        nums[i]=rand()%m+1;
    }
    printf("%d %d %d\n",n,m,q);
    int l,r,x,opt;
    for(int i=1;i<=n;++i){
        printf("%d ",nums[rand()%R]);
    }
    for(int i=1;i<=q;++i){
        opt=rand()%2+1;
        l=rand()%n+1;
        r=rand()%n+1;
        if(l>r)swap(l,r);
        if(opt==1)x=nums[rand()%R];
        else x=rand()%m+1;
        printf("\n%d %d %d %d",opt,l,r,x);
    }
    return 0;
}