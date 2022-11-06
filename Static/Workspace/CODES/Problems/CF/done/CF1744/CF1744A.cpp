#include<bits/stdc++.h>
using namespace std;
int lst[100];
int a[100];
string s;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(lst,0x00,sizeof lst);
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
        }
        cin>>s;
        for(int i=1;i<=n;++i){
            if(lst[a[i]]&&s[i-1]!=s[lst[a[i]]-1]){
                cout<<"NO\12";
                goto ed;
            }
            lst[a[i]]=i;
        }
        cout<<"YES\12";
ed:;
    }
    return 0;
}

