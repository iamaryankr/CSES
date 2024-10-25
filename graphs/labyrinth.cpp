//iamaryankr
#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define pob pop_back
#define all(x) (x).begin(), (x).end()
#define debugV(v) for(int i=0;i<v.size();i++) cout<<v[i]<<' '; cout<<endl;
#define debug(x) cout<< #x << " = " << x << endl;
#define debugMat(v) for(int i=0; i<v.size(); i++){ for(int j=0; j<v[0].size(); j++){ cout << v[i][j] << " ";} cout << nl;}
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
typedef vector<pair<ll, ll>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef map<int,int> mii;
 
int gcd(int a, int b){ return (b ? gcd(b, a % b) : a); }
int lcm(int a, int b){ return (a*b/gcd(a,b)); }
 
int delrow[] = {-1, 0, 1, 0};
int delcol[] = {0, 1, 0, -1};
string path_grid = "URDL";
bool valid(int i, int j, int n, int m) {return (i>=0 && i<n && j>=0 && j<m); }
 
const int maxN = 5000000+1;
const int MOD = 1e9+7;
const int N = 1e5+1;
const int INF = 1e9;
const ll INFF = 1e16;
 
 
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
//try thinking Binary search(on ans), Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers 
//sliding window
 
 
//DONT OVERTHINKKK 
 
 
void solve(){
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for(int i=0; i<n; i++) cin >> grid[i];

  vvi vis(n, vi(m, 0));
  queue<pii> q;
  pii target;
  pii start;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(grid[i][j] == 'A'){
        start = {i, j};
        q.push({i, j});
      }
      if(grid[i][j] == 'B'){
        target = {i, j};
      }
    }
  }
  vector<vector<pii>> prev(n, vector<pii> (m, {-1, -1}));

  while(!q.empty()){
    int row = q.front().first, col = q.front().second;
    q.pop();

    for(int i=0; i<4; i++){
      int nrow = row + delrow[i];
      int ncol = col + delcol[i];
      if(valid(nrow, ncol, n, m) && grid[nrow][ncol] != '#' && !vis[nrow][ncol]){
        vis[nrow][ncol] = 1;
        prev[nrow][ncol] = {row, col};
        q.push({nrow, ncol});
      }
    }
  }
  if(vis[target.first][target.second] == 0) cout << "NO" << nl;
  else{
    cout << "YES" << nl;
    string ans = "";
    int currow = target.first, curcol = target.second;
    while(!(currow == start.first && curcol == start.second)){
      int prevrow = prev[currow][curcol].first;
      int prevcol = prev[currow][curcol].second;
      for(int i=0; i<4; i++){
        if(currow == prevrow + delrow[i] && curcol == prevcol + delcol[i]){
          ans.push_back(path_grid[i]);
        }
      }
      currow = prevrow, curcol = prevcol;
    }
    reverse(all(ans));
    cout << int(ans.size()) << nl;
    cout << ans << nl;
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