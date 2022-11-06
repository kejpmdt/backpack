#include <iostream>
#include <cstdio>
using namespace std;
template <typename T>
void read(T &ans)
{
    ans = 0;
    char us = getchar();
    bool f = false;
    while (us < 48 || us > 57)
    {
        f |= (us == 45);
        us = getchar();
    }
    while (us > 47 && us < 58)
    {
        ans = (ans << 1) + (ans << 3) + (us ^ 48);
        us = getchar();
    }
    ans *= f ? -1 : 1;
    return;
}
template <typename T, typename... O>
void read(T &x, O &...oth)
{
    read(x);
    read(oth...);
}
int son[100005][2];
int length[100005];
bool pd[100005];
int ans;
void dfs1(int nw)
{
    if (son[nw][0] == -1 && son[nw][1] == -1)
    {
        pd[nw] = false;
        length[nw] = 1;
    }
    else
    {
        if (son[nw][0] == -1)
        {
            pd[nw] = true;
            dfs1(son[nw][1]);
            length[nw] = length[son[nw][1]] + 1;
            if (length[son[nw][1]] > 1)
            {
                printf("-1");
                exit(0);
            }
            ++ans;
        }
        else if (son[nw][1] == -1)
        {
            pd[nw] = true;
            dfs1(son[nw][0]);
            length[nw] = length[son[nw][0]] + 1;
            if (length[son[nw][0]] > 1)
            {
                printf("-1");
                exit(0);
            }
        }
        else
        {
            dfs1(son[nw][0]);
            dfs1(son[nw][1]);
            if (pd[son[nw][0]] && pd[son[nw][1]])
            {
                printf("-1");
                exit(0);
            }
            if (length[son[nw][0]] == length[son[nw][1]])
            {
                length[nw] = length[son[nw][0]] + 1;
                if (pd[son[nw][0]])
                {
                    ++ans;
                }
            }
            else
            {
                if (length[son[nw][0]] < length[son[nw][1]])
                {
                    if (pd[son[nw][0]])
                    {
                        printf("-1");
                        exit(0);
                    }
                    ++ans;
                    pd[nw] = true;
                    length[nw] = length[son[nw][1]] + 1;
                }
                else
                {
                    if (pd[son[nw][1]])
                    {
                        printf("-1");
                        exit(0);
                    }
                    pd[nw] = true;
                    length[nw] = length[son[nw][0]] + 1;
                }
            }
        }
    }
}
int fa[100005];
int main()
{
    int n;
    read(n);
    for (int i = 1; i <= n; ++i)
    {
        read(son[i][0], son[i][1]);
        fa[son[i][0]] = fa[son[i][1]] = i;
    }
    int u = 1;
    while (fa[u])
    {
        u = fa[u];
    }
    dfs1(u);
    printf("%d", ans);
}
