//iamaryankr
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pob pop_back
#define sq(x) x*x
#define cube(x) x*x*x
#define all(x) (x).begin(), (x).end()
#define debugV(v) for(int i=0;i<v.size();i++) cout<<v[i]<<' '; cout<<endl;
#define debug(x) cout<< #x << " = " << x << endl;
#define debugMat(v) for(int i=0; i<v.size(); i++){ for(int j=0; j<v[0].size(); j++){ cout << v[i][j] << " ";} cout << nl;}
#define nl "\n"
#define ff first;
#define ss second;

typedef long double ld;
typedef long long ll;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int gcd(int a, int b){ return (b ? gcd(b, a % b) : a); }
int lcm(int a, int b){ return (a*b/gcd(a,b)); }

int delrow[] = {-1, 0, 1, 0};
int delcol[] = {0, 1, 0, -1};

const int maxN = 5000000+1;
const int MOD = 1e9+7;
const int N = 2e5+1;

//try thinking Binary search, Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs



// 5 5 6 
//if 0 at borders, simple case
//else
//for adj elements on each side
// abs==1 , abs==0, abs==2
//abs==0, 3 possible ans, check in range of m
//abs==1, 2 possible ans, no need to check
//abs==2, 1 ans only, no need to check


const int mxN = 1e5+2;
const int mxM = 1e2+2;
int dp[mxN][mxM];

bool validx(int x, int m){
    return x>=1 && x<=m;
}
void solve(){
    int n, m;
    cin >> n >> m;
    vi a(n);
    for(int i=0; i<n ; i++) cin >> a[i];

    memset(dp, 0, sizeof dp);
    //dp(i, x); is the number of ways to make array till ith ind
    //s.t. last element is x;

    //base case of 1 sized array
    for(int x=1; x<=m; x++){
        if(a[0]==0 || a[0]==x) dp[1][x] = 1;
    }

    for(int i=2; i<=n; i++){
        for(int x=1; x<=m; x++){
            if(a[i-1]==0 || a[i-1]==x){
                // 3 possibilities to fill the element where 0
                if(validx(x-1, m)) dp[i][x] = (dp[i][x] + dp[i-1][x-1])%MOD;
                if(validx(x, m)) dp[i][x] = (dp[i][x] + dp[i-1][x])%MOD;
                if(validx(x+1, m)) dp[i][x] = (dp[i][x] + dp[i-1][x+1])%MOD;
            }
        }
    }

    int ans = 0;
    for(int x=1; x<=m; x++){
        ans = (ans + dp[n][x])%MOD;
    }
    cout << ans << nl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}