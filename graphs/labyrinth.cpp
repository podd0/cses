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

int r, c; 
vpii dirs = {{1, 0}, {0, 1}, {-1, 0} , {0, -1}};
string dname = "DRUL";

signed main()
{
	init();
	cin >> r >> c;
	vector<string> mat(r);
	cin >> mat;

	int ai = 1, aj = 1, bi = 1, bj = 1;
	rep(i, 0, r)
		rep(j, 0, c)
		{
			if(mat[i][j] == 'A')
			{
				ai = i;
				aj = j;
			}
			if(mat[i][j] == 'B')
			{
				bi = i; bj = j;
			}
		}
	
	vector<vector<char>> from(r, vector<char>(c, '.'));
	vvi pri(r, vi(c,-1)), prj (r, vi(c,-1));
	queue<pair<int, int>> q;
	q.push({ai, aj});
	while(q.size())
	{
		auto [i, j] = q.front(); q.pop();
		// cout<<i<<' '<<j<<endl;
		rep(k, 0, 4)
		{
			auto [di, dj] = dirs[k];
			int  ei = di+i, ej = dj+j;
			if(ei < 0 || ej < 0 || ei >= r || ej >= c || mat[ei][ej] == '#' || pri[ei][ej] != -1)
				continue;
			from[ei][ej] = dname[k];
			pri[ei][ej] = i;
			prj[ei][ej] = j;
			q.push({ei, ej});
		}
	}
	// cout<<from<<pri<<prj;
	string s = "";
	if(pri[bi][bj] != -1)
	{
		int i = bi, j = bj;
		while(i != ai || j != aj)
		{
			s+=from[i][j];
			tie(i, j) = tie(pri[i][j], prj[i][j]);
		}
		reverse(all(s));
		ans("YES\n"<<s.size()<<endl<<s)
	}
	ans("NO")
}