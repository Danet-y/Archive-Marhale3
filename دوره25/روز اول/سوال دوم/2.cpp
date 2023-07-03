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
int cnt[maxn], val[maxn], cntx[maxn];
vector<int> arr;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			cnt[j]++;
			if (i != j) val[j] = i;
		}
	}
	
	for (int i = 1; i <= n; i++) cntx[val[i]]++;
	
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 2) arr.pb(cntx[i]);
	}
	
	sort(all(arr));
	for (int i = 1; i < len(arr); i++) arr[i] += arr[i - 1];
	
	ll output = 0;
	for (int i = 1; i <= k; i++) {
		int j = upper_bound(all(arr), i) - arr.begin() - 1;
		ll val = 0;
		if (j != -1) val = 1ll * (j + 1) * arr[j] % mod;
		output += val * val % mod; output %= mod;
	}
	
	cout << output << endl;
	
	return 0;
}
