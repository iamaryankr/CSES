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

//general seg tree template use

string s;
class item{
public:
  int open, close, full;
};
class segTree{
public:
  int size = 1;
  vector<item> values;
  item neutral_ele = {0, 0, 0};
  //constructor
  segTree(int n){
    while(size < n) size*= 2;
    values.resize(2*size);
  }

  //merge function for child nodes to get ans for parent
  item merge(item a, item b){
    int f = a.full + b.full + min(a.open, b.close);
    int o = a.open + b.open - min(a.open, b.close);
    int c = a.close + b.close - min(a.open, b.close);
    return {o, c, f};
  }
  //assigning int to a node val
  item make_int(int ind){
    int o = (s[ind]=='(');
    int c = (s[ind]==')');
    int f = 0;
    return {o, c, f};
  }
  
  //building the tree with the vector a
  void build(int node, int low, int high){
    if(low+1 == high){
        if(low < int(s.size()) ) values[node] = make_int(low);
        return;
    }
    int mid = (low+high)>>1;
    build(2*node+1, low, mid);
    build(2*node+2, mid, high);
    values[node] = merge(values[2*node+1], values[2*node+2]);
  }
  void build(){
    build(0, 0, size);
  }

  //building the calc function
  item calc(int l, int r, int node, int low, int high){
        if(low>=r || high<=l) return neutral_ele;
        if(low>=l && high<=r) return values[node];

        int mid = (low+high)>>1;
        item left = calc(l, r, 2*node+1, low, mid);
        item right = calc(l, r, 2*node+2, mid, high);
        return merge(left, right);
    }
    item calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }
};
void solve(){
  cin >> s;
  int m;
  cin >> m;
  int n = s.size();
  segTree st(n);
  st.build();
  while(m--){
    int l, r;
    cin >> l >> r;
    l--;
    cout << 2*(st.calc(l, r).full) << nl;
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