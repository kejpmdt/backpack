#include<bits/stdc++.h>
#include"F:/Static/workspace/INCLUDES/frac.h"
#include"F:/Static/workspace/INCLUDES/mpair.h"
using namespace std;
class Poly{
    public:
        set<mpair<frac,frac>>data;
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
        void print(void){
            bool f=false;
            for(auto i:data){
                if(f)putchar('+');
                putchar('\50');
                i.second.print();
                putchar('\51');
                putchar('\52');
                putchar('\170');
                putchar('\136');
                putchar('\50');
                i.first.print();
                putchar('\51');
                f=true;
            }
        }
};
int main(){
    int n,m;
    cin>>n>>m;
    int u,v;
    Poly a,b;
    for(int i=1;i<=n;++i){
        cin>>u>>v;
        a+=Poly(u,v);
    }
    for(int i=1;i<=m;++i){
        cin>>u>>v;
        b+=Poly(u,v);
    }
    a*=b;
    a.print();
    return 0;
}