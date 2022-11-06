#include<cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(j<=i)printf("%d",1-(i&1));
            else printf("%d",(i&1));
        }
        printf("\n");
    }
}