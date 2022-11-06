#include<bits/stdc++.h>
using namespace std;
int nums1[200];
int nums2[200];
int main(){
    string a,b;
    cin>>a>>b;
    long long ans=(a.size()+1)*(b.size()+1);
    for(int i=0;i<(int)a.size();++i)++nums1[(int)a[i]];
    for(int i=0;i<(int)b.size();++i)++nums2[(int)b[i]];
    for(int i='a';i<='z';++i)ans-=nums1[i]*nums2[i];
    cout<<ans;
}