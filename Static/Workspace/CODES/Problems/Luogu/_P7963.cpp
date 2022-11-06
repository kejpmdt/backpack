#include<cstdio>
#define mi2(a,b) (a<b?a:b)
#define mx2(a,b) (a>b?a:b)
using namespace std;
template<class T>
void read(T&ans){
   ans=0;
   char us=getchar();
   bool f=false;
   while(us<48||us>57){
      f|=(us==45);
      us=getchar();
   }
   while(us>47&&us<58){
      ans=(ans<<1)+(ans<<3)+(us^48);
      us=getchar();
   }
   ans*=f?-1:1;
   return;
}
template<class T,class ...O>
void read(T&x,O&...oth){
   read(x);
   read(oth...);
}
int qs[100005][4];
int main(){
   int n,m,q;
   signed char**mp[2];
   int t,i,j;
   read(t);
   char uschar;
   while(t--){
      delete mp;
      read(n,m,q);
      mp[0]=new signed char*[n+2];
      mp[1]=new signed char*[n+2];
      for(i=0;i<=n;++i){
         mp[0][i]=new signed char[m+2];
         mp[1][i]=new signed char[m+2];
      }
      for(i=1;i<=n;++i){
         for(j=1;j<m;++j){
            uschar=getchar();
            mp[0][i][j]=uschar^48;
         }
         getchar();
      }
      for(i=1;i<n;++i){
         for(j=1;j<=m;++j){
            mp[1][i][j]=uschar^48;
         }
         getchar();
      }
      for(i=1;i<=q;++i){
         read(qs[i][0],qs[i][1],qs[i][2],qs[i][3]);
         

   }
   return 0;
}
