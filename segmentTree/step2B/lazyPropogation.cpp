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

//using lazy propogation for a non commutative property

//assigning (v) to a segment(l, r);
class segTree {
public:
    int size = 1;
    ll no_operation = LLONG_MAX;
    vector<ll> tree;

    segTree(int n) {
        while (size < n) {
            size *= 2;
        }
        tree.resize(2 * size);
    }
    
    ll operation(ll a, ll b){
      //operation b to a
      if(b==no_operation) return a;
      return b;
    }
    void applyOperation(ll &a, ll b){
      a = operation(a,b);
    }
    void propogate(int x, int low, int high){
      if(high-low==1) return;
      applyOperation(tree[2*x+1], tree[x]);
      applyOperation(tree[2*x+2], tree[x]);

      tree[x] = no_operation;
    }

    void modify(int x, int low, int high, int l, int r, ll v) {
      propogate(x, low, high);

      if (low >= r || high <= l) return ;
      if (low >= l && high <= r){
        applyOperation(tree[x], v);
        return;
      }

      int mid = (low + high) / 2;
      modify(2*x + 1, low, mid, l, r, v);
      modify(2*x + 2, mid, high, l, r, v);
    }

    void modify(int l, int r, ll v) {
      modify(0, 0, size, l, r, v);
    }


    ll get(int i, int x, int low, int high){
      propogate(x, low, high);
      if(high-low == 1) return tree[x];
      
      int mid = (low + high) / 2;
      ll res ;
      if (i < mid) res = get(i, 2*x + 1, low, mid);
      else res = get(i, 2*x + 2, mid, high);

      return res;
    }
    ll get(int i){
      return get(i, 0, 0, size);
    }
};

void solve() {
  int n,m;
  cin>>n>>m;
  segTree st(n);
  while(m--){
    int op;
    cin>>op;
    if(op==1){
      int l,r,v;
      cin>>l>>r>>v;
      st.modify(l,r,v);
    }
    else{
      int i;
      cin>>i;
      cout << st.get(i) << nl;
    }
  }
}