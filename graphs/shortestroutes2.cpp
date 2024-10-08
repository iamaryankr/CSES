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
 
int gcd(int a, int b){ return (b ? gcd(b, a % b) : a);}
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vll> dist(n, vll(n, INFF));

    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        dist[u][v] = min(dist[u][v], (ll)w);
        dist[v][u] = min(dist[v][u], (ll)w);
    }
    for(int i=0; i<n; i++) dist[i][i] = 0;

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][k] != INFF && dist[k][j] != INFF){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    while(q--){
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << (dist[u][v]==INFF ? -1 : dist[u][v]) << nl;
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