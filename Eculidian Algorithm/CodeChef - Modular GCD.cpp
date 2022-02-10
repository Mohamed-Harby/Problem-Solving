//			بِسْمِ اللَّـهِ الرَّحْمَـٰنِ الرَّحِيمِ

#include <bits/stdc++.h>

using namespace std;

#define all(v) begin(v), end(v)
#define lol                                \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(0);
#define PREC(n) cout << fixed << setprecision(n);
#define eps 1E-10
#define sz(v) int(sizeof(v) / sizeof(v[0]))
#define pi 2 * acos(0.0)
#define inf 1.797E308
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define qi queue<int>
#define pii pair<int, int>
#define ss second
#define ff first
#define oo int(1e9);

ll mod = 1e9 + 7;

inline ll gcd(ll a, ll b) {
	if (a && b)
		while ((a %= b) and (b %= a));
	return a | b;
}

ll mod_exp(ll b, ll p, ll mod) {
	if (p == 0)
		return 1;
	ll ans = mod_exp(b, p >> 1, mod);
	ans = ((__int128) ans * ans) % mod;
	if (p & 1)
		ans = ((__int128) ans * b) % mod; // (mod - 1) * 1e12 = 1e21 > LL_MAX
	return ans;
}

int main() {
	lol
	int t;
	cin >> t;
	ll a, b, n;
	while (t--) {
		cin >> a >> b >> n;
		ll x;
		if (a - b) {
			// gcd(a^n + b^n , a - b) = gcd((a^n + b^n) % (a - b), a - b)
			x = mod_exp(a, n, a - b) + mod_exp(b, n, a - b);
		} else {
			// gcd(exp, 0) % mod = exp % mod = gcd(exp % mod, 0)
			x = mod_exp(a, n, mod) + mod_exp(b, n, mod);
		}
		cout << gcd(x, a - b) % mod << '\n';

	}

	return 0;
}
