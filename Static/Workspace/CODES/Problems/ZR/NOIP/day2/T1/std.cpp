#include<bits/stdc++.h>
#define FILE() freopen("inp.txt", "r", stdin), freopen("oup.txt", "w", stdout)
using namespace std;

namespace IO {
	char buf[1<<23], *p1=buf, *p2=buf, obuf[1<<23], *O=obuf;
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
	template<typename T>
	inline int Read(T &n) {
		T k=0, f=1; char c=getchar();
		while (c<'0' || c>'9') { if (c == '-') f=-1; c=getchar(); }
		while (c>='0' && c<='9') { k=(k<<3)+(k<<1)+(c-'0'); c=getchar(); }
		n = k*f; return 0;
	}
	template<typename T, typename ...Y>
	inline int Read(T &x, Y&... y) { return Read(x) | Read(y...); }
	template<typename T>
	inline void Write(T x) {
		if (x < 0) { putchar('-'); x=-x; }
		if (x > 9) Write(x/10);
		putchar(x%10+'0');
	}
	template<typename T>
	inline void Write(T x, char c) { Write(x); putchar(c); }
}

#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define ROF(i, a, b) for(int i=(a); i>=(b); i--)
const int N = 1e6 + 10, M = 1e5 + 10;
typedef set<int>::iterator Iter;
int n, m, q;
int rev[M], cnt;
int val[N], vec[N];
bool chk[M];
struct Query {
	int opt, l, r, x;
	inline void Input() {
		IO::Read(opt, l, r, x);
	}
} Q[N];
set<int> num[M];
int dat[N<<2], tag[N<<2];

#define lson (p<<1)
#define rson (p<<1|1)
inline void PushUp(int p) {
	dat[p] = dat[lson] | dat[rson];
}
inline void PushDown(int p) {
	if (!tag[p]) return;
	dat[lson] = 1 << (tag[p]-1);
	dat[rson] = 1 << (tag[p]-1);
	tag[lson] = tag[p];
	tag[rson] = tag[p];
	tag[p] = 0;
}
inline void Build(int p, int l, int r) {
	if (l == r) {
		dat[p] = 1 << (rev[val[l]]-1);
		return;
	}
	int mid = (l+r) >> 1;
	Build(lson, l, mid);
	Build(rson, mid+1, r);
	PushUp(p);
}
inline void Update(int p, int l, int r, int L, int R, int x) {
	if (L <= l && r <= R) {
		dat[p] = 1 << (rev[x] - 1);
		tag[p] = rev[x];
		return;
	}
	PushDown(p);
	int mid = (l+r) >> 1;
	if (L <= mid) Update(lson, l, mid, L, R, x);
	if (R > mid) Update(rson, mid+1, r, L, R, x);
	PushUp(p);
}
inline int Query(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) return dat[p];
	PushDown(p);
	int mid = (l+r) >> 1;
	int ret = 0;
	if (L <= mid) ret |= Query(lson, l, mid, L, R);
	if (R > mid) ret |= Query(rson, mid+1, r, L, R);
	return ret;
}

int main() {
	IO::Read(n, m, q);
	FOR (i, 1, n) {
		IO::Read(val[i]);
		if (!rev[val[i]]) {
			rev[val[i]] = ++cnt;
			vec[cnt] = val[i];
		}
	}
	FOR (i, 1, q) {
		Q[i].Input();
		if (Q[i].opt == 1 && !rev[Q[i].x])
			rev[Q[i].x] = ++cnt, vec[cnt] = Q[i].x;
	}
	Build(1, 1, n);
	chk[0] = 1;
	num[0].insert(0);
	FOR (i, 1, m) FOR (j, 1, cnt) {
		if (vec[j] > i) continue;
		chk[i] |= chk[i-vec[j]];
		if (!chk[i-vec[j]]) continue;
		for (Iter it = num[i-vec[j]].begin(); it != num[i-vec[j]].end(); it++) 
			num[i].insert((*it) | (1 << (j-1)));
	}
	FOR (i, 1, q) {
		if (Q[i].opt == 1) {
			Update(1, 1, n, Q[i].l, Q[i].r, Q[i].x);
		} else {
			int flag = 0;
			int res = Query(1, 1, n, Q[i].l, Q[i].r);
			for (Iter it = num[Q[i].x].begin(); it != num[Q[i].x].end(); it++)
				if ((res & (*it)) == (*it)) {
					flag = 1; break;
				}
			if (flag) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}