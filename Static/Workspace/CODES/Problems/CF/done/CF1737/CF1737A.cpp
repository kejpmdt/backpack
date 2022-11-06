#include<bits/stdc++.h>
using namespace std;
int num[200];
priority_queue<pair<int,int>>q;
int main(){
    int t,n,k,r,i,j;
    string s;
    scanf("%d",&t);
    int ned;
    while(t--){
        scanf("%d%d",&n,&k);
        cin>>s;
        memset(num,0x00,sizeof num);
        for(i=0;i<n;++i)++num[(int)s[i]];
        r='y';
        for(i=0;i<k;++i){
            for(j='a';j<='z';++j){
                if(!num[j]||j-'a'>=(n/k)){
                    break;
                }
            }
            ned=n/k;
            ned-=(j-'a');
            putchar(j--);
            while(j>=97)--num[j--];
            for(j=97;num[j];++j);
            while(ned&&j<='z'){
                while(ned&&num[j])--num[j],--ned;
                if(!num[j])++j;
            }
            r=97;
            while(!q.empty())q.pop();
            for(j=97;num[j];++j){
                q.push({num[j],j});
            }
            while(ned){
                --num[q.top().second];
                --ned;
                q.push({q.top().first-1,q.top().second});
                q.pop();
            }
        }
        cout<<'\12';
    }
    return 0;
}



