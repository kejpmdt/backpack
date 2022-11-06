#include <bits/stdc++.h>
using namespace std;
#define MAXN 45
bool line[MAXN][MAXN];
int n, m;
bool u[MAXN];
bool ans[MAXN];
int num;
void dfs(int nw, int cnt) {
    if (cnt > (n >> 1) ||   n- cnt <= num) return;
    if (nw > n) {
        memcpy(ans, u, sizeof u);
        num= n - cnt;
        return;
    }
    for (int i= 1; i < nw; ++i)
        if (u[i] && !line[nw][i]) goto ed;
    u[nw]= true;
    dfs(nw + 1, cnt);
    u[nw]= false;
ed:
    dfs(nw + 1, cnt + 1);
}
int main() {
    scanf("%d%d", &n, &m);
    int a, b;
    for (int i= 1; i <= m; ++i) {
        scanf("%d%d", &a, &b);
        line[a][b]= line[b][a]= true;
    }
    dfs(1, 0);
    cout << num << '\12';
    for (int i= 1; i <= n; ++i)
        if (ans[i]) cout << i << ' ';
    return 0;
}