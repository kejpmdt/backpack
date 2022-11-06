#include<iostream>
using namespace std;
int lst[1000006];
int num[3000006];
int main(){
    int c,n;
    scanf("%d%d",&c,&n);
    int ans=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&num[i]);
        if(lst[num[i]]==0)++ans;
        lst[num[i]]=i;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;++i)if(lst[num[i]]==i)printf("%d ",num[i]);
    return 0;
}
