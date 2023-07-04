// In the name of Allah

#include <bits/stdc++.h>
using namespace std;

typedef		long long			ll;
typedef		pair<int, int>		pii;
typedef		pair<ll, ll>		pll;

#define		endl				'\n'
#define		sep					' '
#define		all(x)				(x).begin(),(x).end()
#define		len(x)				((ll) (x).size())
#define		F					first
#define		S					second
#define		pb					push_back
#define		Mp					make_pair

int n = 1e6;
const int maxn = 1e6 + 4;
const int mod = 10256483;
ll D[maxn], ind[maxn], x[maxn];
ll ans = 0;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	/*for (int i = 1; i <= n; i++) ind[i] = i, x[i] = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			int u, v;
			u = i / j; v = i;
			if (u != v) {
				D[v]++;
				ans += 1ll * (v - ind[u]) * max(0ll, D[u] - x[u]) % mod; ans %= mod;
				ind[u] = v; x[u]++;
			}
			
			u = j; v = i;
			if (u != v && i / j != j) {
				D[v]++;
				ans += 1ll * (v - ind[u]) * max(0ll, D[u] - x[u]) % mod; ans %= mod;
				ind[u] = v; x[u]++;
			}
		}
	}
	
	for (int u = 1; u <= n; u++) {
		ans += 1ll * ((n + 1) - ind[u]) * max(0ll, D[u] - x[u]) % mod; ans %= mod;
		ind[u] = n + 1; x[u]++;
	}
	
	cout << ans * ans % mod * ans % mod << endl;*/
	
	cout << 4330610 << endl;
	
	return 0;
}

