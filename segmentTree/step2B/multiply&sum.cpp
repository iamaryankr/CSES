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

class segTree {
public:
    int size = 1;
    vector<ll> multtree;
    vector<ll> sumtree;


    void build(ll x, ll low, ll high){
      if(high-low==1) {
        sumtree[x] =  1;
        return;
      }
      ll mid = (low + high)/2;
      build(2*x + 1, low, mid);
      build(2*x + 2, mid, high);
      sumtree[x]= sum_op(sumtree[2*x+1],sumtree[2*x+2]);
    }
    segTree(int n) {
        while (size < n) {
            size *= 2;
        }
        multtree.resize(2 * size, 1LL);
        sumtree.resize(2 * size, 0LL);
        build(0, 0, size);
    }
    ll multiply_op(ll a, ll b){
      return a*b % MOD;
    }
    ll sum_op(ll a, ll b){
      return (a+b)%MOD;
    }
    void modify_op(ll &a, ll b){
      a = multiply_op(a, b);
    }

    void multiply(int x, int low, int high, int l, int r, int v) {
      if (low >= r || high <= l) return ;
      if (low >= l && high <= r){
        modify_op(sumtree[x], v);
        modify_op(multtree[x], v);
        return;
      }

      int mid = (low + high) / 2;
      multiply(2*x + 1, low, mid, l, r, v);
      multiply(2*x + 2, mid, high, l, r, v);

      sumtree[x] = sum_op(sumtree[2*x+1], sumtree[2*x+2]);
      modify_op(sumtree[x], multtree[x]);
    }

    void multiply(int l, int r, int v) {
      multiply(0, 0, size, l, r, v);
    }

    ll sum(int l, int r, int x, int low, int high){
      if (low >= r || high <= l) return 0;
      if (low >= l && high <= r){
        return sumtree[x];
      }

      int mid = (low + high) / 2;
      ll lsum = sum(l, r, 2*x + 1, low, mid);
      ll rsum = sum(l, r, 2*x + 2, mid, high);
      ll res = sum_op(lsum, rsum);

      modify_op(res, multtree[x]);
      return res;
    }
    ll sum(int l, int r){
      return sum(l, r, 0, 0, size);
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
      st.multiply(l,r,v);
    }
    else{
      ll l, r;
      cin>>l >> r;
      cout << st.sum(l, r)<< nl;
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