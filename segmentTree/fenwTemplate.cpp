//iamaryankr
#include<bits/stdc++.h>
using namespace std; 
using ll = long long;

//these are build 1-indexed
//Point update & Range queries
class fenwick{
public:
  int n;
  vector<ll> bit;
  fenwick(int n){
    this->n = n + 1;
    bit.assign(n+1, 0);
  }
  void build(vector<int> &a){
    for(int i=0; i<a.size(); i++) update(i+1, a[i]);
  }
  //adding value val to a[i]
  void update(int ind, int val){ // 1-indexed
    while(ind <= n){
      bit[ind] += val;
      ind += (ind & -ind);
    }
  }
  //tells the sum from 1->ind 
  ll query(int ind){ //1-indexed
    ll ans = 0;
    while(ind > 0){
      ans += bit[ind];
      ind -= (ind & -ind);
    }
    return ans;
  }
  ll sum(int l, int r){ //l, r both 1-indexed  (l <= r <= n)
    return query(r)-query(l-1);
  }
};


//Range update fenw & Point queries
class fenwick{
public:
  int n;
  vector<ll> bit;
  fenwick(int n){
    this->n = n + 1;
    bit.assign(n+2, 0);
  }
  void build(vector<int> &a){
    for(int i=0; i<(int)a.size(); i++){
      update(i+1, a[i]);
      update(i+2, -a[i]);
    }
  }
  void update(int ind, int val){
    while(ind <= n){
      bit[ind] += val;
      ind += (ind & -ind);
    }
  }
  void range_update(int l, int r, int val){
    update(l, val);
    update(r+1, -val);
  }
  ll query(int ind){
    ll ans = 0;
    while(ind > 0){
      ans += bit[ind];
      ind -= (ind & -ind);
    }
    return ans;
  }
  ll sum(int l, int r){
    return query(r)-query(l-1);
  }
};


//Range update & Range Queries
//2 trees are required
class fenwick {
public:
  int n;
  vector<ll> bit1, bit2;

  fenwick(int n) {
    this->n = n + 1;
    bit1.assign(n + 2, 0);
    bit2.assign(n + 2, 0);
  }
  void build(vector<int>& a){
    for(int i=0; i<int(a.size()); i++){
      range_update(i+1, i+1, a[i]);
    }
  }
  // Point update function
  void update(vector<ll>& bit, int ind, ll val) {
    while (ind <= n) {
      bit[ind] += val;
      ind += (ind & -ind);
    }
  }

  // Range update function
  void range_update(int l, int r, ll val) {
    update(bit1, l, val);
    update(bit1, r + 1, -val);
    update(bit2, l, val * (l - 1));
    update(bit2, r + 1, -val * r);
  }

  // Point query function
  ll query(vector<ll>& bit, int ind) {
    ll ans = 0;
    while (ind > 0) {
      ans += bit[ind];
      ind -= (ind & -ind);
    }
    return ans;
  }

  // Prefix sum up to index ind
  ll prefix_sum(int ind) {
    return query(bit1, ind) * ind - query(bit2, ind);
  }

  // Range sum query [l, r]
  ll range_query(int l, int r) {
    return prefix_sum(r) - prefix_sum(l - 1);
  }
};