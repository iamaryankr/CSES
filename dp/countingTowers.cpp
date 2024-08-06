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
const int maxN = 5000000+1;
const int MOD = 1e9+7;
const int N = 1e5+1;
const int INF = 1e9;
const ll INFF = 1e16;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//try thinking Binary search(on ans), Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers, bitmask
//sliding window


//dp on shape
const int mxN = 1e6;
vvll dp(mxN+1, vll(2));


//think of all sub cases 

void solve(){
    int n;
    cin >> n;
    /*dp[i][0] = num of ways to fill up the grid from ith row to 
    top such that there is a 1*2 block on the (i-1)th row trying
    to extend forward */

    /*dp[i][1] = num of ways to fill up the grid from ith row to
    the top such that there are 2 1*1 blocks on the (i-1)th row
    trying to extend forward */

    dp[n][0] = 1;
    dp[n][1] = 1;
    for(int i=n-1; i>=0; i--){
        dp[i][0] = (2LL*dp[i+1][0] + dp[i+1][1])%MOD;
        dp[i][1] = (4LL*dp[i+1][1] + dp[i+1][0])%MOD;
    }

    cout << (dp[1][0]+dp[1][1])%MOD << nl;
}
   
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}