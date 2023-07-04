#include <bits/stdc++.h>
using namespace std;
#define Tof_Io ios_base::sync_with_stdio(false);cin.tie(0) , cout.tie(0);
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define int long long int
#define F first
#define S second
#define tagh2(j) j>>1
#define zarb2(j) j<<1
#define forr(n) for(int i = n ;i>0; i--) 
const int N=1e6+23,MX=2e4+23,mod=10256483,mod1 = 1e9+7;
vector<int> adj[N];
int fac[N];
int inv[N];
int di[N];
int dp[N];
int n= 1401401,m = 202022;
vector<int> seen(N);
int pwe(int a, int b, int md = mod){int res = 1; while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}
void modplus(int &j,int y){(j+=y)>=mod && (j-=mod);}
bool seenprime(int n){bool fl = 1;for (int i = 2; i <= sqrt(n)+1; i++){if(n%i==0){fl = 0;break;}}return fl;}
void printt(bool fl){if(fl==1){cout << "YES";return;}cout << "NO";}
int GCD(int a, int b) {return b?GCD(b,a%b):a;}
int MOD(int a, int b=mod1){ int res = a + b; return (res >= mod? res - mod : res); }
int LCM(int a, int b) {return a/GCD(a,b)*b;}
int lseen(vector<int>& v){if (v.size() == 0) {return 0;} vector<int> tail(v.size(), 0); int szgth = 1; tail[0] = v[0]; for (int i = 1; i < v.size(); i++) {auto b = tail.begin(), e = tail.begin() + szgth; auto it = lower_bound(b, e, v[i]); if (it == tail.begin() + szgth){tail[szgth++] = v[i];}else{*it = v[i];}} return szgth;}
int yay(int n){return (1ull << n);}
int C(int n,int r){return fac[n] * inv[r] % mod * inv[n-r] % mod;}
void dfs(int v,int p = -1) {if(adj[v].size() == 1){dp[v] = 1;return;}if(seen[v]) dp[v] = 0; else dp[v] = 1;for(int u : adj[v]) {if(u == p) continue;dfs(u,v);if(seen[v]) {dp[v] += dp[u];} else{ dp[v] *= dp[u];}dp[v]=dp[v]%mod;}}
void build(){fac[0] = 1; inv[0] = pwe(fac[0],mod-2);for(int i = 1 ; i< N ; i ++) {fac[i] = (fac[i-1] * i)%mod;inv[i] = pwe(fac[i],mod-2);}}
int cal(vector<int> arr1,vector<int> v,int sz){return memcmp(arr1.data(), v.data(), sz * sizeof(v[0])) == 0;}

int32_t main() 
{
	freopen("tree.in", "r", stdin);
	for(int i = 0; i < n-1; i++) 
	{
		int v,u; 
		cin >> v >> u;
		adj[v].pb(u); 
		adj[u].pb(v);
	}
	for(int i = 0 ; i < m ;i++) 
	{
		int x;
		cin >> x;
		seen[x] = 1;
	}
	dfs(1);
	cout<<dp[1];
}
