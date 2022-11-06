#include<bits/stdc++.h>
using namespace std;
#define MAXN 5005
struct square{
    int x1,x2,y1,y2;
}squares[MAXN];
struct line{
    int up,down,x;
};
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)scanf("%d%d%d%d",&squares[i].x1,&squares[i].y1,&squares[i].x2,&squares[i].y2);

}
