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
 
int delrow[] = {-1};
int delcol[] = {0, -1};
const string path_grid = "URDL";
bool valid(int i, int j, int n, int m) {return i>=0 && i<n && j<m && j>=0;}

const int MOD = 1e9+7;
const int INF = 1e9;
const ll INFF = 1e18;
 
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
//try thinking Binary search(on ans), Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers 
//sliding window
 
 
//DONT OVERTHINKKK 

//general seg values template use

// class int{
// public:
//   int open, close, full;
// };
class segvalues{
public:
  int size = 1;
  vector<int> values;
  int neutral_ele = 0;
  //constructor
  segvalues(int n){
    while(size < n) size*= 2;
    values.resize(2*size);
  }

  //merge function for child nodes to get ans for parent
  int merge(int a, int b){
    return a+b;
  }
  //assigning int to a node val
  int make_int(int ind, int val){
    if(ind&1) return -val;
    return val;
  }
  
  //building the values with the vector a
  void build(int node, int low, int high, vi& a){
    if(low+1 == high){
        if(low < int(a.size()) ) values[node] = make_int(low, a[low]);
        return;
    }
    int mid = (low+high)>>1;
    build(2*node+1, low, mid, a);
    build(2*node+2, mid, high, a);
    values[node] = merge(values[2*node+1], values[2*node+2]);
  }
  void build(vi &a){
    build(0, 0, size, a);
  }
  //updating
  void update(int x, int low, int high,int i, int v){
    if(high-low == 1){
      values[x] = make_int(i, v);
      return; 
    }
    int mid = (low+high)>>1 ;
    if(i < mid) update(2*x+1, low, mid, i, v);
    else update(2*x+2, mid, high, i, v);
 
    values[x] = merge(values[2*x+1] , values[2*x+2]);
  }
  void update(int i, int v){
    update(0, 0, size, i, v);
  }
  //building the calc function
  int calc(int l, int r, int node, int low, int high){
        if(low>=r || high<=l) return neutral_ele;
        if(low>=l && high<=r) return values[node];

        int mid = (low+high)>>1;
        int left = calc(l, r, 2*node+1, low, mid);
        int right = calc(l, r, 2*node+2, mid, high);
        return merge(left, right);
    }
    int calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }
};
void solve(){
    int n, m;
    cin >> n;
    vi a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    segvalues st(n);
    st.build(a);
    
    cin >> m;
    while(m--){
        int op;
        cin >> op;
        if(op==0){
            int i, v;
            cin >> i >> v;
            i--;
            st.update(i, v);
        }
        else if(op==1){
            int l, r;
            cin >> l >> r;
            l--;
            cout << st.calc(l, r)*(l&1 ? -1 : 1) << nl;
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