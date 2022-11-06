#include <cstdio>
#include <cstring>
#define mx2(a,b) (a>b?a:b)
#define MAXM 5005
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
int add[MAXM][MAXM];
int main(){
	int n,m;
	n=read();m=read();
//	int x,y,v;
	while(n--)add[read()+2][read()+2]+=read();
	register int i,j;
	int ans=0;
	for(i=1;i<MAXM;++i)for(j=1;j<MAXM;++j)add[i][j]+=add[i-1][j]+add[i][j-1]-add[i-1][j-1];
	for(i=m+1;i<MAXM;++i)for(j=m+1;j<MAXM;++j)ans=mx2(ans,add[i][j]-add[i][j-m]-add[i-m][j]+add[i-m][j-m]);
	put(ans);
	return 0;
}