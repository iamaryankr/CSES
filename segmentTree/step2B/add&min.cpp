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
    vector<ll> sumtree;
    vector<ll> mintree;

    segTree(int n) {
        while (size < n) {
            size *= 2;
        }
        sumtree.resize(2 * size, 0LL);
        mintree.resize(2 * size, 0LL);
    }

    void add(int x, int low, int high, int l, int r, int v) {
      if (low >= r || high <= l) return ;
      if (low >= l && high <= r){
        sumtree[x] += v;
        mintree[x] += v;
        return;
      }

      int mid = (low + high) / 2;
      add(2*x + 1, low, mid, l, r, v);
      add(2*x + 2, mid, high, l, r, v);

      mintree[x] = min(mintree[2*x+1], mintree[2*x+2]) + sumtree[x];
    }

    void add(int l, int r, int v) {
      add(0, 0, size, l, r, v);
    }

    ll mini(int l, int r, int x, int low, int high){
      if (low >= r || high <= l) return LLONG_MAX;
      if (low >= l && high <= r){
        return mintree[x];
      }

      int mid = (low + high) / 2;
      ll lmin = mini(l, r, 2*x + 1, low, mid);
      ll rmin = mini(l, r, 2*x + 2, mid, high);

      return min(lmin, rmin) + sumtree[x] ;
    }
    ll mini(int l, int r){
      return mini(l, r, 0, 0, size);
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
      st.add(l,r,v);
    }
    else{
      ll l, r;
      cin>>l >> r;
      cout << st.mini(l, r)<< nl;
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