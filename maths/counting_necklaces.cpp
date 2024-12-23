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


int mod = 1e9+7;
set<string> st;

ll naive(int n, int m, string pre="")
{
	if(n == 0)
	{
		rep(i, 0, ssize(pre))
		{
			string rot = pre.substr(i)+pre.substr(0, i);
			if(st.count(rot))
				return 0;
		}
		st.insert(pre);
		return 1;
	}
	int res = 0;
	rep(i, 0, m)
	{
		res += naive(n-1, m, pre+char('a'+i));
	}
	return res;
}
array<ll,3> egcd(ll a, ll b) {
	ll x = 1, y = 0;
	ll x1 = 0, y1 = 1, a1 = a, b1 = b;
	while(b1) {
		ll q = a1 / b1;
		tie(x, x1) = make_pair(x1, x - q * x1);
		tie(y, y1) = make_pair(y1, y - q * y1);
		tie(a1, b1) = make_pair(b1, a1 - q * b1);
	}
	return {x, y, a1};
}

ll mod_inverse(ll n, ll mod) {
	auto [x,y,g] = egcd(n, mod);
	if(g != 1) return -1;
	return (x % mod + mod) % mod;
}


signed main()
{
	init();
	int n, m; cin >> n >> m;
	// cout<<naive(n, m)<<endl;
	ll res = 0, pw = 1;
	vi powers(1, 1);
	vi divs;
	rep(i, 1, n+1)
	{
		pw *= m;
		pw %= mod;
		ll sum = pw;
		if(n % i == 0)
		{
			for(int x:divs)
				if(i % x == 0)
					sum = (sum+mod-powers[x])%mod;
			divs.push_back(i);
			sum %= mod;
			res += sum * (n / i);
			res %= mod;
		}
		powers.push_back(sum);
		res %= mod;
	}


	res %= mod;
	res = res * mod_inverse(n, mod);
	res %= mod;
	cout << res << endl;
}
