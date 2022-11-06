#include <cstdio>
#include <cstring>
#define MAXN 355
#define mx2(a,b) (a>b?a:b)
using namespace std;
inline int read(void){
	static int ans;
	static char us=getchar();
	static bool f;
	ans=0;;f=false;
	while(us<'0'||us>'9'){
		f|=(us=='-');
		us=getchar();
	}
	while(us>='0'&&us<='9'){
		ans=(ans<<1)+(ans<<3)+(us^48);
		us=getchar();
	}
	return ans;
}
int f[MAXN];
int fs[MAXN];
int p[5];
int main()
{
	memset(f,0x80,sizeof f);
	int n,m;
	f[0]=fs[0];
	n=read();m=read();
	int i,j;
	for(i=0;i<n;++i)fs[i]=read();
	for(i=0;i<m;++i){
		j=read();
		++p[j];
	}
	while(p[1]--)for(i=n;i>=1;--i)f[i]=mx2(f[i],f[i-1]+fs[i]);
	while(p[2]--)for(i=n;i>=2;--i)f[i]=mx2(f[i],f[i-2]+fs[i]);
	while(p[3]--)for(i=n;i>=3;--i)f[i]=mx2(f[i],f[i-3]+fs[i]);
	while(p[4]--)for(i=n;i>=4;--i)f[i]=mx2(f[i],f[i-4]+fs[i]);
	printf("%d",f[n]);
	return 0;
}