#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;


const int p = 31;
ll rollingHash(string &key){
  ll val = 0, pow = 1;
  for(auto c: key){
    val = (val + (c-'a'+1)*pow)%MOD;
    pow = pow*p%MOD;
  }
  return val;
}

//finding hash of any substring of s(l..r);
ll binexp(ll a, ll b){
  ll ans = 1;
  while(b>0){
    if(b%2){
      ans = (ans*a)%MOD;
    }
    a = (a*a)%MOD;
    b = b>>1LL;
  }
  return ans;
}
const int mxN = 1e6;
ll inv[mxN], pref[mxN];

void precomp(string &s){
  ll pow = 1;
  inv[0] = 1;
  pref[0] = 0;
  for(int i=0; i<int(s.size()); i++){
    pow = pow*p%MOD;
    inv[i+1] = binexp(pow, MOD-2);
    pref[i+1] = (pref[i] + (s[i] - 'a' + 1)*pow)%MOD;
  }
}
ll substrHash(int l, int r){ //1 indexed
  ll res = pref[r] - pref[l-1];
  res = (res * inv[l])%MOD;
  return res;
}