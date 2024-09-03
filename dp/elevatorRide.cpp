//iamaryankr
#include<bits/stdc++.h>
using namespace std; 

#define pb push_back
#define pob pop_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define stprc cout << setprecision(12) << fixed
#define debugV(v) cout<<#v<<" = [ "; for(int i=0;i<v.size();i++) cout<<v[i]<<' '; cout<<"]"<<nl;
#define debug(x) cout<< #x << " = " << x << endl;
#define debugMat(v) for(int i=0; i<v.size(); i++){ for(int j=0; j<v[0].size(); j++){ cout << v[i][j] << " ";} cout << nl;}
#define fr(i, a, n) for(int i=a; i<n; i++)
#define nl "\n"
#define ff first
#define ss second
#define yes cout<<"YES"<< nl
#define no cout<<"NO"<< nl

typedef long long ll;
typedef long double ld;
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
 

//try thinking Binary search(on ans), Bit manipulation,
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers 
//sliding window, Topo sort, dijkstra..
//Dp, Dp, Dp, Dp

//-------------------------------------main-code-------------------------------------------------------------------------------------------------------------------------------------------------------


const int mxX = (1<<20) + 1 ;
pii dp[mxX];

//dp[X]={k,W}, where 
//k= minimum number of rides needed for X (just like before) 
//and W= minimum weight on the last elevator ride given that k is minimum

pii dfs(int mask, const vi& w, int x) {
  if (mask == 0) {
    return {1, 0};
  }
  if (dp[mask].first != -1) {
    return dp[mask];
  }

  pii result = {INF, 0};
  for (int i = 0; i < (int)w.size(); i++) {
    if (mask & (1 << i)) {
      pii canHave = dfs(mask ^ (1 << i), w, x);
      if (canHave.second + w[i] <= x) { //if the person's weight is in the limit
        canHave.second += w[i];
      }
      else{ //now the person out of weight limit will req another ride
        canHave.first++;
        canHave.second = w[i]; //weight for the next ride
      }
      result = min(result, canHave);
    }
  }

  dp[mask] = result;
  return dp[mask];
}
void solve(){
  int n, x;
  cin >> n >> x;
  vi w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }

  // Initialize dp array
  for(int i=0; i<(1<<n); i++) dp[i] = {-1, -1};

  pii result = dfs((1 << n) - 1, w, x);
  cout << result.first << endl;
}


//DONT OVERTHINKKK 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0; 
}
