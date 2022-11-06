#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T&ans){
    ans=0;char us=getchar();bool f=false;
    while(us!=EOF&&(us<48||us>57)){f|=(us==45);us=getchar();}
    while(us>47&&us<58){ans=(ans<<1)+(ans<<3)+(us^48);us=getchar();}
    ans=f?-ans:ans;
}
template<typename T,typename ...O>void read(T&x,O&...oth){read(x);read(oth...);}
template<typename T=signed int>T read(void){T x;read(x);return x;}
long long ori[100005];
multiset<long long>rposi,rnega,lposi,lnega;
template<typename T>T mxx(T a,T b){return a>b?a:b;}
template<typename T,typename ...O>T mxx(T a,T b,O ...oth){return mxx(mxx(a,b),oth...);}
int main(){
    long long ans;
    long long a,b,c,d,e,f,g,h;
    int t;
    read(t);
    int n;
    while(t--){
        read(n);
        ans=0x8000000000000000ll;
        rposi.clear();
        rnega.clear();
        lposi.clear();
        lnega.clear();
        for(int i=1;i<=n;++i){
            read(ori[i]);
            if(ori[i]>=0)rposi.insert(ori[i]);
            else rnega.insert(ori[i]);
        }
        if(ori[1]>=0)rposi.erase(rposi.find(ori[1]));
        else rnega.erase(rnega.find(ori[1]));
        if(ori[1]>=0)lposi.insert(ori[1]);
        else lnega.insert(ori[1]);
        for(int i=2;i<n;++i){
            if(ori[i]>=0)rposi.erase(rposi.find(ori[i]));
            else rnega.erase(rnega.find(ori[i]));
            if(ori[i]>0){
                a=lposi.empty()?0x7fffffff:*--lposi.lower_bound(ori[i]);
                if(a >= ori[i])a=0x7fffffff;
                b=lposi.empty()?0x7fffffff:*lposi.begin();
                if(b >= ori[i])b=0x7fffffff;
                c=lnega.empty()?0x7fffffff:*--lnega.end();
                if(c >= ori[i])c=0x7fffffff;
                d=lnega.empty()?0x7fffffff:*lnega.begin();
                if(d >= ori[i])d=0x7fffffff;
                f=rposi.empty()?0x7fffffff:*--rposi.end();
                if(f <= ori[i])f=0x7fffffff;
                e=(rposi.empty()||f==0x7fffffff)?0x7fffffff:*rposi.upper_bound(ori[i]);
                if(e <= ori[i])e=0x7fffffff;
                ans=mxx(ans,(a==0x7fffffff||e==0x7fffffff)?ans:(a*e*ori[i]),(b==0x7fffffff||e==0x7fffffff)?ans:(b*e*ori[i]),(c==0x7fffffff||e==0x7fffffff)?ans:(c*e*ori[i]),(d==0x7fffffff||e==0x7fffffff)?ans:(d*e*ori[i]),(a==0x7fffffff||f==0x7fffffff)?ans:(a*f*ori[i]),(b==0x7fffffff||f==0x7fffffff)?ans:(b*f*ori[i]),(c==0x7fffffff||f==0x7fffffff)?ans:(c*f*ori[i]),(d==0x7fffffff||f==0x7fffffff)?ans:(d*f*ori[i]));
            }
            else if(ori[i]<0){
                a=lnega.empty()?0x7fffffff:*--lnega.lower_bound(ori[i]);
                if(a >= ori[i])a=0x7fffffff;
                b=lnega.empty()?0x7fffffff:*lnega.begin();
                if(b >= ori[i])b=0x7fffffff;
                f=rnega.empty()?0x7fffffff:*--rnega.end();
                if(f <= ori[i])f=0x7fffffff;
                e=(rnega.empty()||f==0x7fffffff)?0x7fffffff:*rnega.upper_bound(ori[i]);
                if(e <= ori[i])e=0x7fffffff;
                g=rposi.empty()?0x7fffffff:*rposi.begin();
                if(g <= ori[i])e=0x7fffffff;
                h=rposi.empty()?0x7fffffff:*--rposi.end();
                if(h <= ori[i])f=0x7fffffff;
                ans=mxx(ans,(a==0x7fffffff||e==0x7fffffff)?ans:(a*e*ori[i]),(a==0x7fffffff||f==0x7fffffff)?ans:(a*f*ori[i]),(a==0x7fffffff||g==0x7fffffff)?ans:(a*g*ori[i]),(a==0x7fffffff||h==0x7fffffff)?ans:(a*h*ori[i]),(b==0x7fffffff||e==0x7fffffff)?ans:(b*e*ori[i]),(b==0x7fffffff||f==0x7fffffff)?ans:(b*f*ori[i]),(b==0x7fffffff||g==0x7fffffff)?ans:(b*g*ori[i]),(b==0x7fffffff||h==0x7fffffff)?ans:(b*h*ori[i]));
            }
            else {
                a=lnega.empty()?0x7fffffff:*--lnega.end();
                if(a >= ori[i])a=0x7fffffff;
                b=lnega.empty()?0x7fffffff:*lnega.begin();
                if(b >= ori[i])b=0x7fffffff;
                g=rposi.empty()?0x7fffffff:*rposi.begin();
                if(g <= ori[i])e=0x7fffffff;
                h=rposi.empty()?0x7fffffff:*--rposi.end();
                if(h <= ori[i])f=0x7fffffff;
                ans=mxx(ans,(a==0x7fffffff||g==0x7fffffff)?ans:(a*g*ori[i]),(b==0x7fffffff||g==0x7fffffff)?ans:(b*g*ori[i]),(a==0x7fffffff||h==0x7fffffff)?ans:(a*h*ori[i]),(b==0x7fffffff||h==0x7fffffff)?ans:(b*h*ori[i]));
            }
            if(ori[i]>=0)lposi.insert(ori[i]);
            else lnega.insert(ori[i]);
        }
        if(ans!=(signed long long int)0x8000000000000000ll)cout<<ans<<endl;
        else cout<<-1<<endl;
    }
}