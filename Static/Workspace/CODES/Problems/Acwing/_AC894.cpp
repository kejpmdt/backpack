#include <bits/stdc++.h>
using namespace std;
int ssg[105];
int sg(int x) {
    if (ssg[x] != -1) return ssg[x];
    unordered_set<int> ss;
    for (int i= 0; i < x; ++i)for (int j= 0; j < x; ++j)ss.insert(sg(i) ^ sg(j));
    for (int i= 0;; ++i)if (!ss.count(i)) return ssg[x]= i;
}
int main() {
    int n;
    cin >> n;
    memset(ssg, 0xff, sizeof ssg);
    int u= 0;
    while (n--) {
        int x;
        cin >> x, u^= sg(x);
    }
    cout << (u ? "Yes" : "No");
}
