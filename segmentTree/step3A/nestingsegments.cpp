//iamaryankr
#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define pob pop_back
#define all(x) (x).begin(), (x).end()
#define debugV(v) cout<<#v<<" = [ "; for(int i=0;i<v.size();i++) cout<<v[i]<<' '; cout<<"]"<<nl;
#define debug(x) cout<< #x << " = " << x << endl;
#define debugMat(v) for(int i=0; i<v.size(); i++){ for(int j=0; j<v[0].size(); j++){ cout << v[i][j] << " ";} cout << nl;}
#define fr(i, a, n) for(int i=a; i<n; i++)
#define nl "\n"
#define ff first;
#define ss second;
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
 
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
 
int gcd(int a, int b){ return (b ? gcd(b, a % b) : a); }
int lcm(int a, int b){ return (a*b/gcd(a,b)); }
 
int delrow[] = {-1, 0, 1, 0};
int delcol[] = {0, 1, 0, -1};
bool valid(int i, int j, int n, int m) {return i>=0 && i<n && j<m && j>=0;}

const int MOD = 1e9+7;
const int INF = 1e9;
const ll INFF = 1e18;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//try thinking Binary search(on ans), Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers, bitmask
//sliding window


//DONT OVERTHINKKK//

class Segtree{
public:
  vector<int> values;
  int size = 1;
  Segtree(int n){
    while(size < n) size *= 2 ;
    values.resize(size*2, 0);
  }
  int merge(int a, int b){
    return a + b;
  }

  void build(int x, int low, int high, vector<int> &a){
    if(low + 1 == high){
      if(low < int(a.size())) values[x] = a[low];
      return;
    }
    int mid = (low + high) >> 1;
    build(2*x + 1, low, mid, a);
    build(2*x + 2, mid, high, a);
    
    values[x] = merge(values[2*x + 1], values[2*x + 2]);
  }
  void build(vector<int> &a){
    build(0, 0, size, a);
  }

  void set(int x, int low, int high, int i, int v){
    if(low + 1 == high){
      values[x] = v;
      return;
    }
    int mid = (low + high) >> 1;
    if(i < mid) set(2*x + 1, low, mid, i, v);
    else set(2*x + 2, mid, high, i, v);
    
    values[x] = merge(values[2*x + 1], values[2*x + 2]);
  }
  void set(int i, int v){
    set(0, 0, size, i, v);
  }

  int calc(int x, int low, int high, int l, int r){
    if(low >= r || high <= l) return 0;
    if(low >= l && high <= r) return values[x];
    int mid = (low + high) >> 1;
    int left = calc(2*x + 1, low, mid, l, r);
    int right = calc(2*x + 2, mid, high, l, r);

    return merge(left, right);
  }
  int calc(int l, int r){
    return calc(0, 0, size, l, r);
  }

};


void solve(){
  int n;
  cin >> n;
  vi a(2*n);
  for(int i=0; i<2*n; i++) cin >> a[i];

  vector<int> freq(n + 1, 0);

  Segtree st(n + 1);
  st.build(freq);

  vector<int> ans(n, 0);

  for(int i=0; i<2*n; i++){
    if(freq[a[i]] == 0) freq[a[i]] = i + 1;
    else{
      ans[a[i] - 1] = st.calc(freq[a[i]] - 1, i);
      st.set(freq[a[i]] - 1, 1);
    }
  }
  for(auto it: ans) cout << it << " ";
  cout << nl;
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
