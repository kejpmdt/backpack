#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#define MAXN 2025
using namespace std;
short n, m, a, b, c, d;
short mp[MAXN][MAXN];
bool used[MAXN][MAXN][4];
int ts[MAXN][MAXN][4];
struct zt {
	short x, y;
	short cx;
	int t;
	bool operator ()(const zt*a, const zt*b) {
		return a->t < b->t;
	}
	zt(short x1, short y1, short cx1, int t1): x(x1), y(y1), cx(cx1), t(t1) {};
};
template <class T>
class heap {
private:
	signed int heap_signedint_sz;
	void heap_voidfunction_sp(T&a, T&b) {
		T c = a;
		a = b;
		b = c;
	}
public:
	vector<T> heap_templatevector_D;
	heap(void){
		heap_signedint_sz=0;
		heap_templatevector_D.resize(1);
	}
	void heap_voidfunction_init(void) {
		heap_signedint_sz = 0;
		heap_templatevector_D.clear();
		heap_templatevector_D.resize(1);
	}
	T heap_templatefunction_top(void) {
		if (!heap_boolfunction_empty())return heap_templatevector_D[1];
		else {
			heap_templatevector_D.resize(2);
			return heap_templatevector_D[1];
		}
	}
	void heap_voidfunction_pop(void) {
		heap_voidfunction_sp(heap_templatevector_D[heap_signedint_sz], heap_templatevector_D[1]);
		--heap_signedint_sz;
		heap_templatevector_D.pop_back();
		heap_voidfunction_downcheck(1);
	}
	void heap_voidfunction_upcheck(int x) {
		while (x > 1 && heap_templatevector_D[x]<heap_templatevector_D[x >> 1]) {
			heap_voidfunction_sp(heap_templatevector_D[x], heap_templatevector_D[x >> 1]);
			x >>= 1;
		}
		return;
	}
	void heap_voidfunction_downcheck(int x) {
		while (1) {
			if (x << 1 > heap_signedint_sz)return;
			if (x << 1 == heap_signedint_sz) {
				if (heap_templatevector_D[x] < heap_templatevector_D[x << 1])return;
				heap_voidfunction_sp(heap_templatevector_D[x], heap_templatevector_D[x << 1]);
				return;
			}
			if (heap_templatevector_D[x] < heap_templatevector_D[x << 1] && heap_templatevector_D[x] < heap_templatevector_D[(x << 1) | 1])return;
			if (heap_templatevector_D[x << 1] < heap_templatevector_D[(x << 1) | 1]) {
				heap_voidfunction_sp(heap_templatevector_D[x], heap_templatevector_D[x << 1]);
				x <<= 1;
			}
			else {
				heap_voidfunction_sp(heap_templatevector_D[x], heap_templatevector_D[(x << 1) | 1]);
				x <<= 1;
				x |= 1;
			}
		}
	}
	void heap_voidfunction_push(T x) {
		++heap_signedint_sz;
		heap_templatevector_D.push_back(x);
		heap_voidfunction_upcheck(heap_signedint_sz);
	}
	bool heap_boolfunction_empty(void) {
		return heap_signedint_sz == 0;
	}
};

