//iamaryankr
#include<bits/stdc++.h>
using namespace std; 

#define pb push_back
#define pob pop_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define debugV(v) cout<<#v<<" = [ "; for(int i=0;i<v.size();i++) cout<<v[i]<<' '; cout<<"]"<<nl;
#define debug(x) cout<< #x << " = " << x << endl;
#define debugMat(v) for(int i=0; i<v.size(); i++){ for(int j=0; j<v[0].size(); j++){ cout << v[i][j] << " ";} cout << nl;}
#define fr(i, a, n) for(int i=a; i<n; i++)
#define nl "\n"
#define ff first
#define ss second
#define yes cout<<"YES"<< nl
#define no cout<<"NO"<< nl

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef map<int,int> mii;
 
template <typename T>
void make_min(T& a, const T& b){ a = min(a, b);}
template <typename T>
void make_max(T& a, const T& b){ a = max(a, b);}
 
int gcd(int a, int b){ return (b ? gcd(b, a % b) : a); }
int lcm(int a, int b){ return (a*b/gcd(a,b)); }
int delrow[] = {-1, 0, 1, 0};
int delcol[] = {0, 1, 0, -1};
const string path_grid = "URDL";
bool valid(int i, int j, int n, int m) {return i>=0 && i<n && j<m && j>=0;}
 
const int MOD = 1e9+7;
const int INF = 1e9;
const ll INFF = 1e18;
 

//-------------------------------------main-code-------------------------------------------------------------------------------------------------------------------------------------------------------

//try thinking Binary search(on ans), Bit manipulation,
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers 
//sliding window, Topo sort, dijkstra..
//Dp, Dp, Dp, Dp
 
 
//DONT OVERTHINKKK 
const int mxN = 2e5 + 5;


class segTree{
public:
  int size = 1;
  int no_operation = 0;
  vector<ll> values;
  vector<ll> lazy;
  segTree(int n){
    while(size < n) size*= 2;
    values.resize(2*size, 0); 
    lazy.resize(2*size, 0);
  }

  void applyop(ll &a, ll b){
    a = (a + b);
  }

  void propogate(int node, int low, int high){
    if(lazy[node] == no_operation) return;
    if(low + 1 != high) {
      int mid = (low + high) >> 1;
      applyop(lazy[2*node+1], lazy[node]);
      applyop(lazy[2*node+2], lazy[node]);
    }
    values[node] += lazy[node]*(high - low);
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
    
    values[node] = (values[2*node+1] + values[2*node+2]);
  }
  void update(int l, int r, int v){
    update(l, r, v, 0, 0, size);
  }
  //change this to your ques requirement
  ll calc(int l, int r, int node, int low, int high){
    propogate(node, low, high);

    if(low>=r || high<=l) return 0;
    if(low>=l && high<=r){
      return values[node];
    }
    int mid = (low + high)>>1;
    ll left = calc(l, r, 2*node+1, low, mid);
    ll right = calc(l, r, 2*node+2, mid, high);

    return (left + right);
  } 
  ll calc(int l, int r){
    return calc(l, r, 0, 0, size);
  }
};
void solve(){ 
  int n, m;
  cin >> n >> m;
  segTree ST(n);
  for(int i=0; i<n; i++) ST.update(i, i, 0);

  while(m--){
    int op; cin >> op;
    if(op == 1){
      int l, r, v;
      cin >> l >> r >> v;
      ST.update(l, r, v);
    }
    else if(op == 2){
      int l, r;
      cin >> l >> r;
      cout << ST.calc(l, r) << nl;
    }
  }
}
  
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // cout << setprecision(12) << fixed; 
  int t = 1;
  // cin >> t;
  while (t--) {
      solve();
  }
  return 0; 
}
