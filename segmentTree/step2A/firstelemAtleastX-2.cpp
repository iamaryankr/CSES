//iamaryankr
#include<bits/stdc++.h>
using namespace std;

// #define pb push_back
#define pob pop_back
#define sq(x) x*x
#define cube(x) x*x*x
#define all(x) (x).begin(), (x).end()
#define debugV(v) for(int i=0;i<v.size();i++) cout<<v[i]<<' '; cout<<endl;
#define debug(x) cout<< #x << " = " << x << endl;
#define nl "\n"

typedef long double ld;
typedef long long ll;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vi;

int gcd(int a, int b){ return (b ? gcd(b, a % b) : a); }
int lcm(int a, int b){ return (a*b/gcd(a,b)); }


int delrow[] = {-1, 0, 1, 0};
int delcol[] = {0, 1, 0, -1};

const int maxN = 5000000+1;
const int MOD = 1e9+7;
const int N = 1e9;

//segment with maxSum
// class item{
// public:
//   ll seg, pref, suf, sum;
// };
typedef int item;

class segTree{
public:
  ll size = 1 ;
  vector<item> values;

  item neutral_element = INT_MIN;


  item merge(item a, item b) {
    return max(a, b);
  }
  item single(int v){
    return v;
  }

  //creating size starting from root
  segTree(int n){
    while(size<n) size*= 2; 
    values.resize(2*size);
    // for(int i=0; i<2*size; i++) values[i] = 0LL;
  }
  //building the tree
  void build(vector<int> &a, int x /* x is the node*/, int lx, int rx){
    if(rx-lx == 1){
      if(lx < (int)a.size()){
        values[x] = single(a[lx]);
      }
      return ;
    }
    int mid = (lx+rx)/2;
    build(a, 2*x+1, lx, mid);
    build(a, 2*x+2, mid, rx);
    values[x] = merge(values[2*x+1] , values[2*x+2]);
  }
  void build(vector<int> &a){
    build(a, 0, 0, size);
  }

  //setting the a[i] to v;
  void set(int i, int v, int x, int lx, int rx){
    if(rx-lx == 1){
      values[x] = single(v);
      return ;
    }
    int mid = (lx+rx)/2;
    if(i < mid) set(i, v, 2*x+1, lx, mid);
    else set(i, v, 2*x+2, mid, rx);

    values[x] = merge(values[2*x+1], values[2*x+2]);
  }
  void set(int i, int v){
    set(i, v, 0, 0, size);
  }

  //finding sum(l, r);
  item calc(int l, int r, int x, int lx, int rx){
    if(lx >= r || l >= rx) return neutral_element;
    if(lx >= l && rx <= r) return values[x];
    int mid = (lx+rx)/2;
    item lefts = calc(l, r, 2*x+1, lx, mid);
    item rights = calc(l, r, 2*x+2, mid, rx);
    return merge(lefts, rights);
  }
  item calc(int l, int r){
    return calc(l, r, 0, 0, size);
  }

  int first_above(int v, int l, int x, int lx, int rx){
    if(values[x] < v) return -1;
    if(rx <= l ) return -1;
    if(rx-lx==1) return lx;
    int mid = (lx+rx)/2;
    int res = first_above(v, l, 2*x+1, lx, mid);
    if(res==-1) res = first_above(v, l, 2*x+2, mid, rx);

    return res;
  }
  int first_above(int v, int l){
    return first_above(v, l, 0, 0, size);
  }
};

void solve(){
  int n, m;
  cin >> n >> m;
  segTree st(n);
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin>> a[i];
  }
  st.build(a);
  while(m--){
    int op;
    cin>>op;
    if(op==1){
      int i, v;
      cin>>i>>v;
      st.set(i, v);
    }
    else{
      int x, l;
      cin >> x >> l;
      cout << st.first_above(x, l) << endl;
    }
    
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // cout << setprecision(12) << fixed;
  int t=1;
  // cin >> t;
  while (t--){
    solve();
  }
  
  return 0;
}
