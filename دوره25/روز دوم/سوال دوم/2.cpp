#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long  
using namespace std;
using namespace __gnu_pbds;
const int maxn = 200;
const int mod = 10607;
ll modd = 99991;
template <typename T> using ordered_set =  tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll a[maxn][maxn] , b[maxn][maxn] , c[maxn][maxn] , ans[maxn][maxn];
bool mark[maxn][maxn];
ll power (ll a , ll b){
	if (b == 0)
		return 1;
	ll x = power(a , b / 2) % modd;
	if (b % 2)
		return x * x % modd * a % modd;
	return x * x % modd;
}
int main() {
	ios_base :: sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
	int n = 40;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			c[i][j] = power(7 , i) * power(3 , j) % modd + 10000;
	}
	a[1][1] = 1;
	a[1][n] = 1;
	a[n][1] = 1;
	a[n][n] = 1;
	for (int _ = 0; _ < 1e6 + 10; _++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (!mark[i][j] && a[i][j]){
					if (!mark[i][j + 1])
						b[i][j + 1]++;
					if (!mark[i][j - 1])
						b[i][j - 1]++;
					if (!mark[i - 1][j])
						b[i - 1][j]++;
					if (!mark[i + 1][j])
						b[i + 1][j]++;
				}
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (!mark[i][j])
					a[i][j] += b[i][j] , b[i][j] = 0 , ans[i][j]++;
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (a[i][j] >= c[i][j]){
					mark[i][j] = 1;
				}
			}
		}
	}
	ll ans1 = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			if (c[i][j] <= a[i][j])
				ans1 += ans[i][j] , ans1 %= mod;
			}
	//cout << ans1 << "\n";
	cout << ans1 * ans1 % mod * ans1 % mod << "\n";
 	return 0;
}
//The_End
//Game Over :D

