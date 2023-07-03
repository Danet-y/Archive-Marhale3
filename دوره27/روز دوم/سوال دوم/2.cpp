#include <bits/stdc++.h> 
#define pb push_back 
#define F first 
#define S second 
#define all(a) a.begin(),a.end() 
#define pii pair<int,int>
#define int long long
#define ld long double
#define mat vector<vector<int> > 
using namespace std ;
const int  maxn =102, maxq = 1e5 + 10,inf =1e9 + 10 , mod= 10289 ; 
int po(int a ,int b){
  if(b==0)return 1;
  int v = po(a , b/2) ;
  v = v * v % mod ;
  if(b&1)v = (v*a)%mod ;
  return v;
}
int f[maxn] , inv[maxn] ; 

int c(int n , int k){
  return (f[n] * inv[k] % mod * inv[n-k]%mod)%mod ;
}
int dp[maxn][maxn][maxn]  ;
int kat(int n){
  return (c(n , n/2) - c(n , n/2+1) + mod)%mod ;
}
signed main(){
  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
  int n = 70  ; 
  f[0] = 1;
  for(int i = 1; i <= n ; i++){
    f[i] = f[i-1] * i % mod ;
  }
  for(int i = 0 ;i <= n ; i++){
    inv[i] =po(f[i] , mod-2) ;
  }
  int ans =0  ;
  for(int i = 0; i <= n-2 ; i++){
    ans = (ans + kat(n-2) + mod) %mod ;
    if(i%2==0){
      ans =  (ans - kat(i) * kat(n-2-i)%mod + mod)%mod ;
    }
  }
  cout << ans ; 
}
/*
  
  }
*/



