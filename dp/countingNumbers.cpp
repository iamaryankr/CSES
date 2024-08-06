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

const int MOD = 1e9+7;
const int INF = 1e9;
const ll INFF = 1e16;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//try thinking Binary search(on ans), Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers, bitmask
//sliding window


//dp on digits

//dp[n][x][leading_zeros][tight] = num of ways to generate a number
//of 'n' digits such that leading digit in not 'x', and can have
//multiple leading zeroes only if 'leading_zeros'=true and must follow
//constraints imposed by c only if 'tight'=true

ll dp[19][10][2][2];

ll func(string& number, int n, int x, bool leading_zeroes, bool tight){
    if(n==0) return 1;
    if(x!=-1 && dp[n][x][leading_zeroes][tight]!=-1) return dp[n][x][leading_zeroes][tight];

    ll lb = 0;
    ll ub = (tight==false) ? 9 : (number[number.size()-n]-'0');

    ll ans = 0;
    for(int dig=lb; dig<=ub; dig++){
        if(dig==x && leading_zeroes==0) continue;
        ans += func(number, n-1, dig, leading_zeroes&(dig==0), tight&(dig==ub));
    }
    return dp[n][x][leading_zeroes][tight] = ans;
}

void solve(){
    string a, b;
    cin >> a >> b;
    //change a to a-1
    ll x = stoll(a);
    a = to_string(x-1);

    memset(dp, -1, sizeof dp);
    ll ans1 = func(b, b.size(), -1, true, true);

    memset(dp, -1, sizeof dp);
    ll ans2 = func(a, a.size(), -1, true, true);

    cout << (ans1-ans2) << nl;
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