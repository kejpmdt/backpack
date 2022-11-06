#include <bits/stdc++.h>
using namespace std;
template<typename T>
T phi(T x) {
    T res= x;
    for (T i= 2; i <= x / i; ++i)
        if (x % i == 0) {
            while (x % i == 0) x/= i;
            res= res / i * (i - 1);
        }
    if (x > 1) res= res / x * (x - 1);
    return res;
}
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
template<typename T>void read(T&ans){
    ans=0;char us=getchar();bool f=false;
    while(us!=EOF&&(us<48||us>57)){f|=(us==45);us=getchar();}
    while(us>47&&us<58){ans=(ans<<1)+(ans<<3)+(us^48);us=getchar();}
    ans=f?-ans:ans;
}
int main() {
    __int128_t L;
    int t= 0;
    while (1) {
        read(L);
        if (L == 0) return 0;
        ++t;
        cout << "Case " << t << ": ";
        if (L == 8) {
            cout << 1 << endl;
            continue;
        }
        __int128_t d= __gcd(L, (__int128_t) 8);
        __int128_t c= 9 * L / d;
        if (__gcd((__int128_t)10, c) != 1) {
            cout << 0 << endl;
        } else {
            long long x= phi(c);
            long long mi= x;
            for (long long i= 1; i <= x / i; ++i) {
                if (x % i == 0) {
                    if (qpow<__int128_t>(10, i, c) == 1) {
                        mi= min(mi, i);
                    }
                    if (qpow<__int128_t>(10, x / i, c) == 1) {
                        mi= min(mi, x / i);
                    }
                }
            }
            cout << mi << endl;
        }
    }
}