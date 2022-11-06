#include<bits/stdc++.h>
using namespace std;
class BigInt{
    public:
    vector<int>data;
    BigInt(signed int x){
        data.clear();
        do{
            data.push_back(x%10);
            x/=10;
        }while(x);
    }
    void operator*=(signed int x){
        for(int i=0;i<(int)data.size();++i)data[i]*=x;
        for(int i=0;i<(int)data.size();++i){
            if(i==(int)data.size()-1){
                if(data[i]>9){
                    data.push_back(data[i]/10);
                    data[i]%=10;
                }
                else break;
            }
            data[i+1]+=data[i]/10;
            data[i]%=10;
        }
    }
    void print(){
        int nw=data.size()-1;
        while(nw!=0&&data[nw]==0)--nw;
        while(nw>=0)putchar(48+data[nw--]);
    }
};
int num[5005];
bool pd[5005];
int mim[5005];
int main(){
    int a,b;
    cin>>a>>b;
    if(b>a-b)b=a-b;
    for(int i=2;i<=a;++i){
        for(int j=2;j<=a/i;++j){
            if(pd[j])continue;
            mim[i*j]=j;
            pd[i*j]=true;
            if(i%j==0)break;
        }
    }
    for(int i=1;i<=b;++i)num[i]-=1,num[a-i+1]+=1;
    for(int i=a;i>=2;--i){
        if(!pd[i])continue;
        num[mim[i]]+=num[i];
        num[i/mim[i]]+=num[i];
        num[i]=0;
    }
    BigInt x=1;
    for(int i=2;i<=a;++i){
        if(num[i]>0){
            while(num[i]--){
                x*=i;
            }
        }
    }
    x.print();
}

