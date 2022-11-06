#include <cstdio>
#define MAXN 100005
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
int us[MAXN];
void MergeSort(int l,int r){
	if(l==r)return;
	MergeSort(l,l+r>>1);
	MergeSort(l+r>>1|1,r);
	static int i,j,k;
	i=l;j=l+r>>1|1;k=l;
	while(i<=l+r>>1&&j<=r)us[k++]=a[i]>a[j]?a[j++]:a[i++];
	while(i<=l+r>>1)us[k++]=a[i++];
	while(j<=r)us[k++]=a[j++];
	k=l;while(k<=r)a[k++]=us[k++];
	return;
}
int main(){
	int n;
	n=read();
	for(int i=0;i<n;++i)a[i]=read();
	MergeSort(0,n-1);
	for(int i=0;i<n;++i)put(a[i]),putchar(32);
	return 0;
}