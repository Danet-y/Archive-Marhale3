// In the name of Allah

#include <bits/stdc++.h>
using namespace std;

typedef long long int	ll;
typedef long double	ld;
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;

#define all(x)		(x).begin(),(x).end()
#define len(x)		((ll) (x).size())
#define F		first
#define S		second
#define pb		push_back
#define sep             ' '
#define endl            '\n'
#define Mp		make_pair
#define debug(x)	cerr << #x << ": " <<  x << endl;
#define kill(x)		cout << x << '\n', exit(0);
#define set_dec(x)	cout << fixed << setprecision(x);
#define file_io(x,y)	freopen(x, "r", stdin); freopen(y, "w", stdout);

int n = 1000000, k = 250000;
const int maxn = 1e6 + 4;
const int mod = 10289;
const ll oo = 1e9;
vector<int> adj1[maxn], adj2[maxn];
bool is_prime[maxn];
int cnt[maxn], val[maxn];
int valp[maxn], cntx[maxn];
bool M[maxn];
vector<int> A[maxn];
vector<ll> arr; int D[maxn];
priority_queue<pair<pll, ll>> qu; vector<int> res;

void topol_sort() {
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 3 || cnt[i] == 4 || cnt[i] == 5) {
			if (D[i] == 0) qu.push(Mp(Mp(-cntx[i], len(adj1[i])), -i));
		}
	}
	
	while (!qu.empty()) {
		int v = -qu.top().S; qu.pop();
		res.pb(v);
		
		for (int u : adj1[v]) {
			D[u]--;
			if (D[u] == 0) qu.push(Mp(Mp(-cntx[u], len(adj1[u])), -u));
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	fill(is_prime + 2, is_prime + maxn, 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			cnt[j]++;
			if (i != j) {
				val[j] = i;
			}
			if (is_prime[i] && i != j) {
				valp[j] = i;
				is_prime[j] = 0;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) cntx[val[i]]++;
	
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 3 || cnt[i] == 4 || cnt[i] == 5) {
			int t = 0, x = i;
			while (x % valp[i] == 0) {
				t++; x /= valp[i];
			}
			if (cnt[i] == t + 1) A[valp[i]].pb(i);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < len(A[i]); j++) {
			int u = A[i][j - 1], v = A[i][len(A[i]) - 1];
			adj2[u].pb(v); adj1[v].pb(u);
			D[u]++;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (len(adj2[i]) > 0) cntx[i]--;
	}
	
	topol_sort();
	
	for (int i = 0; i < len(res); i++) {
		int u = res[i];
		arr.pb(cntx[u]);
	}
	for (int i = 1; i < len(arr); i++) arr[i] += arr[i - 1];
	
	ll output = 0;
	for (int i = 1; i <= k; i++) {
		int j = upper_bound(all(arr), i) - arr.begin() - 1;
		ll val = 0;
		if (j != -1) val = 1ll * (j + 1) * (arr[j] % mod) % mod;
		output += val * val % mod; output %= mod;
	}
	
	cout << output << endl;
	
	return 0;
}
