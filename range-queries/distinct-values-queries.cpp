#include<bits/stdc++.h>
using namespace std;

void init() {
	cout.precision(17);
	cin.tie(0)->sync_with_stdio(false);
	#ifndef TIE
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
}

// #define int long long
#define all(c) begin(c), end(c)
#define rep(ind, st, end) for(int ind = st; ind<end; ind++)
#define revp(ind, end, st) for(int ind = st; ind-->end; )
#define modfor(ind, st, mod) for(int ind = st, _fl=false; ind!=st || !_fl; ind = (i+1)%mod, _fl=true)
#define ssize(c) static_cast<int>(c.size())
#define lg2(x) (__builtin_clz(1) - __builtin_clz(x))
#define pb push_back
#define F first
#define S second
#ifndef TIE
	#define endl '\n'
#endif
#define vv vector<vector
#define rdup(a, b)  (a%b ? (a/b+1) : a/b)
#define ith_bit(n, i) (((n)>>(i))&1)


using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vvi = vector<vector<int >> ;
using vvll = vector<vector<ll >> ;
using vvpii = vector<vector<pii >> ;

// sets res to last n in range [l, r] s.t. f is true
#define binsearch(l, r, f, res) { \
	ll cpl = l, cpr = r, mid; \
	while(cpl < cpr)\
	{\
		mid = (cpl+cpr)/2; \
		if(f) cpl = mid+1; \
		else cpr = mid; \
	}\
	res = cpl-1; \
}

template<class T>
int max(const vector<T> &v) { int r = 0; rep(i, 1, ssize(v)) if(v[i]>v[r]) r = i; return r; }
template<class T>
int min(const vector<T> &v) { int r = 0; rep(i, 1, ssize(v)) if(v[i]<v[r]) r = i; return r; }
template<class T>
istream& operator >> (istream &input, vector<T>& vec) { rep(i, 0, ssize(vec)) input >> vec[i]; return input; }
template<class T>
ostream& operator << (ostream &out, const vector<T>& vec){ out << "["; rep(i, 0, ssize(vec)) out << ' ' << vec[i]; out << " ]\n"; return out; }
template<class T, size_t Z>
istream& operator >> (istream &input, array<T, Z>& vec) { rep(i, 0, ssize(vec)) input >> vec[i]; return input; }
template<class T, size_t Z>
ostream& operator << (ostream &out, const array<T, Z>& vec){ out << "["; rep(i, 0, ssize(vec)) out << ' ' << vec[i]; out << " ]\n"; return out; }
template<class A, class B>
istream& operator >> (istream &input, pair<A, B>& pp) { input >> pp.first >> pp.second; return input; }
template<class A, class B>
ostream& operator << (ostream &out, const pair<A, B>& pp) { out << "(" << pp.F << ", " << pp.S << ")"; return out; }

#define ans(x) {cout << x << endl; return 0; }

// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓


struct Fenwick {
	using Value = int;

	vector<Value> ft;
	Fenwick(int N) { ft.assign(N+1, 0); }
	template<typename T> Fenwick(const vector<T>& data) {
		ft.push_back(0);
		ft.insert(ft.end(), data.begin(), data.end());
		for(int i = 1, j = 2; i < ssize(ft); ++i, j = i+(i&-i))
			if(j < ssize(ft))
				ft[j] += ft[i];
	}
	void add(int p, Value v) {
		for(++p; p < ssize(ft); p += p&-p) ft[p] += v;
	}
	Value sum(int b) {
		Value res = 0;
		for(++b; b > 0; b -= b&-b) res += ft[b];
		return res;
	}
	// [a, b]
	Value sum(int a, int b) { return sum(b) - (a?sum(a-1):0); }
	Value get(int p) { return sum(p, p); }
	void set(int p, Value v) { 
		// cout<<"set :"<<p <<' '<<v<<endl;
		add(p, v - get(p)); }
};



signed main()
{
	init();
	int n; cin >> n;
	int q; cin >> q;
	vi v(n); cin >> v;

	vector<array<int, 3>> qr(q);

	rep(i, 0, q)
	{
		int l, r; cin >> l >> r;
		l--; r--;
		qr[i] = {l, r, i};
	}
	sort(all(qr));

	vi res (q);
	int curr = q-1;
	Fenwick ft(n);
	map<int, int> lind;
	revp(i, 0, n)
	{
		if(lind.count(v[i]))
			ft.set(lind[v[i]], 0);
		ft.set(i, 1);
		lind[v[i]] = i;
		while(curr >= 0 && qr[curr][0] == i)
		{
			// cout<<qr[curr];
			res[qr[curr][2]] = ft.sum(qr[curr][0], qr[curr][1]);
			curr--;
		}
	}

	for(int x:res)
		cout << x << endl;

}
