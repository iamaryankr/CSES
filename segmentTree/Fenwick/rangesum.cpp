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
  void update(int ind, int val){
    while(ind <= n){
      bit[ind] += val;
      ind += (ind & -ind);
    }
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
void solve(){
  int n, m;
  cin >> n >> m;
  vi a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  fenwick BIT(n);
  BIT.build(a);

  while(m--){
    int op;
    cin >> op;
    if(op == 1){
      int i, val;
      cin >> i >> val;
      BIT.update(i, val-a[i-1]);
      a[i-1] = val;
    }
    else if(op == 2){
      int l, r;
      cin >> l >> r;
      cout << BIT.sum(l, r) << nl;
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