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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int startRow = -1, startCol = -1;
    int endRow = -1, endCol = -1;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'A') {
                startRow = i;
                startCol = j;
            }
            if (a[i][j] == 'B') {
                endRow = i;
                endCol = j;
            }
        }
    }
    vvi vis(n, vi(m, 0));
    vector<vector<pii>> prev(n, vector<pii>(m, {-1, -1}));
    queue<pii> q;
    vis[startRow][startCol] = 1;
    q.push({startRow, startCol});
    
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
 
            if (valid(nrow, ncol, n, m) && !vis[nrow][ncol] && a[nrow][ncol] != '#') {
                vis[nrow][ncol] = 1;
                prev[nrow][ncol] = {row, col};
                q.push({nrow, ncol});
            }
        }
    }
    if (!vis[endRow][endCol]) {
        cout << "NO" << nl;
    }
    else {
        string ans = "";
        int curRow = endRow, curCol = endCol;
        while (!(curRow == startRow && curCol == startCol)) {
            pii p = prev[curRow][curCol];
            int row = p.first;
            int col = p.second;
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(curRow == nrow && curCol == ncol) {
                    ans += (path_grid[i]);
                    break;
                }
            }
            curRow = row;
            curCol = col;
        }
        cout << "YES" << nl;
        reverse(all(ans));
        cout << ans.size() << nl;
        cout << ans << nl;
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