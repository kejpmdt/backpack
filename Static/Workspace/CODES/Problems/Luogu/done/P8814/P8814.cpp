#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,d,e;
    long long a,b,c;
    long long p,q;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld%lld",&n,&d,&e);
        a=1;
        b=e*d-n-2;
        c=n;
        long long sq=sqrt(b*b-4*a*c);
        if(b*b-4*a*c<0||sq*sq!=b*b-4*a*c){
            cout<<"NO\12";
            goto ed;
        }
        p=(-b+sq)/2,q=n/p;
        if(p*q!=n){
            cout<<"NO\12";
            goto ed;
        }
        if(p>q)swap(p,q);
        cout<<p<<' '<<q<<'\12';
ed:;
    }
    return 0;
}
