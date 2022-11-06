#include<cstdio>
#define abs(x) ((x)>0?(x):-(x))
#define mx2(a,b) (a>b?a:b)
using namespace std;
int f[105][105];
int main(){
   int i,j,k,n;
   scanf("%d",&n);
   for(i=1;i<=n;++i){
      scanf("%d",&f[i][i]);
   }
   for(i=1;i<=n;++i){
      for(j=i+1;j<=n;++j){
         f[i][j]=abs(f[i][i]-f[j][j])*(j-i+1);
      }
   }
   for(k=1;k<=n;++k){
      for(i=1;i+k<=n;++i){
         for(j=0;j<k;++j){
            f[i][i+k]=mx2(f[i][i+k],f[i][i+j]+f[i+j+1][i+k]);
         }
      }
   }
   printf("%d",f[1][n]);
   return 0;
}