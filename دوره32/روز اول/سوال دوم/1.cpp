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
const int N=1e6+23,MX=2e4+23,mod=10256483;
int fct[N],inv[N];
int pwe(int x,int y){int a=1;while(y){if(y&1)a=a*x%mod;x=x*x%mod;y/=2;}return a;}
int C(int n,int r){return r<0||n<r?0:fct[n]*inv[r]%mod*inv[n-r]%mod;}
void modplus(int &j,int y){(j+=y)>=mod && (j-=mod);}
bool isprime(int n){bool fl = 1;for (int i = 2; i <= sqrt(n)+1; i++){if(n%i==0){fl = 0;break;}}return fl;}
void printt(bool fl){if(fl==1){cout << "YES";return;}cout << "NO";}
int GCD(int a, int b) {return b?GCD(b,a%b):a;}
void rape(int &a) {if(a <0) a += 10 * mod;a %= mod;}
int LCM(int a, int b) {return a/GCD(a,b)*b;}
int lis(vector<int>& v){if (v.size() == 0) {return 0;} vector<int> tail(v.size(), 0); int szgth = 1; tail[0] = v[0]; for (int i = 1; i < v.size(); i++) {auto b = tail.begin(), e = tail.begin() + szgth; auto it = lower_bound(b, e, v[i]); if (it == tail.begin() + szgth){tail[szgth++] = v[i];}else{*it = v[i];}} return szgth;}
int MOD(int a, int b){return (a%b + b) % b;}
int sexygirl(int n){return (1ull << n);}
int cal(vector<int> arr1,vector<int> v,int sz){return memcmp(arr1.data(), v.data(), sz * sizeof(v[0])) == 0;}
int32_t main()
{
	/*
	int dp[1500][2];
    dp[0][0] =1;
	dp[0][1] = 1;
    for(int i = 1; i < 1401;i++) 
	{
    	dp[i][0]=dp[i-1][0]+dp[i-1][1];
    	dp[i][1]=dp[i-1][0]*dp[i-1][1]%mod;
    }
    cout<<dp[n][1]%mod;
	*/
	cout << 2145227;
}
