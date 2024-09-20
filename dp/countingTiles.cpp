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


//dp on bitMask 
const int mxN = 1e3;
int dp[mxN+1][1<<11];

void generate_next_masks(int current_mask, int row, int next_mask, int n, vector<int>& next_masks){
  if(row == n){
    next_masks.push_back(next_mask);
    return;
  }
  
  if((current_mask & (1 << row)) != 0)
    generate_next_masks(current_mask, row + 1, next_mask, n, next_masks);
  
  if(row != n-1 && (current_mask & (1 << row)) == 0 && (current_mask & (1 << (row+1))) == 0)
    generate_next_masks(current_mask, row + 2, next_mask, n, next_masks);      
  
  if((current_mask & (1 << row)) == 0)
    generate_next_masks(current_mask, row + 1, next_mask + (1 << row), n, next_masks);    
}
int memo(int col, int mask , int m, int n){
  if(col == m){// BASE CASE
    return mask == 0;
  }

  if(dp[col][mask] != -1)
    return dp[col][mask];

  vector<int> next_masks;
  generate_next_masks(mask, 0, 0, n, next_masks);

  int ans = 0;
  for(int next_mask: next_masks){
    ans = (ans + memo(col + 1, next_mask, m, n)) % MOD;
  }

  return dp[col][mask] = ans;
}
void solve(){
  int n, m;
  cin >> n >> m;
  //dp(i, mask) -> no of ways to fill from ith to mth col
  //given that some positions are already filled
  memset(dp, -1, sizeof(dp));
  cout << memo(0, 0, m, n) << nl;
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
