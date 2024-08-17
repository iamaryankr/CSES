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

const int mxX = (1<<20) + 1 ;
int dp[mxX][2];

pii solve(int mask, const vi& w, int x) {
    if (mask == 0) {
        return {1, 0};
    }
    if (dp[mask][0] != -1) {
        return {dp[mask][0], dp[mask][1]};
    }

    pii result = {INF, 0};
    for (int i = 0; i < (int)w.size(); i++) {
        if (mask & (1 << i)) {
            pii canHave = solve(mask ^ (1 << i), w, x);
            if (canHave.second + w[i] <= x) {
                canHave.second += w[i];
            } else {
                canHave.first++;
                canHave.second = w[i];
            }
            result = min(result, canHave);
        }
    }

    dp[mask][0] = result.first;
    dp[mask][1] = result.second;
    return result;
}
void solve(){
  int n, x;
    cin >> n >> x;
    vi w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    // Initialize dp array
    for (int i = 0; i <= (1 << n); i++) {
        dp[i][0] = dp[i][1] = -1;
    }

    pii result = solve((1 << n) - 1, w, x);
    cout << result.first << endl;
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