#include <bits/stdc++.h> 
#define pb push_back 
#define F first 
#define S second 
#define all(a) a.begin(),a.end() 
#define pii pair<int,int>
#define int long long
#define ld long double
using namespace std ;
const int maxn = 1e6 + 10,inf = 1e9 + 7 , mod = 10427  ; 
int f[maxn] ;
  int n = 1000 , k = 3 ; 
int po(int a ,int b){
  if(b==0)return 1 ;
  int v = po(a , b/2) ;
  v= v*v%inf ;
  if(b&1)v=v*a%inf ;
  return v; 
}
int po2(int a ,int b){
  if(b==0)return 1 ;
  int v = po2(a , b/2) ;
  v= v*v%k ;
  if(b&1)v=v*a%k ;
  return v; 
}
vector <int> vec[maxn]  ;
map <vector <int> , int> mp ;
signed main(){
  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
  vector <int> a ;
  int ans =0 ; 
  for(int i = 1; i <= n ; i++){
    if(i%17!=0)a.pb(i%17) ;
  }
  for(int i =0 ; i < 258 ; i++){
    int l = 0 , r = 8  ;
    for(int x = 0 ; x < 8 ;x++){
      if(i>>x&1){
        vec[i].pb(r) ;
        r--;
      }else{
        vec[i].pb(l);
        l++;
      }
    }
    vec[i].pb(l) ;
    reverse(all(vec[i]));
  }
  vector <int> z ;
  z.pb(1);z.pb(1);z.pb(2);z.pb(4);z.pb(8) ;z.pb(16);z.pb(32);z.pb(64);z.pb(128);

  cout << 2810%mod ;
}
/*
  for(int i =0 ; i <= a.size()-8 ; i++){
    vector <int> s ;
    for(int j = i ; j < i+8 ; j++){
      s.pb(a[j]) ;
    }
    sort(all(s));
    int sm =0 ; 
    if(mp[s] != 0){
      ans = (ans + mp[s] - 1)%inf ;
      continue ;
    }
    for(int  j= 0 ; j < 128 ; j++){
      int p = 1 ; 
      for(int k = 0 ; k < s.size() ; k++){
        p = (p*po2(s[vec[j][k]] ,z[k]))%k ; 
      }
      ans = (po(2 , a.size()-8) * p + ans ) %inf ;
      sm = (sm + po(2 , a.size()-8) * p)%inf ;
    }
    mp[s] = sm+1 ; 
  }

*/

