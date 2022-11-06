#include "incs.h"
#ifndef _POLY_H
#define _POLY_H
class Poly{
    public:
        std::set<mpair<frac,frac>>data;
        Poly(frac x,frac y=0){
            data.insert({y,x});
        }
        Poly(){};
        friend Poly operator +(const Poly&a,const Poly&b){
            Poly res;
            for(auto i:a.data)res.data.insert({i.first,0}).first->second+=i.second;
            for(auto i:b.data)res.data.insert({i.first,0}).first->second+=i.second;
            return res;
        }
        friend Poly operator -(const Poly&a,const Poly&b){
            Poly res;
            for(auto i:a.data)res.data.insert({i.first,0}).first->second+=i.second;
            for(auto i:b.data)res.data.insert({i.first,0}).first->second-=i.second;
            return res;
        }
        friend Poly operator *(const Poly&a,const Poly&b){
            Poly res;
            for(auto i:a.data)for(auto j:b.data)res.data.insert({i.first+j.first,0}).first->second+=i.second*j.second;
            return res;
        }
        friend void operator +=(Poly&a,const Poly&b){
            a=a+b;
        }
        friend void operator -=(Poly&a,const Poly&b){
            a=a-b;
        }
        friend void operator *=(Poly&a,const Poly&b){
            a=a*b;
        }
        friend ostream&operator<<(ostream&out,Poly&x){
            bool f=false;
            for(auto i:x.data){
                if(f)out<<'\53';
                out<<'\50'<<i.second<<"\51\52\170\136\50"<<i.first<<'\51';
                f=true;
            }
            return out;
        }
};
#endif