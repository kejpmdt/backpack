#ifndef _AUTOMATH_H
#define _AUTOMATH_H

#include "incs.h"

#ifndef _CF
#define _CF
template<typename T1,typename T2=signed int>std::map<T1,T2>cf(T1 x){std::map<T1,T2>res;for(T1 i=2;i<=x/i;++i)while(x%i==0)++res[i],x/=i;if(x>1)++res[x];return res;}
#endif

#ifndef _GCD
#define _GCD
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T1,typename T2,typename T3,typename T4=T3,class T0=T1>T0 exgcd(T1 a,T2 b,T3&x,T4&y=*new T3){if(!b){x=1,y=0;return a;}T0 d=exgcd(b,a%b,y,x);y-=a/b*x;return d;}
#endif

#ifndef _POW
#define _POW
template<typename A,typename B>A qpow(A a,B n){A ans=1;while(n){if(n%(B)2)ans*=a;a*=a,n>>=1;}return ans;}
template<typename A,typename B,typename C>C qpow(A a,B n,C p){C ans=1;a%=p;while(n){if(n%(B)2)ans=(ans*a)%p;a=(C)a*a%p,n>>=1;}return ans%p;}
#endif

#ifndef _PHI
#define _PHI
template<typename T>T phi(T x){std::set<T>s;T ans=x;for(T i=(T)2;i<=x/i;++i)while(x%i==0){if(s.insert(i).second)ans=ans*(i-1)/i;x/=i;}if(x>(T)1)if(s.insert(x).second)ans=ans*(x-(T)1)/x;return ans;}
#endif

#endif