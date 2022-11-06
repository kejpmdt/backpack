#include <bits/stdc++.h>
using namespace std;
struct line
{
    int a, b;
    int color;
    int ans;
} lines[500005];
int fa[500005];
int getfa(int x)
{
    if (fa[fa[x]] != fa[x])
        fa[x] = getfa(fa[x]);
    return fa[x];
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &lines[i].a, &lines[i].b, &lines[i].color);
    }
    for(int i=1;i<=n;++i){
        fa[i]=i;
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (lines[j].ans != 0)
                continue;
            if (lines[j].color == 1 || getfa(lines[j].a) == getfa(lines[j].b))
            {
                lines[j].ans = i;
                fa[fa[lines[j].a]] = fa[lines[j].b];
                break;
            }
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        printf("%d ", lines[i].ans);
    }
    return 0;
}
