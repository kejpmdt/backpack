#include <cstdio>
#include <algorithm>
#define MAXN 5000005
using namespace std;
inline int read(void){
	static int ans;
 	static char us=getchar();
 	static bool f;
 	f=false;
 	ans=0;
 	while(us<48||57<us){
 		f|=(us=='-');
 		us=getchar();
 	}
 	while(47<us&&us<58){
 		ans=(ans<<1)+(ans<<3)+(us^48);
 		us=getchar();
 	}
 	return f?-ans:ans;
 }
bool put(int x){
	return putchar(x>9?put(x/10),x%10^48:x^48),false;
}
int a[MAXN];
int k;
int kth(int L,int R){
	int l=L,r=R,mid=a[rand()%(r-l+1)+l];
	do{
		while(a[l]<mid)++l;
		while(a[r]>mid)--r;
		if(l<=r){
			swap(a[l],a[r]);
			++l;--r;
		}
	}while(l<=r);
	if(k<=r)return kth(L,r);
	if(k>=l)return kth(l,R);
	return mid;
}
int main(){
	int n;
	n=read();k=read();
	for(int i=0;i<n;++i)a[i]=read();
	put(kth(0,n-1));
	return 0;
}
