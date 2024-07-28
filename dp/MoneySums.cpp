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
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl

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
bool valid(int i, int j, int n, int m) {return i>=0 && i<n && j<m && j>=0;}
const int maxN = 5000000+1;
const int MOD = 1e9+7;
const int N = 1e5+1;
const int INF = 1e9;


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//try thinking Binary search, Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers 
//sliding window

//

void solve(){
    int n;
    cin>>n;
    vi x(n);
    for(int i=0; i<n ;i++) cin>>x[i];

    //dp[i][x] = true if it is possible to make x 
    //using the first i coins, false otherwise.
    vector<vector<bool>> dp(n+1, vector<bool> (N, false));
    dp[0][0] = true;
    for(int i=1; i<=n ;i++){
        for(int j=0; j<=N; j++){
            dp[i][j] = dp[i-1][j];
            int left = j - x[i-1];
            if(left>=0 && dp[i-1][left]) dp[i][j] = true;
        }
    }
    vector<int> sums;
    for(int j=1; j<=N; j++){
        if(dp[n][j]) sums.push_back(j);
    }
    cout << sums.size() << nl;
    for(auto it: sums) cout << it << " " ;
    cout <<nl;

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