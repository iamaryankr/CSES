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
bool valid(int i, int j, int n, int m) {return i>=0 && i<n && j<m && j>=0;}
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

const int mxN = 1e6+1;
vll fact(mxN+1);
vll invfact(mxN+1);

ll binexp(ll a, ll b, const int mod){
    if(b==0) return 1;
    ll res = 1;
    while(b){
        if(b&1) res = res*a%mod;
        b = b/2;
        a = a*a%mod;
    }
    return res%mod;
}
void factorial(const int mod){
    fact[0] = 1;
    for(int i=1; i<=mxN; i++) fact[i] = fact[i-1]*i%mod;
}
void invfactorial(const int mod){
    invfact[mxN] = binexp(fact[mxN], mod-2, mod);
    for(int i=mxN; i>=1; i--) invfact[i-1] = invfact[i]*i%mod;
}
ll nCr(ll n, ll r, const int mod){
    return (fact[n]*invfact[r]%mod * invfact[n-r]%mod);
}
void solve(){
    ll n, r;
    cin >> n >> r;

    cout << nCr(n, r, MOD) << nl;
}
   
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cout << setprecision(12) << fixed;

    factorial(MOD);
    invfactorial(MOD);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
