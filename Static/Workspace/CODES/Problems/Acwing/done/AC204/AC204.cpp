#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL gcd(LL a, LL b, LL& x, LL& y) {
    if (b==0) {
        x= 1, y= 0;
        return a;
    }
    LL d= gcd(b, a % b, y, x);
    y-= a / b * x;
    return d;
}
int main() {
    int n;
    cin >> n;
    LL nwa= 1, nwm= 0;
    LL x, y, d, ua, um;
    while (n--) {
        cin >> ua >> um;
        d= gcd(nwa, ua, x, y);
        if ((um - nwm) % d != 0) {
            cout << -1;
            return 0;
        }
        x*= (um - nwm) / d;
        y= ua / d;
        x= (x % y + y) % y;
        nwm+= nwa * x;
        nwa= abs(ua / d * nwa);
    }
    cout << (nwm % nwa + nwa % nwa);
    return 0;
}
