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


//Multisource BFS from all the monsters

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    for(int i=0; i<n ;i++){
        cin>>a[i];
    }
    
    //for MONSTERS
    queue<pair<int,int>> q;
    vector<vector<int>> vis(n, vector<int> (m, 0));
    vector<vector<int>> dist(n, vector<int> (m, INF));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]=='M'){
               q.push({i, j});
               dist[i][j] = 0;
               vis[i][j] = 1;
            }
        }
    }
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(valid(nrow, ncol, n, m) && !vis[nrow][ncol]
            && a[nrow][ncol]!='#'){
                dist[nrow][ncol] = dist[row][col]+1;
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }

    //for A
    vector<vector<int>> distA(n, vector<int> (m, INF));
    vector<vector<int>> visA(n, vector<int> (m, 0));
    queue<pair<int,int>> qA;
    map<pair<int,int>, pair<int,int>> par;//for parents
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]=='A'){
                qA.push({i, j});
                distA[i][j] = 0;
                visA[i][j] = 1;
                par[{i, j}] = {i, j};
                break;
            }
        }
    }
    while(!qA.empty()){
        int row = qA.front().first;
        int col = qA.front().second;
        qA.pop();
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i]; 
            if(valid(nrow, ncol, n, m) && !visA[nrow][ncol]
            && a[nrow][ncol]!='#'){
                distA[nrow][ncol] = distA[row][col]+1;
                visA[nrow][ncol] = 1;
                qA.push({nrow, ncol});
                par[{nrow,ncol}] = {row, col};
            }
        }
    }
    vector<pair<int,int>> res;
    bool flag = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 || i==n-1 || j==0 || j==m-1){
                if(distA[i][j] < dist[i][j]){
                    pair<int,int> temp = {i, j};
                    while(par[temp]!=temp){
                        res.push_back(temp);
                        temp = par[temp];
                    }
                    res.push_back(temp);
                    flag = false;
                    break;
                }
            }
        }
        if(!flag) break;
    }
    if(flag){
        cout << "NO" <<nl;
        return;
    }
    else{
        cout << "YES" <<nl;
        int sz = res.size();
        cout << sz-1 << nl;
        reverse(all(res));
        for(int i=0; i<sz-1; i++){
            pair<int,int> a1 = res[i];
            pair<int,int> a2 = res[i+1];
            if(a1.second+1 == a2.second) cout << 'R';
            else if(a1.second-1 == a2.second) cout<<'L';
            else if(a1.first-1 == a2.first) cout<<'U';
            else cout<<'D';
        }
        cout << nl;
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