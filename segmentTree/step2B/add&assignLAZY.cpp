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
//similar code for all operations + assignments
//add+assign... min+assign
class segTree {
public:
    int size = 1;
    vector<ll> operations;
    vector<ll> values;
    ll neutral_ele = 0;
    ll no_operation = LLONG_MAX-1;

    segTree(int n) {
        while (size < n) {
            size *= 2;
        }
        operations.resize(2 * size, 0LL);
        values.resize(2 * size, 0LL);
    }
    ll modify_op(ll a, ll b, ll len){
      if(b==no_operation) return a;
      return b*len;
    }
    ll calc_op(ll a, ll b){
      return a+b;
    }
    void apply_mod(ll &a, ll b, ll len){
      a = modify_op(a, b, len);
    }

    void propogate(int x, int low, int high){
      if(low == high-1) return;

      int mid = (low + high)/2;
      apply_mod(operations[2*x+1], operations[x], 1);
      apply_mod(values[2*x+1], operations[x], mid-low);
      apply_mod(operations[2*x+2], operations[x], 1);
      apply_mod(values[2*x+2], operations[x], high-mid);
      operations[x] = no_operation;
    }

    void modify(int x, int low, int high, int l, int r, int v) {
      propogate(x, low, high);

      if (low >= r || high <= l) return ;
      if (low >= l && high <= r){
        apply_mod(values[x], v, high-low);
        apply_mod(operations[x], v, 1);
        return;
      }

      int mid = (low + high) / 2;
      modify(2*x + 1, low, mid, l, r, v);
      modify(2*x + 2, mid, high, l, r, v);

      values[x] = calc_op(values[2*x+1], values[2*x+2]);
    }

    void modify(int l, int r, int v) {
      modify(0, 0, size, l, r, v);
    }

    ll calc(int l, int r, int x, int low, int high){
      propogate(x, low, high);

      if (low >= r || high <= l) return neutral_ele;
      if (low >= l && high <= r){
        return values[x];
      }

      int mid = (low + high) / 2;
      ll lsum = calc(l, r, 2*x + 1, low, mid);
      ll rsum = calc(l, r, 2*x + 2, mid, high);

      ll res = calc_op(lsum, rsum);
      return res;
    }
    ll calc(int l, int r){
      return calc(l, r, 0, 0, size);
    }

};

void solve() {
  ll n,m;
  cin>>n>>m;
  segTree st(n);
  while(m--){
    int op;
    cin>>op;
    if(op==1){
      ll l,r,v;
      cin>>l>>r>>v;
      st.modify(l,r,v);
    }
    else{
      ll l, r;
      cin>>l >> r;
      cout << st.calc(l, r)<< nl;
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