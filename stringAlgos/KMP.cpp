#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

//len of longest proper prefix of substr(0, i) 
//which is also a suffix
vector<int> prefix_function(string &s){
  int n = s.size();
  vector<int> pi(n);
  for(int i=1; i<n; i++){
    int j = pi[i-1];
    while(j > 0 && s[i] != s[j]){
      j = pi[j-1];
    }
    if(s[i] == s[j]) j ++ ;
    pi[i] = j;
  }
  return pi;
}

vector<int> z_function(string &s) {
  int n = s.size();
  vector<int> z(n);
  int l = 0, r = 0;
  for(int i = 1; i < n; i++) {
    if(i < r) z[i] = min(r - i, z[i - l]);
    while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if(i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}
