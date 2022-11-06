#include <bits/stdc++.h>
using namespace std;
template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T1, typename T2, typename T3, typename T4= T3, class T0= T1>
T0 exgcd(T1 a, T2 b, T3& x, T4& y= (*new T3)) {
    if (!b) {
        x= 1, y= 0;
        return a;
    }
    T0 d= exgcd(b, a % b, y, x);
    y-= a / b * x;
    return d;
}
int main() {
    int a, b;
    cin >> a >> b;
    int x;
    int d= exgcd(a, b, x);
    cout << (x % (b / d) + (b / d) ) % (b / d) ;
}