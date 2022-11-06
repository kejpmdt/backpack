#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q;
int main(){
    int t,n;
    int u;
    int mi;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        mi=0x7fffffff;
        while(!q.empty())q.pop();
        while(n--){
            scanf("%d",&u);
            q.push(u);
            mi=min(mi,u);
        }
        int ans=0;
        while(q.top()>=2*mi){
            if(q.top()>=4*mi-1){
                if(q.top()%(2*mi-1)==0)--ans;
                ans+=((q.top())/(2*mi-1))-1;
            }
            q.pop();
            ++ans;
        }
        cout<<ans<<'\12';
    }
    return 0;
}
