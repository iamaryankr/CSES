//iamaryankr
#include<bits/stdc++.h>
using namespace std;

// #define pb push_back
#define pob pop_back
#define sq(x) x*x
#define cube(x) x*x*x
#define all(x) (x).begin(), (x).end()
#define debugV(v) for(int i=0;i<v.size();i++) cout<<v[i]<<' '; cout<<endl;
#define debug(x) cout<< #x << " = " << x << endl;
#define debugMat(v) for(int i=0; i<v.size(); i++){ for(int j=0; j<v[0].size(); j++){ cout << v[i][j] << " ";} cout << nl;}
#define nl "\n"

typedef long double ld;
typedef long long ll;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vi;

int gcd(int a, int b){ return (b ? gcd(b, a % b) : a); }
int lcm(int a, int b){ return (a*b/gcd(a,b)); }

int delrow[] = {-1, 0, 1, 0};
int delcol[] = {0, 1, 0, -1};

const int maxN = 5000000+1;
const int MOD = 1e9+7;
const int N = 2e5+1;


//

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for(int i=1; i<=x; i++){
        for(int j=0; j<n; j++){
            if(a[j]<=i) dp[i] = (dp[i]+dp[i-a[j]])%MOD;
        }
    }
    cout << dp[x] << nl;
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