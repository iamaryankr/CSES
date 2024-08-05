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
#define MP make_pair
 
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


void radix_sort(vector<pair<pii,int>> &a){
    int n = a.size();
    //for second index
    {
        vector<int> cnt(n);
        for(auto x: a){
            cnt[x.first.second] ++;
        }
        vector<pair<pii,int>> a_new(n);
        vector<int> pos(n);
        for(int i=1; i<n; i++){
            pos[i] = pos[i-1]+cnt[i-1];
        }
        for(auto x: a){
            int i = x.first.second;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;
    }
    //for first index
    {
        vector<int> cnt(n);
        for(auto x: a){
            cnt[x.first.first] ++;
        }
        vector<pair<pii,int>> a_new(n);
        vector<int> pos(n);
        for(int i=1; i<n; i++){
            pos[i] = pos[i-1]+cnt[i-1];
        }
        for(auto x: a){
            int i = x.first.first;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;
    }


}
void solve(){
    string s;
    cin>>s;
    s += "$";
    int n = s.size();
    vector<int> p(n), c(n); //ordering and classes respectively

    vector<pair<char, int>> a(n);
    for(int i=0; i<n; i++) a[i] = {s[i], i};
    sort(all(a));
    for(int i=0; i<n; i++) p[i] = a[i].second;
    c[p[0]] = 0;

    for(int i=1; i<n; i++){
        if(a[i].first==a[i-1].first) c[p[i]] = c[p[i-1]];
        else c[p[i]] = c[p[i-1]]+1;
    }
    
    int k = 0;
    //transition
    while((1<<k) < n){
        vector<pair<pair<int,int>, int>> a(n);
        for(int i=0; i<n; i++){
            //because of cyclic %n
            a[i] = {{c[i], c[(i+(1<<k))%n]}, i};
        }
        // sort(all(a));
        radix_sort(a);
        for(int i=0; i<n; i++) p[i] = a[i].second;
        c[p[0]] = 0;

        for(int i=1; i<n; i++){
            if(a[i].first==a[i-1].first) c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]]+1;
        }

        k++;
    }
    for(int i=0; i<n; i++){
        cout << p[i] << " "; 
    }
    cout << nl;
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