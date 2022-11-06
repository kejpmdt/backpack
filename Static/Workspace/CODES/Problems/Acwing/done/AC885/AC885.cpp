#include <bits/stdc++.h>
using namespace std;
int C[2005][2005];
const int MOD= 1000000007;
int main() {
    int n;
    cin >> n;
    for (int i= 0; i <= 2000; ++i) {
        C[i][0]= 1;
        for (int j= 1; j <= i; ++j) {
            C[i][j]= (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << C[a][b] << endl;
    }
    return 0;
}
