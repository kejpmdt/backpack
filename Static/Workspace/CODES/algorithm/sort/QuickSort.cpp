#include <cstdio>
#include <algorithm>
#define MAXN 100005
using namespace std;
int a[MAXN];
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
void qsort(int L,int R){
	int l,r;
	int mid;
	l=L;r=R;
	mid=a[rand()%(r-l+1)+l];
	do{
		while(a[l]<mid)++l;
		while(a[r]>mid)--r;
		if(l<=r)swap(a[l++],a[r--]);
	}while(l<=r);
	if(L<r)qsort(L,r);
	if(l<R)qsort(l,R);
	return;
}
int main(){
	int n;
	n=read();
	for(int i=0;i<n;++i)a[i]=read();
	qsort(0,n-1);
	for(int i=0;i<n;++i)put(a[i]),putchar(32);
	return 0;
}