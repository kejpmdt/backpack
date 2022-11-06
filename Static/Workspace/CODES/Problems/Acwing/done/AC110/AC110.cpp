#include <cstdio>
#include <algorithm>
#define MAXN 2505
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
	return putchar(x>9?put(x/10),x%10|48:x%10|48),true;
}
struct cow{
	int low;
	int high;
	bool operator < (cow x) const { return high<x.high;}
};
struct bottle{
	int data;
	int num;
	bool operator < (bottle x) const{return data<x.data;}
};
cow cows[MAXN];
bottle bottles[MAXN];
int main(){
	int n,m;
	n=read();m=read();
	int i;
	for(i=1;i<=n;++i){
		cows[i].low=read();
		cows[i].high=read();
	}
	for(i=1;i<=m;++i){
		bottles[i].data=read();
		bottles[i].num=read();
	}
	sort(cows+1,cows+n+1);
	sort(bottles+1,bottles+m+1);
	int j;
	int ans=0;
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			if(bottles[j].data<=cows[i].high&&bottles[j].data>=cows[i].low&&bottles[j].num>0){
				--bottles[j].num;
				++ans;
				break;
			}
		}
	}
	put(ans);
	return 0;
}
