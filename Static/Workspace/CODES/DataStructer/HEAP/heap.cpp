template <class T>
class heap {
private:
	signed int sz;
	void sp(T&a, T&b) {
		T c = a;
		a = b;
		b = c;
	}
public:
	vector<T> data;
	heap(void){
		sz=0;
		data.resize(1);
	}
	void init(void) {
		sz = 0;
		data.clear();
		data.resize(1);
	}
	T top(void) {
		if (!empty())return data[1];
		else {
			data.resize(2);
			return data[1];
		}
	}
	void pop(void) {
		sp(data[sz], data[1]);
		--sz;
		data.pop_back();
		downcheck(1);
	}
	void upcheck(int x) {
		while (x > 1 && data[x]<data[x >> 1]) {
			sp(data[x], data[x >> 1]);
			x >>= 1;
		}
		return;
	}
	void downcheck(int x) {
		while (1) {
			if (x << 1 > sz)return;
			if (x << 1 == sz) {
				if (data[x] < data[x << 1])return;
				sp(data[x], data[x << 1]);
				return;
			}
			if (data[x] < data[x << 1] && data[x] < data[(x << 1) | 1])return;
			if (data[x << 1] < data[(x << 1) | 1]) {
				sp(data[x], data[x << 1]);
				x <<= 1;
			}
			else {
				sp(data[x], data[(x << 1) | 1]);
				x <<= 1;
				x |= 1;
			}
		}
	}
	void push(T x) {
		++sz;
		data.push_back(x);
		upcheck(sz);
	}
	bool empty(void) {
		return sz == 0;
	}
};
