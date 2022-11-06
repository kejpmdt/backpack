#include <bits/stdc++.h>
using namespace std;
char ins[11][20] = {"T1_0.in", "T1_1.in", "T1_2.in", "T1_3.in", "T1_4.in", "T1_5.in", "T1_6.in", "T1_7.in", "T1_8.in", "T1_9.in", "T1_10.in"};
char outs[11][20] = {"T1_0.ans", "T1_1.ans", "T1_2.ans", "T1_3.ans", "T1_4.ans", "T1_5.ans", "T1_6.ans", "T1_7.ans", "T1_8.ans", "T1_9.ans", "T1_10.ans"};
int maxns[11]={0,5,5,20,20,100,100,200,200,1000000,1000000};
int main()
{
    for (int t = 1; t <= 10; ++t)
    {
        freopen("seed.txt", "r", stdin);
        int n;
        cin >> n;
        srand(n);
        fclose(stdin);
        freopen("seed.txt", "w", stdout);
        cout << rand();
        freopen(ins[t], "w", stdout);
        n = maxns[t];
        printf("%d\n", n);
        for (int i = 1; i <= n; ++i)
        {
            printf("%d ", rand() % 10 + 1);
        }
    }
    return 0;
}
