#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, x, y, z, cnt, a[N], f[N], fa[N], dep[N], num, ans[N];
struct edge
{
    int x, y, z;
} e[N << 1];
vector<int> v[N];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void dfs(int x)
{
    for (int i : v[x])
    {
        int y = e[i].y;
        if (y != e[fa[x]].x)
            fa[y] = i, dep[y] = dep[x] + 1, dfs(y);
    }
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].z);
        e[i + m] = e[i], swap(e[i + m].x, e[i + m].y);
        if (e[i].z)
            v[e[i].x].push_back(i), v[e[i].y].push_back(i + m);
    }
    for (int i = 1; i <= n; i++)
        f[i] = i;
    dfs(1);
    for (int i = 1; i <= m; i++)
        if (!ans[i])
        {
            if (!e[i].z && (x = find(e[i].x)) ^ (y = find(e[i].y)))
            {
                cnt = 0;
                while (x ^ y)
                {
                    if (dep[x] < dep[y])
                        swap(x, y);
                    a[++cnt] = fa[x] - (fa[x] > m ? m : 0), x = find(e[fa[x]].x);
                }
                sort(a + 1, a + 1 + cnt);
                for (int i = 1; i <= cnt; i++)
                    if (!ans[a[i]])
                        ans[a[i]] = ++num, f[e[a[i]].x] = f[e[a[i]].y] = find(x);
            }
            ans[i] = ++num;
        }
    for (int i = 1; i <= m; i++)
        printf("%d ", ans[i]);
    return 0;
}
