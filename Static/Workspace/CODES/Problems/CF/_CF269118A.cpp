#include<bits/stdc++.h>
using namespace std;
void radixsort(vector<pair<pair<int,int>,int>>&a){
    vector<int>times(a.size());
    for(int i=0;i<a.size();++i){
        ++times[a[i].first.second];
    }
    vector<pair<pair<int,int>,int>>p(a.size());
    vector<int>pos(a.size());
    pos[0]=0;
    for(int i=1;i<a.size();++i){
        pos[i]=pos[i-1]+times[i-1]; 
    }
    for(int i=0;i<a.size();++i){
        p[pos[a[i].first.second]++]={{a[i].first.first,a[i].first.second},a[i].second};
    }
    a=p;
    times.clear();
    times.resize(a.size());
    for(int i=0;i<a.size();++i){
        ++times[a[i].first.second];
    }
    pos[0]=0;
    for(int i=1;i<a.size();++i){
        pos[i]=pos[i-1]+times[i-1]; 
    }
    for(int i=0;i<a.size();++i){
        p[pos[a[i].first.second]++]={{a[i].first.first,a[i].first.second},a[i].second};
    }
    a=p;
}
int main(){
    string t;
    cin>>t;
    t+="$";
    int n;
    string r;
    vector<pair<char,int>>a(t.size());
    int len=t.size();
    for(int i=0;i<len;++i){
        a[i]={t[i],i};
    }
    sort(a.begin(),a.end());
    vector<int>p(len,0),c(len);
    for(int i=0;i<len;++i){
        p[i]=a[i].second;
    }
    c[p[0]]=0;
    for(int i=1;i<len;++i){
        if(a[i].first==a[i-1].first){
            c[p[i]]=c[p[i-1]];
        }
        else{
            c[p[i]]=c[p[i-1]]+1;
        }
    }
    vector<pair<pair<int,int>,int>>v(len);
    int k=0;
    while((1<<k)<len){
        for(int i=0;i<len;++i){
            v[i]={{c[i],c[(i+(1<<k))%len]},i};
        }
        radixsort(v);
        for(int i=0;i<len;++i){
            p[i]=v[i].second;
        }
        c[p[0]]=0;
        for(int i=1;i<len;++i){
            if(v[i].first==v[i-1].first){
                c[p[i]]=c[p[i-1]];
            }
            else{
                c[p[i]]=c[p[i-1]]+1;
            }
        }
        k++;
    }
    for(int i=0;i<len;++i){
        printf("%d ",c[i]);
    }
    return 0;
}


