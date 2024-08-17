//iamaryankr
#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define pob pop_back
#define all(x) (x).begin(), (x).end()
#define debugV(v) cout<<#v<<" = [ "; for(int i=0;i<v.size();i++) cout<<v[i]<<' '; cout<<"]"<<nl;
#define debug(x) cout<< #x << " = " << x << endl;
#define debugMat(v) for(int i=0; i<v.size(); i++){ for(int j=0; j<v[0].size(); j++){ cout << v[i][j] << " ";} cout << nl;}
#define fr(i, a, n) for(int i=a; i<n; i++)
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
const string path_grid = "URDL";
bool valid(int i, int j, int n, int m) {return i>=0 && i<n && j<m && j>=0;}

const int MOD = 1e9+7;
const int INF = 1e9;
const ll INFF = 1e18;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//try thinking Binary search(on ans), Bit manipulation, Dp
//jee standard Maths, greedy, Bfs, Dfs, 2 pointers, bitmask
//sliding window


//DONT OVERTHINKKK//


void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    //bfs for monsters
    queue<pii> qm;
    vector<vi> dism(n, vi(m, INF));
    vector<vi> vis(n, vi(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]=='M'){
                qm.push({i, j});
                vis[i][j] = 1;
                dism[i][j] = 0;
            }
        }
    }
    while(!qm.empty()){
        int row = qm.front().first;
        int col = qm.front().second;
        qm.pop();

        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(valid(nrow, ncol, n, m) && !vis[nrow][ncol] && a[nrow][ncol]!='#'){
                dism[nrow][ncol] = dism[row][col] + 1;
                qm.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }

    //bfs for 'A'
    queue<pii> qa;
    vector<vi> disa(n, vi(m, INF));
    vis.assign(n, vi(m, 0));
    vector<vector<pii>> prev(n, vpii(m, {-1, -1}));
    int startRow = -1, startCol = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]=='A'){
                startCol = j, startRow = i;
                qa.push({i, j});
                vis[i][j] = 1;
                disa[i][j] = 0;
                prev[i][j] = {i, j};
                break;
            }
        }
    }

    while(!qa.empty()){
        int row = qa.front().first;
        int col = qa.front().second;
        qa.pop();

        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(valid(nrow, ncol, n, m) && !vis[nrow][ncol] && a[nrow][ncol]!='#'){
                disa[nrow][ncol] = 1 + disa[row][col];
                qa.push({nrow, ncol});
                vis[nrow][ncol] = 1;
                prev[nrow][ncol] = {row, col};
            }
        }
    }
    bool flag = false; // is possible reaching end
    vector<pii> res;
    int endRow = -1, endCol = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 || i==n-1 || j==0 || j==m-1){
                if(disa[i][j] < dism[i][j]){
                    flag = true;
                    endRow = i, endCol = j;
                    pii temp = {i, j};
                    while(prev[i][j] != temp){
                        res.push_back(temp);
                        temp = prev[i][j];
                    }
                    res.push_back(temp);
                    break;
                }
            }
        }
        if(flag) break;
    }
    if(!flag) cout << "NO" <<nl;
    else{
        string ans = "";
        int curRow = endRow, curCol = endCol;
        while(!(curRow==startRow && curCol==startCol)){
            pii p = prev[curRow][curCol];
            int row = p.first, col = p.second;
            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(curCol==ncol && curRow==nrow){
                    ans += (path_grid[i]);
                    break;
                }
            }
            curRow = row;
            curCol = col;
        }
        cout << "YES" << nl;
        cout << ans.size() << nl;
        reverse(all(ans));
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