void show(void) {
	printf("\n\n--------------------------------\n\n");
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			switch (mp[i][j]) {
			case 0: putchar('#'); break;
			case 1: putchar('|'); break;
			case 2: putchar('-'); break;
			case 3: putchar('/'); break;
			case 4: putchar('\\'); break;
			case 5: putchar('.'); break;
			case 6: putchar('S'); break;
			case 7: putchar('E'); break;
			case 8: putchar('<'); break;
			case 9: putchar('>'); break;
			case 10: putchar('^'); break;
			case 11: putchar('v'); break;
			}
		}
		putchar(10);
	}
	printf("\n\nleft\n");
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			printf("%d", used[i][j][0]);
		}
		putchar('|');
		for (int j = 1; j <= m; ++j) {
			printf("%2d", ts[i][j][0]);
		}
		putchar(10);
	}
	printf("\n\ndown\n");
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			printf("%d", used[i][j][1]);
		}
		putchar('|');
		for (int j = 1; j <= m; ++j) {
			printf("%2d", ts[i][j][1]);
		}
		putchar(10);
	}
	printf("\n\nright\n");
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			printf("%d", used[i][j][2]);
		}
		putchar('|');
		for (int j = 1; j <= m; ++j) {
			printf("%2d", ts[i][j][2]);
		}
		putchar(10);
	}
	printf("\n\nup\n");
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			printf("%d", used[i][j][3]);
		}
		putchar('|');
		for (int j = 1; j <= m; ++j) {
			printf("%2d", ts[i][j][3]);
		}
		putchar(10);
	}
}
template <class T>inline T read(void) {T ans; static bool f; static char us = getchar(); ans = 0; f = false; while (us < 48 || us > 57) {f |= (us == 45); us = getchar();} while (us > 47 && us < 58) {ans = (ans << 1) + (ans << 3) + (us ^ 48); us = getchar();} return f ? -ans : ans;}
template <typename T>void put(T x) {if (x < 0)return putchar(45), put(-x); else putchar(x > 9 ? put(x / 10), x % 10 | 48 : x % 10 | 48);}
bool cmp(zt*a, zt*b) {
	return a->t > b->t;
}
heap<zt*> q;
int main() {
	memset(ts, 0x00, sizeof ts);
	q.heap_voidfunction_init();
//	freopen("C:\\Users\\Dell\\Desktop\\us.txt", "r", stdin);
	n = read<short>(); m = read<short>(); a = read<short>(); b = read<short>(); c = read<short>(); d = read<short>();
	char us = getchar();
	while (us == ' ' || us == '\n' || us == '\r')us = getchar();
	for (short i = 1; i <= n; ++i) {
		for (short j = 1; j <= m; ++j) {
			switch (us) {
			case '#': {
				mp[i][j] = 0;
				break;
			}
			case '|': {
				mp[i][j] = 1;
				break;
			}
			case '-': {
				mp[i][j] = 2;
				break;
			}
			case '/': {
				mp[i][j] = 3;
				break;
			}
			case '\\': {
				mp[i][j] = 4;
				break;
			}
			case '.': {
				mp[i][j] = 5;
				break;
			}
			case 'S': {
				mp[i][j] = 6;
				q.heap_voidfunction_push(new zt(i, j - 1, 0, 0));
				q.heap_voidfunction_push(new zt(i + 1, j, 1, 0));
				q.heap_voidfunction_push(new zt(i, j + 1, 2, 0));
				q.heap_voidfunction_push(new zt(i - 1, j, 3, 0));
				used[i][j - 1][0] = true;
				used[i + 1][j][1] = true;
				used[i][j + 1][2] = true;
				used[i - 1][j][3] = true;
				ts[i][j - 1][0] = 0;
				ts[i + 1][j][1] = 0;
				ts[i][j + 1][2] = 0;
				ts[i - 1][j][3] = 0;
				break;
			}
			case 'E': {
				mp[i][j] = 7;
				break;
			}
			case '<': {
				mp[i][j] = 8;
				break;
			}
			case '>': {
				mp[i][j] = 9;
				break;
			}
			case '^': {
				mp[i][j] = 10;
				break;
			}
			case 'v': {
				mp[i][j] = 11;
				break;
			}
			}
			us = getchar();
		}
		while (us == ' ' || us == '\n' || us == '\r')us = getchar();
	}
	short nwx, nwy, nwcx;
	int nwt;
	while (!q.heap_boolfunction_empty()) {
		nwx = q.heap_templatefunction_top()->x;
		nwy = q.heap_templatefunction_top()->y;
		nwcx = q.heap_templatefunction_top()->cx;
		nwt = q.heap_templatefunction_top()->t;
		q.heap_voidfunction_pop();
		switch (mp[nwx][nwy]) {
		case 0: {
			continue;
		}
		case 1: {
			switch (nwcx) {
			case 0: {
				if (!used[nwx][nwy - 1][0] || ts[nwx][nwy - 1][0] > nwt + a) {
					q.heap_voidfunction_push(new zt(nwx, nwy - 1, 0, nwt + a));
					used[nwx][nwy - 1][0] = true;
					ts[nwx][nwy - 1][0] = nwt + a;
				}
				break;
			}
			case 1: {
				if (!used[nwx][nwy - 1][0] || ts[nwx][nwy - 1][0] > nwt + a) {
					q.heap_voidfunction_push(new zt(nwx, nwy - 1, 0, nwt + a));
					used[nwx][nwy - 1][0] = true;
					ts[nwx][nwy - 1][0] = nwt + a;
				}
				if (!used[nwx][nwy + 1][2] || ts[nwx][nwy + 1][2] > nwt + a) {
					q.heap_voidfunction_push(new zt(nwx, nwy + 1, 2, nwt + a));
					used[nwx][nwy + 1][2] = true;
					ts[nwx][nwy + 1][2] = nwt + a;
				}
				break;
			}
			case 2: {
				if (!used[nwx][nwy + 1][2] || ts[nwx][nwy + 1][2] > nwt + a) {
					q.heap_voidfunction_push(new zt(nwx, nwy + 1, 2, nwt + a));
					used[nwx][nwy + 1][2] = true;
					ts[nwx][nwy + 1][2] = nwt + a;
				}
				break;
			}
			case 3: {
				if (!used[nwx][nwy - 1][0] || ts[nwx][nwy - 1][0] > nwt + a) {
					q.heap_voidfunction_push(new zt(nwx, nwy - 1, 0, nwt + a));
					used[nwx][nwy - 1][0] = true;
					ts[nwx][nwy - 1][0] = nwt + a;
				}
				if (!used[nwx][nwy + 1][2] || ts[nwx][nwy + 1][2] > nwt + a) {
					q.heap_voidfunction_push(new zt(nwx, nwy + 1, 2, nwt + a));
					used[nwx][nwy + 1][2] = true;
					ts[nwx][nwy + 1][2] = nwt + a;
				}
				break;
			}
			}
			break;
		}
		case 2: {
			switch (nwcx) {
			case 0: {
				if (!used[nwx + 1][nwy][1] || ts[nwx + 1][nwy][1] > nwt + a) {
					q.heap_voidfunction_push(new zt(nwx + 1, nwy, 1, nwt + a));
					used[nwx + 1][nwy][1] = true;
					ts[nwx + 1][nwy][1] = nwt + a;
				}
				if (!used[nwx - 1][nwy][3] || ts[nwx - 1][nwy][3] > nwt + a) {
					q.heap_voidfunction_push(new zt(nwx - 1, nwy, 3, nwt + a));
					used[nwx - 1][nwy][3] = true;
					ts[nwx - 1][nwy][3] = nwt + a;
				}
				break;
			}
			case 1: {
				if (!used[nwx + 1][nwy][1] || ts[nwx + 1][nwy][1] > nwt + a) {
					q.heap_voidfunction_push(new zt(nwx + 1, nwy, 1, nwt + a));
					used[nwx + 1][nwy][1] = true;
					ts[nwx + 1][nwy][1] = nwt + a;
				}
				break;
			}
			case 2: {
				if (!used[nwx + 1][nwy][1] || ts[nwx + 1][nwy][1] > nwt + a) {
					q.heap_voidfunction_push(new zt(nwx + 1, nwy, 1, nwt + a));
					used[nwx + 1][nwy][1] = true;
					ts[nwx + 1][nwy][1] = nwt + a;
				}
				if (!used[nwx - 1][nwy][3] || ts[nwx - 1][nwy][3] > nwt + a) {
					q.heap_voidfunction_push(new zt(nwx - 1, nwy, 3, nwt + a));
					used[nwx - 1][nwy][3] = true;
					ts[nwx - 1][nwy][3] = nwt + a;
				}
				break;
			}
			case 3: {
				if (!used[nwx - 1][nwy][3] || ts[nwx - 1][nwy][3] > nwt + a) {
					q.heap_voidfunction_push(new zt(nwx - 1, nwy, 3, nwt + a));
					used[nwx - 1][nwy][3] = true;
					ts[nwx - 1][nwy][3] = nwt + a;
				}
				break;
			}
			}
			break;
		}
		case 3: {
			switch (nwcx) {
			case 0: {
				if (!used[nwx + 1][nwy][1] || ts[nwx][nwy - 1][1] > nwt + b) {
					q.heap_voidfunction_push(new zt(nwx + 1, nwy, 1, nwt + b));
					used[nwx + 1][nwy][1] = true;
					ts[nwx][nwy - 1][1] = nwt + b;
				}
				break;
			}
			case 1: {
				if (!used[nwx][nwy - 1][0] || ts[nwx + 1][nwy][0] > nwt + b) {
					q.heap_voidfunction_push(new zt(nwx, nwy - 1, 0, nwt + b));
					used[nwx][nwy - 1][0] = true;
					ts[nwx + 1][nwy][0] = nwt + b;
				}
				break;
			}
			case 2: {
				if (!used[nwx - 1][nwy][3] || ts[nwx][nwy + 1][3] > nwt + b) {
					q.heap_voidfunction_push(new zt(nwx - 1, nwy, 3, nwt + b));
					used[nwx - 1][nwy][3] = true;
					ts[nwx][nwy + 1][3] = nwt + b;
				}
				break;
			}
			case 3: {
				if (!used[nwx][nwy + 1][2] || ts[nwx - 1][nwy][2] > nwt + b) {
					q.heap_voidfunction_push(new zt(nwx, nwy + 1, 2, nwt + b));
					used[nwx][nwy + 1][2] = true;
					ts[nwx - 1][nwy][2] = nwt + b;
				}
				break;
			}
			}
			break;
		}
		case 4: {
			switch (nwcx) {
			case 0: {
				if (!used[nwx - 1][nwy][3] || ts[nwx - 1][nwy][3] > nwt + b) {
					q.heap_voidfunction_push(new zt(nwx - 1, nwy, 3, nwt + b));
					used[nwx - 1][nwy][3] = true;
					ts[nwx - 1][nwy][3] = nwt + b;
				}
				break;
			}
			case 1: {
				if (!used[nwx][nwy + 1][2] || ts[nwx][nwy + 1][2] > nwt + b) {
					q.heap_voidfunction_push(new zt(nwx, nwy + 1, 2, nwt + b));
					used[nwx][nwy + 1][2] = true;
					ts[nwx][nwy + 1][2] = nwt + b;
				}
				break;
			}
			case 2: {
				if (!used[nwx + 1][nwy][1] || ts[nwx + 1][nwy][1] > nwt + b) {
					q.heap_voidfunction_push(new zt(nwx + 1, nwy, 1, nwt + b));
					used[nwx + 1][nwy][1] = true;
					ts[nwx + 1][nwy][1] = nwt + b;
				}
				break;
			}
			case 3: {
				if (!used[nwx][nwy - 1][0] || ts[nwx][nwy - 1][0] > nwt + b) {
					q.heap_voidfunction_push(new zt(nwx, nwy - 1, 0, nwt + b));
					used[nwx][nwy - 1][0] = true;
					ts[nwx][nwy - 1][0] = nwt + b;
				}
				break;
			}
			}
			break;
		}
		case 5: {
			if (!used[nwx][nwy - 1][0] || ts[nwx][nwy - 1][0] > nwt + c) {
				q.heap_voidfunction_push(new zt(nwx, nwy - 1, 0, nwt + c));
				used[nwx][nwy - 1][0] = true;
				ts[nwx][nwy - 1][0] = nwt + c;
			}
			if (!used[nwx + 1][nwy][1] || ts[nwx + 1][nwy][1] > nwt + c) {
				q.heap_voidfunction_push(new zt(nwx + 1, nwy, 1, nwt + c));
				used[nwx + 1][nwy][1] = true;
				ts[nwx + 1][nwy][1] = nwt + c;
			}
			if (!used[nwx][nwy + 1][2] || ts[nwx][nwy + 1][2] > nwt + c) {
				q.heap_voidfunction_push(new zt(nwx, nwy + 1, 2, nwt + c));
				used[nwx][nwy + 1][2] = true;
				ts[nwx][nwy + 1][2] = nwt + c;
			}
			if (!used[nwx - 1][nwy][3] || ts[nwx - 1][nwy][3] > nwt + c) {
				q.heap_voidfunction_push(new zt(nwx - 1, nwy, 3, nwt + c));
				used[nwx - 1][nwy][3] = true;
				ts[nwx - 1][nwy][3] = nwt + c;
			}
			break;
		}
		case 6: {
			continue;
		}
		case 7: {
			put(nwt);
			return 0;
		}
		case 8: {
			switch (nwcx) {
			case 2:
			case 0: {
				if (!used[nwx - 1][nwy][3] || ts[nwx - 1][nwy][3] > nwt + d) {
					q.heap_voidfunction_push(new zt(nwx - 1, nwy, 3, nwt + d));
					used[nwx - 1][nwy][3] = true;
					ts[nwx - 1][nwy][3] = nwt + d;
				}
				break;
			}
			case 3: {
				if (!used[nwx - 2][nwy][3] || ts[nwx - 2][nwy][3] > nwt + d) {
					q.heap_voidfunction_push(new zt(nwx - 2, nwy, 3, nwt + d));
					used[nwx - 2][nwy][3] = true;
					ts[nwx - 2][nwy][3] = nwt + d;
				}
				break;
			}
			case 1: {
				break;
			}
			}
			break;
		}
		case 9: {
			switch (nwcx) {
			case 2:
			case 0: {
				if (!used[nwx + 1][nwy][1] || ts[nwx + 1][nwy][1] > nwt + d) {
					q.heap_voidfunction_push(new zt(nwx + 1, nwy, 1, nwt + d));
					used[nwx + 1][nwy][1] = true;
					ts[nwx + 1][nwy][1] = nwt + d;
				}
				break;
			}
			case 1: {
				if (!used[nwx + 2][nwy][1] || ts[nwx + 2][nwy][1] > nwt + d) {
					q.heap_voidfunction_push(new zt(nwx + 2, nwy, 1, nwt + d));
					used[nwx + 2][nwy][1] = true;
					ts[nwx + 2][nwy][1] = nwt + d;
				}
				break;
			}
			case 3: {
				break;
			}
			}
			break;
		}
		case 10: {
			switch (nwcx) {
			case 1:
			case 3: {
				if (!used[nwx][nwy - 1][0] || ts[nwx][nwy - 1][0] > nwt + d) {
					q.heap_voidfunction_push(new zt(nwx, nwy - 1, 0, nwt + d));
					used[nwx][nwy - 1][0] = true;
					ts[nwx][nwy - 1][0] = nwt + d;
				}
				break;
			}
			case 0: {
				if (!used[nwx][nwy - 2][0] || ts[nwx][nwy - 2][0] > nwt + d) {
					q.heap_voidfunction_push(new zt(nwx, nwy - 2, 0, nwt + d));
					used[nwx][nwy - 2][0] = true;
					ts[nwx][nwy - 2][0] = nwt + d;
				}
				break;
			}
			case 2: {
				break;
			}
			}
			break;
		}
		case 11: {
			switch (nwcx) {
			case 1:
			case 3: {
				if (!used[nwx][nwy + 1][2] || ts[nwx][nwy + 1][2] > nwt + d) {
					q.heap_voidfunction_push(new zt(nwx, nwy + 1, 2, nwt + d));
					used[nwx][nwy + 1][2] = true;
					ts[nwx][nwy + 1][2] = nwt + d;
				}
				break;
			}
			case 2: {
				if (!used[nwx][nwy + 2][2] || ts[nwx][nwy + 2][2] > nwt + d) {
					q.heap_voidfunction_push(new zt(nwx, nwy + 2, 2, nwt + d));
					used[nwx][nwy + 2][2] = true;
					ts[nwx][nwy + 2][2] = nwt + d;
				}
				break;
			}
			case 0: {
				break;
			}
			}
			break;
		}
		}
	}
	put(-1);
	return 0;
}


