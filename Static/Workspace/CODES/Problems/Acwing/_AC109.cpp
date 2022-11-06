#include <cstdio>
#include <algorithm>
#define MAXN 500000
using namespace std;
int inp[MAXN];
int us[MAXN];
int us2[MAXN];
unsigned long long T;
inline int read(void){
	static int ans;
	static bool f;
	static char us=getchar();
	ans=0;
	f=false;
	while(us<48||us>57){
		f|=(us==45);
		us=getchar();
	}
	while(us>47&&us<58){
		ans=(ans<<1)+(ans<<3)+(us^48);
		us=getchar();
	}
	return f?-ans:ans;
}
bool put(int x){
	return putchar(x>9?put(x/10),x%10|48:x%10|48),true;
}
int n,m;
bool check(int s,int r,bool t=false){
	static int i,j,k;
	static int l=0;
	if(l<s)l=s;
	if(t)l=s;
	for(i=l;i<=r;++i)us2[i]=inp[i];
	sort(us2+l,us2+r+1);
	k=s;
	i=s;j=l;
	while(i<l&&j<=r)us[k++]=inp[i]<us2[j]?inp[i++]:us2[j++];
	while(i<l)us[k++]=inp[i++];
	while(j<=r)us[k++]=us2[j++];
	i=s;j=r;
	unsigned long long ans=0;
	while(i<j&&i-s<m){
		ans+=(us[j]-us[i])*(us[j--]-us[i++]);
		if(ans>T)return false;
	}
	for(i=s;i<=r;++i)inp[i]=us[i];
	l=r;
	return true;
}
int main(){
	int r2;
	r2=read();
	register int r1,st,l;
	int ans2;
	while(r2--){
		n=read();m=read();T=read();
		for(r1=1;r1<=n;++r1)inp[r1]=read();
		st=1;
		l=1;
		r1=0;
		ans2=0;
		check(st,st,true);
		while(1){
			while(1){
				if(check(st,st+l)){
					l<<=1;
					continue;
				}
				else {
					l>>=1;
					break;
				}
			}
			r1=st+l;
			l>>=1;
			while(l){
				if(check(st,r1)){
					r1+=l;
					continue;
				}
				l>>=1;
				continue;
			}
			++ans2;
			if(r1==n)break;
		}
		put(ans2);
		putchar(10);
	}
}