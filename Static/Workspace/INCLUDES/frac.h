#include "incs.h"
#ifndef _FRAC_H
#define _FRAC_H
class frac{
    public:
        bool negative;
        BigInt top,buttom;
        friend ostream& operator<<(ostream&out,frac&x){
            x.maintain();
            if(x.negative)out<<'\55';
            out<<x.top;
            if(x.buttom==BigInt(1))return out;
            out<<'\57'<<x.buttom;
            return out;
        }

        frac(BigInt a,BigInt b){
            negative=(a.negative())^(b.negative());
            top=abs(a);
            buttom=abs(b);
            maintain();
        }
        frac(BigInt x){
            negative=x.negative();
            top=x;
            buttom=1;
            maintain();
        }
        frac(signed long long x){
            negative=x<0;
            top=x;
            buttom=1;
            maintain();
        }
        frac(){};
        void maintain(){
            if(!top){
                buttom=1;
                negative=false;
            }
            negative^=top.negative();
            negative^=buttom.negative();
            top=abs(top);
            buttom=abs(buttom);
            BigInt u=gcd(buttom,top);
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
            pair<BigInt,BigInt>ua,ub;
            ua={a.top,a.buttom};
            ub={b.top,b.buttom};
            if(a.negative)ua.first*=-1;
            if(b.negative)ub.first*=-1;
            frac ans(ua.second/gcd(ua.second,ub.second)*ub.first+ub.second/gcd(ua.second,ub.second)*ua.first,ub.second/gcd(ua.second,ub.second)*ua.second);
            ans.maintain();
            return ans;
        }
        friend frac operator-(const frac&a,const frac&b){
            pair<BigInt,BigInt>ua,ub;
            ua={a.top,a.buttom};
            ub={b.top,b.buttom};
            if(a.negative)ua.first*=-1;
            if(!b.negative)ub.first*=-1;
            frac ans(ua.second/gcd(ua.second,ub.second)*ub.first+ub.second/gcd(ua.second,ub.second)*ua.first,ub.second/gcd(ua.second,ub.second)*ua.second);
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
        bool operator <(const frac&b)const{
            if(negative!=b.negative)return negative;
            return top*b.buttom<buttom*b.top;
        }
        bool operator >(const frac&b)const{
            if(negative!=b.negative)return !negative;
            return top*b.buttom>buttom*b.top;
        }
};
#endif