#include<cstdio>
#include<queue>
struct stable{
   long long z;
   int dis;
   int exp;
   bool operator < (zt other)const{
      return dis+exp>other.dis+other.exp;
   }
   zt(long long x,int b){
      z=x;
      dis=b;
      i