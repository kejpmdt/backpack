#include <cstdio>
#include <algorithm>
using namespace std;
int a[105];
int main()
{
    int t;
    int n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        printf("%d\n", n);
        for (int i = 1; i <= n; ++i)
        {
            a[i] = i;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                printf("%d ", a[j]);
            }
            printf("\n");
            swap(a[i], a[i + 1]);
        }
    }
}