#include "incs.h"
#ifndef _BIGINT_H
#define _BIGINT_H
using namespace std;
class BigInt{
    private:
        void maintain(void){overflow();checksize();if(!*this)Negative=false;}
        void checksize(void){while(data.size()>1&&data.back()==0)data.pop_back();}
        void overflow(void){for(std::size_t i=0;i<data.size();++i)if(data[i]>9||data[i]<0){if(i==data.size()-1)data.push_back(data[i]/10);else data[i+1]+=floor(data[i]/10.0);data[i]=(data[i]%10+10)%10;}}
        deque<signed char>data;
        bool Negative;
    public:
        bool negative(void)const{return Negative;}
        BigInt(const string s){
            data.clear();
            string x=s;
            for(std::size_t i=0;i<x.size();++i)if(s[i]!='\55'&&(s[i]<'\60'||'\71'<s[i]))x.erase(i,1);
            Negative=false;
            if(x[0]=='\55')Negative=true,x.erase(0,1);
            if(x=="")data.push_back(0);
            for(std::size_t i=0;i<x.size();++i)data.push_front(x[i]-48);
            checksize();
        }
        BigInt(signed long long x){
            data.clear();
            if(x<0)x*=-1,Negative=true;else Negative=false;
            do data.push_back(x%10),x/=10;while(x);
        }
        BigInt(void){Negative=false;data.clear();}
        friend ostream&operator<<(ostream&out,BigInt&x){
            if(x.Negative)out<<'\55';
            for(int i=(int)x.data.size()-1;i>=0;--i)
            out<<(char)(x.data[i]+'\60');
            return out;
        }
        friend BigInt abs(BigInt x){return x.negative()?-x:x;}
        friend BigInt operator -(BigInt x){BigInt ans=x;ans.Negative^=1;return ans;}
        auto size(void)const{return data.size();}
        signed char operator[](int x)const{return data[x];}
        friend BigInt operator *(BigInt a,BigInt b){
            BigInt *ans=new BigInt(0);
            (*ans).Negative=(a.negative()!=b.negative());
            for(std::size_t i=1;i<a.size()+b.size();++i)(*ans).data.push_back(0);
            for(std::size_t i=0;i<a.size();++i){
                (*ans).overflow();
                for(std::size_t j=0;j<b.size();++j)(*ans).data[i+j]+=a[i]*b[j];
            }
            (*ans).maintain();
            return (*ans);
        }
        friend BigInt operator +(BigInt a,BigInt b){
            BigInt *ans=new BigInt(0);
            if(a.negative()==b.negative()){
                (*ans).Negative=a.negative();
                for(std::size_t i=1;i<a.size()||i<b.size();++i)(*ans).data.push_back(0);
                for(std::size_t i=0;i<a.size();++i)(*ans).data[i]+=a[i];
                for(std::size_t i=0;i<b.size();++i)(*ans).data[i]+=b[i];
            }
            else{
                if(abs(a)<abs(b)){
                    (*ans).Negative=b.negative();
                    for(std::size_t i=1;i<a.size()||i<b.size();++i)(*ans).data.push_back(0);
                    for(std::size_t i=0;i<b.size();++i)(*ans).data[i]+=b[i];
                    for(std::size_t i=0;i<a.size();++i)(*ans).data[i]-=a[i];
                }
                else{
                    (*ans).Negative=a.negative();
                    for(std::size_t i=1;i<a.size()||i<b.size();++i)(*ans).data.push_back(0);
                    for(std::size_t i=0;i<b.size();++i)(*ans).data[i]-=b[i];
                    for(std::size_t i=0;i<a.size();++i)(*ans).data[i]+=a[i];
                }
            }
            (*ans).maintain();
            return (*ans);
        }
        friend BigInt operator /(BigInt a,BigInt b){
            BigInt *ans=new BigInt(0);
            BigInt u;
            BigInt rest=a;
            while(rest>=b){
                u=1;
                while(BigInt(2)*u*b<rest)u*=2;
                (*ans)+=u;
                rest-=u*b;
            }
            return (*ans);
        }
        friend BigInt operator %(BigInt a,BigInt b){
            BigInt u;
            BigInt*rest=new BigInt(a);
            while((*rest)>=b){
                u=1;
                while(BigInt(2)*u*b<(*rest))u*=2;
                (*rest)-=u*b;
            }
            return (*rest);
        }
        bool operator <(BigInt oth)const{
            if(Negative!=oth.negative())return Negative;
            if(data.size()!=oth.size())return (data.size()<oth.size())!=Negative;
            for(int i=(int)data.size()-1;i>=0;--i)if(data[i]!=oth[i])return (data[i]<oth[i])!=Negative;
            return false;
        }
        bool operator==(BigInt oth)const{
            if(Negative!=oth.negative())return false;
            if(data.size()!=oth.size())return false;
            for(std::size_t i=0;i<data.size();++i)if(data[i]!=oth[i])return false;
            return true;
        }
        friend BigInt operator <<(BigInt a,int b){return a*BigInt(1<<b);}
        friend BigInt operator >>(BigInt a,int b){return a/BigInt(1<<b);}
        friend BigInt operator -(BigInt a,BigInt b){return a+(-b);}
        bool operator >(BigInt oth)const{return oth<*this;}
        bool operator <=(BigInt oth)const{return !(oth<*this);}
        bool operator >=(BigInt oth)const{return !(*this<oth);}
        bool operator!=(BigInt oth)const{return !(*this==oth);}
        friend BigInt operator +=(BigInt&a,BigInt b){return a=a+b;}
        friend BigInt operator -=(BigInt&a,BigInt b){return a=a-b;}
        friend BigInt operator *=(BigInt&a,BigInt b){return a=a*b;}
        friend BigInt operator /=(BigInt&a,BigInt b){return a=a/b;}
        friend BigInt operator %=(BigInt&a,BigInt b){return a=a%b;}
        friend BigInt operator <<=(BigInt&a,int b){return a=a<<b;}
        friend BigInt operator >>=(BigInt&a,int b){return a=a>>b;}
        friend BigInt operator ++(BigInt&x){return x+=BigInt(1);}
        friend BigInt operator --(BigInt&x){return x-=BigInt(1);}
        operator bool()const{return(data.size()==1&&data[0]==0);}
};
#endif