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

const int maxn = 5000 + 4;
const int mod = 10289;
ll dp[maxn][maxn], sm_dp[maxn][maxn], C[maxn][maxn];

int main() 
{
	int n,k;
	cin >> n >> k;
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) C[i][j] = 1;
			else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}
	
	for (int i = 1; i <= n - k + 1; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1) {
				dp[i][j] = 1;
			}
			else {
				for (int r = 1; r <= j; r++) {
					dp[i][j] += C[j][r] * (sm_dp[i - 1][j - r] - ((i - k - 1 >= 0) ? sm_dp[i - k - 1][j - r] : 0) + mod) % mod;
					dp[i][j] %= mod;
				}
			}
			
			sm_dp[i][j] = (sm_dp[i - 1][j] + dp[i][j]) % mod;
		}
	}
	
	cout << dp[n - k + 1][n] << endl;
	
	return 0;
}
