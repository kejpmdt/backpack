#include<cstdio>
#include<iostream>
#define MOD 998244353
#define MAXN 100005
using namespace std;
struct d{
   int t,a;
}ds[MAXN];
int fst[MAXN];
int nt[MAXN];
int q[MAXN];
int aft[MAXN];
void dfs(int nw){
   if(aft[nw])return;
   for(int i=fst[nw];i;i=nt[i]){
      
int main(){
   