#include<bits/stdc++.h>
using namespace std;
#define MAXN 300
#define MAXK 5
#define MAXX 10000
int main(){
    freopen("seed.txt","r",stdin);
    int n;
    cin>>n;
    srand(n);
    fclose(stdin);
    freopen("seed.txt","w",stdout);
    cout<<rand();
    freopen("P2168_.in","w",stdout);
    int k;
    n=rand()%MAXN+1;
    k=rand()%MAXK+1;
    cout<<n<<' '<<k<<endl;
    for(int i=1;i<=n;++i){
        cout<<rand()%MAXX+1<<endl;
    }
    fclose(stdout);
}