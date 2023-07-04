#include<bits/stdc++.h>
#ifdef LOCAL
#include "Essentials/algo/debug.h"
#else
#define debug(...) 69
#endif
using namespace std;

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef long long     ll;
typedef long double   ldb;
typedef pair<int,int> pii;
typedef pair<ll,ll>   pll;

const int N = 2e6 + 23;
const ll mod = 10256483; // 998244353
const int LOG = 23;
const ll inf = 1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define F           first
#define S           second
#define pb          push_back
#define ms(x,y)     memset((x) , (y) , sizeof (x))
#define done        return cout<<endl , 0;
#define kill(x)     cout<<x<<endl, exit(0);
#define isIn(x,s,e) ((x) >= (s) && (x) <= e)
#define all(x)      x.begin(),x.end()
#define sz(x)       (int)x.size()
#define pc(x)       __builtin_popcount(x)
#define ctz(x)      __builtin_ctz(x)
#define MinHeap(x)  priority_queue<x, vector<x> , greater<x> >
#define MaxHeap(x)  priority_queue<x, vector<x>>
#define lc(id)      (id << 1)
#define rc(id)      ((id<<1) |1)
#define pt(id)      (id >> 1)
#define int      ll

ll pw(ll a, ll b, ll md = mod){ll res = 1; while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

void ok(int &a) {
	a %= mod;
}

int n= 1401401,m = 202022;
bool is[N];
vector<int> G[N];
vector<int> koochik;

void dfs(int v,int p=-1) {
	sort(all(G[v]));
	koochik.pb(v);
	if(is[v]) {
		vector<int> x;
		for(int u : G[v]) if(u != p) {
			if(u != p) {
				x.pb(u);
				break;
			}
		}
		G[v] = x;
	}
	for(int u : G[v]) {
		if(u != p) {
			dfs(u,v);
		}
	}
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout<<8577391;
    done;
	freopen("tree.in", "r", stdin);
	for(int i = 1; i< n; i++) {
		int v,u; cin>>v>>u;
		G[v].pb(u); G[u].pb(v);
	}
	for(int i = 0 ; i < m ;i++) {
		int x; cin>>x; is[x] =1;
	}
	dfs(1);
	int ans= koochik[1400];
	cout<<pw(ans,3);
    done;
}

