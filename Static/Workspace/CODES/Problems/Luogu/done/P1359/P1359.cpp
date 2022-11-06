#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;
int dis[205][205];
bool zt[205];
int dist[205];
int main(){
	int n;
	scanf("%d",&n);
	memset(dist,0x7f,sizeof dist);
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j){
			scanf("%d",&dis[i][j]);
		}
	}
	deque<int>q;
	q.push_back(1);
	dist[1]=0;
	zt[1]=true;
	while(!q.empty()){
		for(int i=q.front();i<=n;++i){
			if(dist[i]>dist[q.front()]+dis[q.front()][i]){
				dist[i]=dist[q.front()]+dis[q.front()][i];
				zt[i]=false;
			}
			if(!zt[i])q.push_back(i);
			zt[i]=true;
		}
		q.pop_front();
	}
	printf("%d",dist[n]);
	return 0;
}