#include <bits/stdc++.h>
using namespace std;
const int N= 110;
const double eps= 1e-6;
int n;
double a[N][N];
int guass() {
    int c, r;  // r为行，c为列
    for (c= 0, r= 0; c < n; ++c) {
        int t= r;  // r为开始，t为最大列
        for (int i= r; i < n; ++i)
            if (fabs(a[i][c]) > fabs(a[t][c])) t= i;         //找绝对值最大的那一列
        if (fabs(a[t][c]) < eps) continue;                   //如果全是0
        for (int i= c; i <= n; ++i) swap(a[t][i], a[r][i]);  //换到最上面
        for (int i= n; i >= c; --i) a[r][i]/= a[r][c];       //把系数化去
        for (int i= r + 1; i < n; ++i)
            if (fabs(a[i][c]) > eps)
                for (int j= n; j >= c; --j) a[i][j]-= a[r][j] * a[i][c];  //清掉下面的这一项
        ++r;                                                              //下一行
    }
    if (r < n) {
        for (int i= r; i < n; ++i)
            if (fabs(a[i][n]) > eps) return 2;  //出现0!=0,无解
        return 1;                               // 0==0无穷多解
    }
    for (int i= n - 1; i >= 0; --i)
        for (int j= i + 1; j < n + 1; ++j) a[i][n]-= a[i][j] * a[j][n];  //去掉其他项
    return 0;
}
int main() {
    cin >> n;
    for (int i= 0; i < n; ++i)
        for (int j= 0; j <= n; ++j) cin >> a[i][j];
    int t= guass();
    if (t == 0)
        for (int i= 0; i < n; ++i) printf("%.2lf\12", a[i][n]);
    else if (t == 1)
        printf("Infinite group solutions\12");
    else
        printf("No solution\12");
    return 0;
}
