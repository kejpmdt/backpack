#include <bits/stdc++.h>
using namespace std;
long long n, m;
template<class T>
class squad {
private:
    T** data;
public:
    int length, width;
    squad(int l, int w) : length(l), width(w) {
        data= new T*[length];
        for (int i= 0; i < length; ++i) data[i]= new T[width];
            for (int i= 0; i < length; ++i)
                for (int j= 0; j < width; ++j) data[i][j]=0;
    }
    T* operator[](const int x) {
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
squad<long long> qpow(squad<long long> a, long long n) {
    squad<long long> ans(a.length,a.width);
    ans[0][0]=ans[1][1]=ans[2][2]=1;
    while (n) {
        if (n & 1) ans*= a;
        a*= a, n>>= 1;
    }
    return ans;
}
int main() {
    cin >> n >> m;
    squad<long long> a(1, 3), b(3, 3);
    a[0][1]=1;
    a[0][2]=0;
    b[0][1]=b[1][0]=b[1][1]=b[1][2]=b[2][2]=1;
    squad<long long> u= qpow(b, n );
    a= a * u;
    cout << a[0][2];
}
