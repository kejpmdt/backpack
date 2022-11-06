#include <cstdio>
#define mx2(a, b) (a > b ? a : b)
using namespace std;
long long f1[100005][2];
long long f2[100005][2];
int fst[100005], nt[200005], to[200005];
int fa[100005];
int getfa(int x)
{
    if (fa[fa[x]] != fa[x])
    {
        fa[x] = getfa(fa[x]);
    }
    return fa[x];
}
void addline(int a, int b)
{
    static int i = 0;
    to[++i] = b, nt[i] = fst[a], fst[a] = i;
    to[++i] = a, nt[i] = fst[b], fst[b] = i;
}
void dps1(int nw, int fa)
{
    if (to[fst[nw]] == fa)
    {
        fst[nw] = nt[fst[nw]];
    }
    int i;
    for (i = fst[nw]; i; i = nt[i])
    {
        if (to[nt[i]] == fa)
        {
            nt[i] = nt[nt[i]];
        }
        dps1(to[i], nw);
        f1[nw][0] += mx2(f1[to[i]][0], f1[to[i]][1]);
        f1[nw][1] += f1[to[i]][0];
    }
}
void dps2(int nw)
{
    int i;
    for (i = fst[nw]; i; i = nt[i])
    {
        dps2(to[i]);
        f2[nw][0] += mx2(f2[to[i]][0], f2[to[i]][1]);
        f2[nw][1] += f2[to[i]][0];
    }
}
int main()
{
    int s, t;
    int n;
    scanf("%d", &n);
    int i;
    for (i = 1; i <= n; ++i)
    {
        scanf("%d", &f1[i][1]);
        f2[i][1] = f1[1][i];
        fa[i] = i;
    }
    int u, v;
    for (i = 1; i <= n; ++i)
    {
        scanf("%d%d", &u, &v);
        ++u, ++v;
        if (getfa(u) != getfa(v))
        {
            addline(u, v);
            fa[fa[u]] = fa[v];
        }
        else
        {
            s = u, t = v;
        }
    }
    double k;
    scanf("%lf", &k);
    dps1(s, s);
    dps2(t);
    long long ans = mx2(f1[s][0], f2[s][0]);
    printf("%.1lf", k * ans);
    return 0;
}
