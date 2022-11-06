#include <bits/stdc++.h>
using namespace std;
template<typename A, typename B, typename C>
C qpow(A a, B n, C p) {
    C ans= 1;
    a%= p;
    while (n) {
        if (n & 1) ans= (ans * a) % p;
        a= (C)a * a % p, n>>= 1;
    }
    return ans % p;
}
long long C(long long a, long long b, long long p) {
    long long ans= 1;
    for (long long i= a - b + 1; i <= a; ++i) ans= ans * i % p;
    for (long long i= 1; i <= b; ++i) ans= ans * qpow(i, p - 2, p) % p;
    return ans % p;
}
long long lucas(long long a, long long b, int p) {
    if (a < p && b < p) return C(a, b, p);
    return C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}
int main() {
    long long a, b, p;
    int n;
    cin >> n;
    while (n--) {
        cin >> a >> b >> p;
        cout << lucas(a, b, p) << endl;
    }
    return 0;
}
