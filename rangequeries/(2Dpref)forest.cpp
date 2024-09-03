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
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers, bitmask
//sliding window

void solve(){
    int n;
	int qr;
	cin >> n >> qr;
    vector<vector<int>> a(n+1, vector<int> (n+1));
    vector<vector<int>> pref(n+1, vector<int> (n+1, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			a[i+1][j+1] += (c == '*');
		}
	}
	// build the prefix sum array
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			pref[i][j] = a[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
		}
	}
	for (int q = 0; q < qr; q++) {
		int row1, row2, col1, col2;
		cin >> row1 >> col1 >> row2 >> col2;
		cout << pref[row2][col2] - pref[row1 - 1][col2] - pref[row2][col1 - 1] +
		    pref[row1 - 1][col1 - 1]<< nl;

	}
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