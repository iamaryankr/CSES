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


class segTree {
public:
    int size = 1;
    vector<ll> tree;

    segTree(int n) {
        while (size < n) {
            size *= 2;
        }
        tree.resize(2 * size);
    }

    void add(int x, int low, int high, int l, int r, ll v) {
      if (low >= r || high <= l) return ;
      if (low >= l && high <= r){
        tree[x] = max(tree[x], v);
        return;
      }

      int mid = (low + high) / 2;
      add(2*x + 1, low, mid, l, r, v);
      add(2*x + 2, mid, high, l, r, v);
    }

    void add(int l, int r, ll v) {
      add(0, 0, size, l, r, v);
    }


    ll get(int i, int x, int low, int high){
      if(high-low == 1) return tree[x];
      
      int mid = (low + high) / 2;
      ll res ;
      if (i < mid) res = get(i, 2*x + 1, low, mid);
      else res = get(i, 2*x + 2, mid, high);

      return max(res , tree[x]);
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
      st.add(l,r,v);
    }
    else{
      int i;
      cin>>i;
      cout << st.get(i) << nl;
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
