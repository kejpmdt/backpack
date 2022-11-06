#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
class squad {
public:
    ll** data;
    int length, width;
    squad(int l, int w) : length(l), width(w) {
        data= new ll*[length];
        for (int i= 0; i < length; ++i) data[i]= new ll[width];
            for (int i= 0; i < length; ++i)
                for (int j= 0; j < width; ++j) data[i][j]=0;
    }
    ll* operator[](const int x) {
        return  data[x] ;
    }
    friend squad operator*(squad a, squad b) {
        squad res(a.length, b.width);
        for (int i= 0; i < a.length; ++i) {
            for (int j= 0; j < b.width; ++j) {
                res[i][j]= 0;
                for (int k= 0; k < a.width; ++k) 
                    res[i][j]= (res[i][j] + a[i][k] * b[k][j]) % m;
            }
        }
        return res;
    }
    friend void operator *=(squad&a,const squad&b){
        a=a*b;
    }
};
squad qpow(squad a, ll n) {
    squad ans(a.length,a.width);
    ans[0][0]=ans[1][1]=ans[2][2]=1;
    while (n) {
        if (n & 1) ans*= a;
        a*= a, n>>= 1;
    }
    return ans;
}
int main() {
    cin >> n >> m;
    squad a(1, 4), b(4, 4);
    a[0][2]=a[0][3]=0;
    a[0][1]=b[0][1]=b[1][0]=b[1][1]=b[1][2]=b[2][2]=b[2][3]=b[3][3]=1;
    squad u= qpow(b, n);
    a= a * u;
    ll r=a[0][2]*(n+1);
    a*=b;
    cout <<(r- a[0][3]+m)%m;
}
