#include<bits/stdc++.h>
using namespace std;
int s[115];
int ssg[10014];
int k;
int sg(int x){
    if(ssg[x]!=-1)return ssg[x];
    unordered_set<int>ss;
    ss.clear();
    int i;
    for(i=0;i<k;++i)if(x-s[i]>=0)ss.insert(sg(x-s[i]));
    for(i=0;;++i)if(!ss.count(i))return ssg[x]=i;
}
int main(){
    cin>>k;
    for(int i=0;i<k;++i){
        cin>>s[i];
    }
    memset(ssg,0xff,sizeof ssg);
    int n;
    cin>>n;
    int u=0;
    while(n--){
        int a;
        cin>>a;
        u^=sg(a);
    }
    cout<<(u==0?"No":"Yes");
    return 0;
}
