#include <cstdio>
using namespace std;
signed int over_signedint_p;
class node {
  public:
    node*      node_public_nodepointer_lc;
    node*      node_public_nodepointer_rc;
    signed int node_public_signedint_l;
    signed int node_public_signedint_r;
    signed int node_public_signedint_addtag;
    signed int node_public_signedint_timestag;
    signed int node_public_signedint_sum;
    void       node_public_voidfunction_build(int, int);
    void       node_public_voidfunction_add(int, int, int);
    void       node_public_voidfunction_times(int, int, int);
    void       node_public_voidfunction_pushdown(void);
    signed int node_public_signedfunction_query(int, int);
} * over_nodepointer_root;
signed int over_signedintarray_inp[100005];
void       node::node_public_voidfunction_build(int l, int r) {
          node_public_signedint_l       = l;
          node_public_signedint_r       = r;
          node_public_signedint_addtag  = 0;
          node_public_signedint_timestag= 1;
          if (l == r) {
              node_public_signedint_sum = over_signedintarray_inp[l];
              node_public_nodepointer_lc= node_public_nodepointer_rc= nullptr;
              return;
    }
          node_public_nodepointer_lc= new node;
          node_public_nodepointer_rc= new node;
          node_public_nodepointer_lc->node_public_voidfunction_build(l, (l + r) >> 1);
          node_public_nodepointer_rc->node_public_voidfunction_build(((l + r) >> 1) + 1, r);
          node_public_signedint_sum= (node_public_nodepointer_lc->node_public_signedint_sum + node_public_nodepointer_rc->node_public_signedint_sum) % over_signedint_p;
          return;
}
void node::node_public_voidfunction_add(int l, int r, int k) {
    if (r < node_public_signedint_l || l > node_public_signedint_r) return;
    if (l <= node_public_signedint_l && r >= node_public_signedint_r) {
        node_public_signedint_sum+= (node_public_signedint_r - node_public_signedint_l + 1) * k;
        node_public_signedint_sum%= over_signedint_p;
        node_public_signedint_addtag+= k;
        node_public_signedint_addtag%= over_signedint_p;
        return;
    }
    node_public_voidfunction_pushdown();
    node_public_nodepointer_lc->node_public_voidfunction_add(l, r, k);
    node_public_nodepointer_rc->node_public_voidfunction_add(l, r, k);
    node_public_signedint_sum= (node_public_nodepointer_lc->node_public_signedint_sum + node_public_nodepointer_rc->node_public_signedint_sum) % over_signedint_p;
    return;
}
void node::node_public_voidfunction_times(int l, int r, int k) {
    if (r < node_public_signedint_l || l > node_public_signedint_r) return;
    if (l <= node_public_signedint_l && r >= node_public_signedint_r) {
        node_public_signedint_sum*= k;
        node_public_signedint_addtag*= k;
        node_public_signedint_timestag*= k;
        node_public_signedint_sum%= over_signedint_p;
        node_public_signedint_addtag%= over_signedint_p;
        node_public_signedint_timestag%= over_signedint_p;
        return;
    }
    node_public_voidfunction_pushdown();
    node_public_nodepointer_lc->node_public_voidfunction_times(l, r, k);
    node_public_nodepointer_rc->node_public_voidfunction_times(l, r, k);
    node_public_signedint_sum= (node_public_nodepointer_lc->node_public_signedint_sum + node_public_nodepointer_rc->node_public_signedint_sum) % over_signedint_p;
    return;
}
void node::node_public_voidfunction_pushdown(void) {
    if (node_public_signedint_l == node_public_signedint_r) return;
    node_public_nodepointer_lc->node_public_signedint_sum*= node_public_signedint_timestag;
    node_public_nodepointer_lc->node_public_signedint_addtag*= node_public_signedint_timestag;
    node_public_nodepointer_lc->node_public_signedint_timestag*= node_public_signedint_timestag;
    node_public_nodepointer_lc->node_public_signedint_sum%= over_signedint_p;
    node_public_nodepointer_lc->node_public_signedint_addtag%= over_signedint_p;
    node_public_nodepointer_lc->node_public_signedint_timestag%= over_signedint_p;
    node_public_nodepointer_lc->node_public_signedint_sum+= node_public_signedint_addtag * (node_public_nodepointer_lc->node_public_signedint_r - node_public_nodepointer_lc->node_public_signedint_l + 1);
    node_public_nodepointer_lc->node_public_signedint_addtag+= node_public_signedint_addtag;
    node_public_nodepointer_lc->node_public_signedint_sum%= over_signedint_p;
    node_public_nodepointer_lc->node_public_signedint_addtag%= over_signedint_p;

    node_public_nodepointer_rc->node_public_signedint_sum*= node_public_signedint_timestag;
    node_public_nodepointer_rc->node_public_signedint_addtag*= node_public_signedint_timestag;
    node_public_nodepointer_rc->node_public_signedint_timestag*= node_public_signedint_timestag;
    node_public_nodepointer_rc->node_public_signedint_sum%= over_signedint_p;
    node_public_nodepointer_rc->node_public_signedint_addtag%= over_signedint_p;
    node_public_nodepointer_rc->node_public_signedint_timestag%= over_signedint_p;
    node_public_nodepointer_rc->node_public_signedint_sum+= node_public_signedint_addtag * (node_public_nodepointer_rc->node_public_signedint_r - node_public_nodepointer_rc->node_public_signedint_l + 1);
    node_public_nodepointer_rc->node_public_signedint_addtag+= node_public_signedint_addtag;
    node_public_nodepointer_rc->node_public_signedint_sum%= over_signedint_p;
    node_public_nodepointer_rc->node_public_signedint_addtag%= over_signedint_p;

    node_public_signedint_addtag  = 0;
    node_public_signedint_timestag= 1;
    return;
}
signed node::node_public_signedfunction_query(int l, int r) {
    if (r < node_public_signedint_l || l > node_public_signedint_r) return 0;
    if (l <= node_public_signedint_l && r >= node_public_signedint_r) return node_public_signedint_sum;
    return (node_public_nodepointer_lc->node_public_signedfunction_query(l, r) + node_public_nodepointer_rc->node_public_signedfunction_query(l, r)) % over_signedint_p;
}
signed int main() {
    over_nodepointer_root= new node;
    signed int main_signedint_n;
    signed int main_signedint_m;
    scanf("%d%d%d", &main_signedint_n, &main_signedint_m, &over_signedint_p);
    signed int main_signedint_x;
    signed int main_signedint_y;
    signed int main_signedint_k;
    signed int main_signedint_i;
    signed int main_signedint_opt;
    for (main_signedint_i= 1; main_signedint_i <= main_signedint_n; ++main_signedint_i) scanf("%d", &over_signedintarray_inp[main_signedint_i]);
    over_nodepointer_root->node_public_voidfunction_build(1, main_signedint_n);
    for (main_signedint_i= 1; main_signedint_i <= main_signedint_m; ++main_signedint_i) {
        scanf("%d%d%d", &main_signedint_opt, &main_signedint_x, &main_signedint_y);
        if (main_signedint_opt == 1) {
            scanf("%d", &main_signedint_k);
            over_nodepointer_root->node_public_voidfunction_times(main_signedint_x, main_signedint_y, main_signedint_k);
        }
        if (main_signedint_opt == 2) {
            scanf("%d", &main_signedint_k);
            over_nodepointer_root->node_public_voidfunction_add(main_signedint_x, main_signedint_y, main_signedint_k);
        }
        if (main_signedint_opt == 3) {
            printf("%d\n", over_nodepointer_root->node_public_signedfunction_query(main_signedint_x, main_signedint_y) % over_signedint_p);
        }
    }
    return 0;
}
