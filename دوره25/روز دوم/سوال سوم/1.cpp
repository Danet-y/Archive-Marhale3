#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define _file freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define ll long long
#define ld long double
#define sp setprecision
#define pb push_back
#define F first
#define S second
#define mk make_pair
#define pii pair < int , int >
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod = 10607;
const int maxn = 1e6 + 10;
const ll inf = 1e18;
ll power (ll a , ll b) {
	if (b == 0)
		return 1;
	ll x = power(a , b / 2) % mod;
	if (b % 2)
		return x * x % mod * a % mod;
	return x * x % mod;
}
vector < string > g;
void make(string a , int t){
	if (a.size() == t){
		g.pb(a);
		return;
	}
	make(a + "1" , t);
	make(a + "0" , t);
	return;
}
vector < int > x;
set < int > s;
int main() {
	int n;
	cin >> n;
	make("" , n);
	int ans = 0;
	for (int i = 0; i < g.size(); i++){
		for (int j = 1; j <= g[i].size(); j++){
			if (g[i][j - 1] == '1')
				x.pb(j);
		}
		for (int j = 0; j < x.size(); j++){
			for (int k = j + 1; k < x.size(); k++)
				if (x[k] % x[j] == 0)
					s.insert(x[k] / x[j]);
		}
		ans += s.size();
		ans %= mod;
		s.clear();
		x.clear();
	}
	cout << ans << "\n";
	return 0;
}
