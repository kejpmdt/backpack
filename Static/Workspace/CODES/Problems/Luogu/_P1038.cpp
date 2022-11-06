#include<iostream>
#include<cstdio>
#define MAXN 105
#define MAXM 10005
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
long long fst[MAXN],nt[MAXM],to[MAXM],v[MAXM];
long long U[MAXN];
long long num[MAXN];
int ins[MAXN];
void addline(int a,int b,long long c){
   static int nw=1;
   to[nw]=b;
   nt[nw]=fst[a];
   fst[a]=nw;
   v[nw]=c;
   ++ins[b];
   ++nw;
}
void deep_first_search(int nw){
   num[nw]-=U[nw];
   for(int i=fst[nw];i;i=nt[i]){
      num[to[i]]+=num[nw]*v[i];
      --ins[to[i]];
      if(ins[to[i]]==0)deep_first_search(to[i]);
   }
   if(fst[nw])num[nw]=0;
}
int main(){
   int n,p;
   read(n,p);
   int i;
   for(i=1;i<=n;++i){
      read(num[i],U[i]);
   }
   long long a,b,c;
   for(i=1;i<=p;++i){
      read(a,b,c);
      addline(a,b,c);
   }
   for(i=1;i<=n;++i){
      if(ins[i]==0){
         addline(0,i,0);
      }
   }
   deep_first_search(0);
   bool flag=true;
   for(i=1;i<=n;++i){
      if(num[i]>0){
         printf("%d %d\n",i,num[i]);
         flag=false;
      }
   }
   if(flag)printf("NULL");
   return 0;
}

