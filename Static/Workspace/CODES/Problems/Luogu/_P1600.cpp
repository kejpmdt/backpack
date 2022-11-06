#include<cstdio>
using namespace std;
int fst[300005],nt[600005],to[600005];
int big[300005],zpld[300005],size[300005];
int fa[300005],deep[300005];
int read(void){T ans;static bool f;static char us=getchar();ans=0;f=false;while(us<48||us>57){f|=(us==45);us=getchar();}while(us>47&&us<58){ans=(ans<<1)+(ans<<3)+(us^48);us=getchar();}return f?-ans:ans;}
int n,m;
void dfs1(int nw){
	size[nw]=1;
	for(int i=fst[nw];i;i=nt[i]){
		if(to[i]==fa[nw])continue;
		fa[to[i]]=nw;
		deep[to[i]]=deep[nw]+1;
		dfs1(to[i]);
		size[nw]+=size[to[i]];
		if(size[big[nw]]<=size[to[i]])big[nw]=to[i];
	}
}
void dfs2(int nw,int ld){
	zpld[nw]=ld;
	if(big[nw])dfs2(big[nw],ld);
	for(int i=fst[nw];i;i=nt[i]){
		if(to[i]==fa[nw])continue;
		if(to[i]==big[nw])continue;
		dfs2(to[i],nw);
	}
}
int main(){
	
	n=read();
	m=read();
	int u,v;
	for(int i=1;i<n;++i){
		u=read();v=read();
		to[i<<1]=v;
		to[i<<1|1]=u;
		nt[i<<1]=fst[u];
		nt[i<<1|1]=fst[v];
		fst[u]=i<<1;
		fst[v]=i<<1|1;
	}
	dfs1(1);
	dfs2(1,1);
	
}
