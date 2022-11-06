#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXN 1005
using namespace std;
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
	return x<0?putchar(45),put(-x):putchar(x>9?put(x/10),x%10|48:x%10|48),true;
}
int n,d;
struct island{
	float frm,to;
	bool operator < (island a)const {return to<a.to;}
	void turn(void){
		static float us;
		us=sqrt(d*d-to*to);
		to=frm+us;
		frm=frm-us;
	}
};
island islands[MAXN];
int main(){
	n=read();d=read();
	int i;
	for(i=1;i<=n;++i){
		islands[i].frm=read();
		islands[i].to=read();
		if(islands[i].to>d||islands[i].to<-d){
			put(-1);
			return 0;
		}
	}
	for(i=1;i<=n;++i)islands[i].turn();
	sort(islands+1,islands+n+1);
	float nw=-3000;
	int ans=0;
	for(i=1;i<=n;++i){
		if(islands[i].frm<=nw&&islands[i].to>=nw){
			continue;
		}
		++ans;
		nw=islands[i].to;
	}
	put(ans);
	return 0;
}
