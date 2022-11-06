#include <bits/stdc++.h>
#define lowbit(x) (x & -(x))
using namespace std;
int n, m;
int inp[1000006];
struct node
{
    const int l;
    mutable int r, x;
    node(int L, int R, int X) : l(L), r(R), x(X) {}
    bool operator<(const node &oth) const { return l < oth.l; }
};
set<node> odt;
set<node>::iterator split(int x)
{
    if (x > n)
        return odt.end();
    set<node>::iterator u = --odt.upper_bound({x, 0, 0});
    if (u->l == x)
        return u;
    int r = u->r;
    u->r = x - 1;
    return odt.insert({x, r, u->x}).first;
}
void assign(int l, int r, int x)
{
    set<node>::iterator R = split(r + 1), L = split(l);
    odt.erase(L, R);
    odt.insert({l, r, x});
}
int ask(int l, int r)
{
    set<node>::iterator R = split(r + 1), L = split(l);
    int ans = 0;
    for (set<node>::iterator i = L; i != R; ++i)
        ans |= (1 << i->x);
    return ans >> 1;
}
void build(int l, int r)
{
    set<node>::iterator u = odt.insert({l, l, inp[l]}).first;
    for (int i = l + 1; i <= r; ++i)
    {
        if (inp[i] == inp[i - 1])
            ++u->r;
        else
            u = odt.insert({i, i, inp[i]}).first;
    }
}
int q;
bool pd[1024][100005];
int u[2000006];
int lg2[1024];
struct ask
{
    int opt, l, r, x;
} asks[1000005];
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    register int i, j, k,r;
    for (i = 1; i <= n; ++i)
        scanf("%d", &inp[i]), u[i] = inp[i];
    for (i = 1; i <= q; ++i)
        scanf("%d%d%d%d", &asks[i].opt, &asks[i].l, &asks[i].r, &asks[i].x);
    k = n;
    for (i = 1; i <= q; ++i)
        if (asks[i].opt == 1)
            u[++k] = asks[i].x;
    sort(u + 1, u + k + 1);
    int len = unique(u + 1, u + k + 1) - u;
    lg2[0] = 0;
    for (i = 1; i < 1024; ++i)
        lg2[i] = lg2[i >> 1] + 1;
    for (i = 0; i < 1024; ++i)
        pd[i][0] = true;
    for (i = 1; i < 1 << (len - 1); ++i)
    {
        k=i-lowbit(i);
        r=lg2[lowbit(i)];
        for (j = 0; j <= m; ++j)
        {
            pd[i][j] = pd[k][j];
        }
        for (j = 0; j + u[r] <= m; ++j)
        {
            pd[i][j + u[r]] |= pd[i][j];
        }
    }

    for (i = 1; i <= n; ++i)
        inp[i] = lower_bound(u + 1, u + len, inp[i]) - u;
    for (i = 1; i <= q; ++i)
        if (asks[i].opt == 1)
            asks[i].x = lower_bound(u + 1, u + len, asks[i].x) - u;
    build(1, n);
    for (i = 1; i <= q; ++i)
    {
        if (asks[i].opt == 1)
        {
            assign(asks[i].l, asks[i].r, asks[i].x);
        }
        else
        {
            j = ask(asks[i].l, asks[i].r);
            if (pd[j][asks[i].x])
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}