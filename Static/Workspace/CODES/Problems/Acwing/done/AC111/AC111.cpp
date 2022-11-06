#include <cstdio>
#include <queue>
#include <algorithm>
#define MAXN 50005
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
int stalls[MAXN];
struct cow{
	int frm;
	int end;
	int num;
	bool operator < (cow x)const{return frm<x.frm;}
}cows[MAXN];
struct stall{
	int num;
	int time;
	bool operator < (stall x)const{return time>x.time;}
};
stall makeit(int num,int time){return stall{num,time};}
priority_queue<stall>q;
int main(){
	int n=read();
	int i;
	for(i=1;i<=n;++i){
		cows[i].frm=read();
		cows[i].end=read();
		cows[i].num=i;
	}
	sort(cows+1,cows+n+1);
	int nw=0;
	for(i=1;i<=n;++i){
		if(q.empty()||q.top().time>=cows[i].frm){
			stalls[cows[i].num]=++nw;
			q.push(makeit(nw,cows[i].end));
			continue;
		}
		stalls[cows[i].num]=q.top().num;
		q.push(makeit(q.top().num,cows[i].end));
		q.pop();
		continue;
	}
	put(nw);
	putchar(10);
	for(i=1;i<=n;++i){
		put(stalls[i]);
		putchar(10);
	}
	return 0;
}

