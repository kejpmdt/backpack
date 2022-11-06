#include <cstdio>
using namespace std;
int main(){
	int n,a,b,c,d,e,f,i,j,k,ans=0;
	scanf("%d%d%d%d%d%d%d",&n,&a,&b,&c,&d,&e,&f);
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)for(k=1;k<=n;++k)if((((i-a+n)%n<=2||(a-i+n)%n<=2)&&((j-b+n)%n<=2||(b-j+n)%n<=2)&&((k-c+n)%n<=2||(c-k+n)%n<=2))||(((i-d+n)%n<=2||(d-i+n)%n<=2)&&((j-e+n)%n<=2||(e-j+n)%n<=2)&&((k-f+n)%n<=2||(f-k+n)%n<=2)))++ans;
	printf("%d",ans);
	return 0;
}