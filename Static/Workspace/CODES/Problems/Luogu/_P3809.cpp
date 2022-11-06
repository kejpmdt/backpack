#include<bits/stdc++.h>
#define lowbit(x) (x&-(x))
using namespace std;
void radixsort(vector<pair<pair<int,int>,int>>&v){
}
int main(){
    string s;
    cin>>s;
    s+="$";
    int n=s.size();
    int nw=0;
    while(n!=lowbit(n)){
        ++n;
        s+=s[nw++];
    }
    vector<pair<char,int>>v(n);
    for(int i=0;i<n;++i)v[i]={s[i],i};
    sort(v.begin(),v.end());
    vector<pair<pair<int,int>,int>>u(n);
    int nw=1;
    while(nw!=n){
        for(int i=0;i<n;++i){
            u[i]={{i,(i+nw)%n},i};
}
