#include<bits/stdc++.h>
using namespace std;
class frac{
    public:
        bool negative;
        long long top,buttom;
        frac(long long a,long long b){
            negative=(a<0)^(b<0);
            top=a>0?a:-a;
            buttom=b>0?b:-b;
            maintain();
        }
        frac(long long x){
            negative=(x<0);
            top=x;
            buttom=1;
            maintain();
        }
        frac(){};
        void maintain(){
            if(top==0){
                buttom=1;
                negative=false;
            }
            negative^=(top<0);
            negative^=(buttom<0);
            top=top>0?top:-top;
            buttom=buttom>0?buttom:-buttom;
            long long u=__gcd(buttom,top);
            buttom/=u;
            top/=u;
        }
        friend frac operator*(const frac&a,const frac&b){
            frac ans(a.top*b.top,a.buttom*b.buttom);
            ans.negative=a.negative^b.negative;
            ans.maintain();
            return ans;
        }
        friend frac operator/(const frac&a,const frac&b){
            frac ans(a.top*b.buttom,a.buttom*b.top);
            ans.negative=a.negative^b.negative;
            ans.maintain();
            return ans;
        }
        friend frac operator+(const frac&a,const frac&b){
            pair<long long,long long>ua,ub;
            ua={a.top,a.buttom};
            ub={b.top,b.buttom};
            if(a.negative)ua.first*=-1;
            if(b.negative)ub.first*=-1;
            frac ans(ua.second/__gcd(ua.second,ub.second)*ub.first+ub.second/__gcd(ua.second,ub.second)*ua.first,ub.second/__gcd(ua.second,ub.second)*ua.second);
            ans.maintain();
            return ans;
        }
        friend frac operator-(const frac&a,const frac&b){
            pair<long long,long long>ua,ub;
            ua={a.top,a.buttom};
            ub={b.top,b.buttom};
            if(a.negative)ua.first*=-1;
            if(!b.negative)ub.first*=-1;
            frac ans(ua.second/__gcd(ua.second,ub.second)*ub.first+ub.second/__gcd(ua.second,ub.second)*ua.first,ub.second/__gcd(ua.second,ub.second)*ua.second);
            ans.maintain();
            return ans;
        }
        friend void operator *=(frac&a,const frac&b){
            a=a*b;
        }
        friend void operator +=(frac&a,const frac&b){
            a=a+b;
        }
        friend void operator -=(frac&a,const frac&b){
            a=a-b;
        }
        friend void operator /=(frac&a,const frac&b){
            a=a/b;
        }
        friend bool operator <(const frac&a,const frac&b){
            if(a.negative!=b.negative)return a.negative;
        }
};