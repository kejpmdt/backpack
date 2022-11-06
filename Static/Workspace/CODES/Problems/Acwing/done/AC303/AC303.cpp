#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 100010, M = 100010, P = 110;
int n, m, p;
LL d[N], t[N], a[N], s[N];
LL f[P][M];
int q[M];
LL gety(int k, int j)
{
    return f[j - 1][k] + s[k];
}
int main()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 2; i <= n; ++i)
    {
        scanf("%lld", &d[i]);
        d[i] += d[i - 1];
    }
    for (int i = 1; i <= m; ++i)
    {
        int h;
        scanf("%d%lld", &h, &t[i]);
        a[i] = t[i] - d[h];
    }
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; ++i)
    {
        s[i] = s[i - 1] + a[i];
    }
    memset(f, 0x3f, sizeof f);
    for (int i = 0; i <= p; ++i)
    {
        f[i][0] = 0;
    }
    for (int j = 1; j <= p; ++j)
    {
        int hh = 0, tt = 0;
        q[0] = 0;
        for (int i = 1; i <= m; ++i)
        {
            while (hh < tt && (gety(q[hh + 1], j) - gety(q[hh], j)) <= a[i] * (q[hh + 1] - q[hh]))
            {
                hh++;
            }
            int k = q[hh];
            f[j][i] = f[j - 1][k] - a[i] * k + s[k] + a[i] * i - s[i];
            while (hh < tt && (gety(q[tt], j) - gety(q[tt - 1], j)) * (i - q[tt]) >= (gety(i, j) - gety(q[tt], j)) * (q[tt] - q[tt - 1]))
            {
                --tt;
            }
            q[++tt] = i;
        }
    }
    printf("%lld", f[p][m]);
    return 0;
}