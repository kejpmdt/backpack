#include <bits/stdc++.h>
using namespace std;
int nums[1005];
int a[1000005];
int ss;
int sum;
int n;
int ans;
void dfs(int x)
{
    if (x > n)
    {
        int nw = 0;
        for (int i = 1; i <= ss; ++i)
        {
            if (nums[i] * ss > sum)
                ++nw;
        }
        ans = max(ans, nw);
        return;
    }
    sum += a[x];
    nums[++ss] = a[x];
    dfs(x + 1);
    sum -= a[x];
    --ss;
    dfs(x + 1);
}
template<typename T>
void read(T&ans)
{
    ans=0;
    char us=getchar();
    bool f=false;
    while(us<48||us>57){
        f|=(us==45);
        us=getchar();
    }
    while(us>47&&us<58){
        ans=(ans<<1)+(ans<<3)+(us^48);
        us=getchar();
    }
    ans*=f?-1:1;
    return;
}
template<typename T,typename ...O>
void read(T&x,O&...oth)
{
    read(x);
    read(oth...);
}
#define mi2(a,b) (a<b?a:b)
#define mx2(a,b) (a>b?a:b)
template<typename T=signed int>T read(void){T x;read(x);return x;}
char ins[11][20] = {"T1_0.in", "T1_1.in", "T1_2.in", "T1_3.in", "T1_4.in", "T1_5.in", "T1_6.in", "T1_7.in", "T1_8.in", "T1_9.in", "T1_10.in"};
char outs[11][20] = {"T1_0.ans", "T1_1.ans", "T1_2.ans", "T1_3.ans", "T1_4.ans", "T1_5.ans", "T1_6.ans", "T1_7.ans", "T1_8.ans", "T1_9.ans", "T1_10.ans"};
int main()
{
    for (int t = 1; t <= 10; ++t)
    {
        freopen(ins[t], "r", stdin);
        freopen(outs[t], "w", stdout);
        n = read();
        if (n <= 1)
        {
            printf("0");
            return 0;
        }
        long long sum = 0;
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            a[i] = read();
        sort(a + 1, a + n + 1);
        int nw = 1;
        for (int i = 1; i <= n; ++i)
        {
            sum += a[i];
            while (a[nw] * i <= sum && nw < i)
                ++nw;
            ans = mx2(ans, i - nw + 1);
        }
        printf("%d\n", ans);
    }
}
