#include<bits/stdc++.h>
template<typename T>void read(T&ans){
    ans=0;char us=getchar();bool f=false;
    while(us!=EOF&&(us<48||us>57)){f|=(us==45);us=getchar();}
    while(us>47&&us<58){ans=(ans<<1)+(ans<<3)+(us^48);us=getchar();}
    ans=f?-ans:ans;
}
template<typename T,typename ...O>void read(T&x,O&...oth){read(x);read(oth...);}
template<typename T=signed int>T read(void){T x;read(x);return x;}
using namespace std;
int q, n, k;

int main() {
	q = read();
    freopen("buildout.txt","w",stdout);
    string u,s;
	for(int i=1;i<=q;++i){
        putchar('\"');
		k = i;
        u="";
		for(int i = 1; i < k; ++i) {
            u=(char)(i+'a'-1)+u;
            cout<<u<<u;
		}
        s="";
        u="";
        for(int i=1;i<=k;++i){
            u=(char)(i+'a'-1)+u;
            s=u+s;
        }
        cout<<s;
        putchar('\"');
        putchar(',');
		putchar('\n');
	}
	return 0;
}