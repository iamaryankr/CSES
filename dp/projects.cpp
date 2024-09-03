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

class project{
  public:
    int start, end, money;
};
void solve(){
  int n;
  cin >> n;

  vector<project> p(n+1);
  for(int i=1; i<=n; i++){
    cin >> p[i].start >> p[i].end >> p[i].money;
  }

  sort(all(p), [&](const project &a, const project &b){
    return a.end < b.end ;
  });
  vector<int> endDays(n+1);
  for(int i=1; i<=n; i++) endDays[i] = p[i].end;

  vector<ll> dp(n+1, 0);
  //dp(i) is the max money till the day i

  for(int i=1; i<=n; i++){
    auto it = lower_bound(all(endDays), p[i].start);
    int j = (it - endDays.begin()) - 1;

    ll nottake = dp[i-1];
    ll take = p[i].money + dp[j]; // take the project that ends fastest

    dp[i] = max(nottake, take);
  }

  cout << dp[n] << nl;
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
