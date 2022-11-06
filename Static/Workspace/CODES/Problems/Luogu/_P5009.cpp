#include <cstdio>
#include <cmath>
#define belong(x) ((x-1)/sqrtn+1)
#define begin(x) ((x-1)*sqrtn+1)
#define end(x) (x*sqrtn)
#define MAXN 200005
#define MOD

using namespace std;
int bgv[1000],ada[1000],adb[1000],adx[1000],bgab[1000];
int smv[MAXN],sma[MAXN],smb[MAXN];
int main(){
	int n,m;
	register int opt,t,x,y,z;
	n=read();m=read();
	const int sqrtn=sqrt(n);
	for(int i=1;i<=n;++i){
		smv[i]=read();
		sma[i]=read();
		smb[i]=read();
	}
	for(int i=1;i<=n;++i){
		bgv[belong(i)]+=smv[i];
		bgab[belong(i)]+=sma[i]*smb[i];
	}
	int lst=0;
	for(int i=1;i<=m;++i){
		opt=read();
		t=read();
		x=read();
		y=read();
		if(opt==1){
