#include <cstdio>
using namespace std;
struct node
{
    int data;
    node *lst;
    node *nt;
};
struct list
{
    int size;
    node *fst;
    list *lst;
    list *nt;
    node *last;
} * fst, *lst;
int n;
long long play()
{
    for (int i = 1; i <= n; ++i)
    {
    }
    void init()
    {
        int u;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &u);
            if (lst == nullptr)
            {
                lst = fst = new list;
                fst->size = 1;
                lst->lst = lst->nt = nullptr;
                lst->fst = lst->last = new node;
                lst->fst->lst = lst->fst->nt = nullptr;
                lst->fst->data = u;
            }
            else
            {
                if (lst->size * lst->size > n)
                {
                    lst->nt = new list;
                    lst->nt->lst = lst;
                    lst = lst->nt;
                    lst->nt = nullptr;
                    lst->fst = lst->last = new node;
                    lst->fst->data = u;
                    lst->size = 1;
                    lst->fst->lst = lst->fst->nt = nullptr;
                }
                else
                {
                    lst->last->nt = new node;
                    lst->last->nt->lst = lst->last;
                    lst->last = lst->last->nt;
                    ++lst->size;
                    lst->last->data = u;
                    lst->last->nt = nullptr;
                }
            }
        }
    }
}
int main()
{
    init();
    printf("%lld", play());
}
