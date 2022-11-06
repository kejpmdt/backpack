#include<cstdio>
using namespace std;
int k[305],s[305];
int fst[305],nt[305];
int f[305][305];
void dps(int nw){
   for(int i=fst[nw];i;i=nt[i])dps(i);
   for(int i=