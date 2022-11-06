#include <bits/stdc++.h>
using namespace std;
template<typename A, typename B>
A qpow(A a, B n) {
    A ans= 1;
    while (n) {
        if (n & 1) ans*= a;
        a*= a, n>>= 1;
    }
    return ans;
}
template<typename A, typename B, typename C>
C qpow(A a, B n, C p) {
    C ans= 1;
    a%= p;
    while (n) {
        if (n & 1) ans= (ans * a) % p;
        a= a * a % p, n>>= 1;
    }
    return ans % p;
}
long long jc[100005];
long long jcny[100005];
const long long mod= 1000000007;
int main() {
    int n;
    cin >> n;
    jc[0]= 1;
    for (int i= 1; i <= 100000; ++i) jc[i]= jc[i - 1] * i % mod;
    jcny[100000]= qpow(jc[100000], mod - 2, mod);
    for (int i= 99999; i >= 0; --i) jcny[i]= jcny[i + 1] * (i + 1) % mod;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << jc[a] * jcny[b] % mod * jcny[a - b] % mod << endl;
    }
    return 0;
}