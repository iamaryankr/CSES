//iamaryankr
#include<bits/stdc++.h>
using namespace std; 

//with lazy 
//Range updates & Range queries
class segTree{
public:
  int size = 1;
  int no_operation = 0; //change this
  vector<int> values; //storing the reqd calc
  vector<int> lazy;
  segTree(int n){
    while(size < n) size*= 2;
    values.resize(2*size, 0); //change initial values
    lazy.resize(2*size, 0); //change initial values
  }

  int operation(int a, int b){  //change this
    if(b == no_operation) return a;
    return (a | b);
  }
  void applyop(int &a, int b){
    a = operation(a, b);
  }
  int calc_op(int a, int b){ //change this
   return (a & b);
  }

  void propogate(int node, int low, int high){
    if(lazy[node] == no_operation) return;
    if(low + 1 != high) {
      int mid = (low + high) >> 1;
      applyop(lazy[2*node+1], lazy[node]);
      applyop(lazy[2*node+2], lazy[node]);
    }
    applyop(values[node], lazy[node]); //change this if reqd
    lazy[node] = no_operation;
  }
  
  void update(int l, int r, int v, int node, int low, int high){
    propogate(node, low, high);

    if(low>=r || high<=l) return;
    if(low>=l && high<=r){
      applyop(lazy[node], v);
      propogate(node, low, high);
      return;
    }
    int mid = (low + high)>>1;
    update(l, r, v, 2*node+1, low, mid);
    update(l, r, v, 2*node+2, mid, high);
    
    values[node] = calc_op(values[2*node+1] , values[2*node+2]);
  }
  void update(int l, int r, int v){
    update(l, r, v, 0, 0, size);
  }
  //change this to your ques requirement
  int calc(int l, int r, int node, int low, int high){
    propogate(node, low, high);

    if(low>=r || high<=l) return -1; //change this
    if(low>=l && high<=r){
      return values[node];
    }
    int mid = (low + high)>>1;
    int left = calc(l, r, 2*node+1, low, mid);
    int right = calc(l, r, 2*node+2, mid, high);

    return calc_op(left, right);
  } 
  int calc(int l, int r){
    return calc(l, r, 0, 0, size);
  }
};