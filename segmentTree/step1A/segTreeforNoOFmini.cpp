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


class Node{
public:
  ll mini = INFF, cnt = 0;
};

class Segtree{
public:
  int size = 1;
  vector<Node> values;
  Node NA = {INFF, 0};
  Segtree(int n){
    while(size < n) size*=2;
    values.resize(size*2);
  }
  Node apply_op(Node a, Node b){
    if(a.mini > b.mini){
      return {b.mini, b.cnt};
    }
    else if(a.mini == b.mini){
      return {a.mini, a.cnt + b.cnt};
    }
    return {a.mini, a.cnt};
  }
  Node make_ele(ll a){
    return {a, 1};
  }
  void build(int x, int low, int high, vector<int> &a){
    if(low + 1 == high){
      if(low < int(a.size())) values[x] = make_ele(a[low]);
      return;
    }
    int mid = (low + high)>>1;
    build(2*x + 1, low, mid, a);
    build(2*x + 2, mid, high, a);
    values[x] = apply_op(values[2*x + 1] , values[2*x + 2]);
  }
  void build(vector<int> &a){
    build(0, 0, size, a);
  }

  void set(int x, int i, int v, int low, int high){
    if(low + 1 == high){
      values[x] = make_ele(v);
      return;
    }
    int mid = (low + high)>>1;
    if(i < mid) set(2*x + 1, i, v, low, mid);
    else set(2*x + 2, i, v, mid, high);

    values[x] = apply_op(values[2*x + 1] , values[2*x + 2]);
  }
  void set(int i, int v){
    set(0, i, v, 0, size);
  }

  Node calc(int x, int l, int r, int low, int high){
    if(low >= r || high <= l) return NA;
    if(low >= l && high <= r) return values[x];
    
    int mid = (low + high) >> 1;
    Node left = calc(2*x + 1, l, r, low, mid);
    Node right = calc(2*x + 2, l, r, mid, high);
    return apply_op(left, right); 
  }
  Node calc(int l, int r){
    return calc(0, l, r, 0, size);
  }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    for(int i=0; i<n ;i++) cin >> a[i];
    Segtree st(n);
    st.build(a);

    while(m--){
        int op;
        cin >> op;
        if(op==1){
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else if(op==2){
            int l, r;
            cin >> l >> r;
            cout << st.calc(l, r).mini << " " << st.calc(l, r).cnt <<nl;
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