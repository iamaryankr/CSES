//iamaryankr
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pob pop_back
#define sq(x) x*x
#define cube(x) x*x*x
#define all(x) (x).begin(), (x).end()


typedef long double ld;
typedef long long ll;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vi;

const int maxN = 1e6;
const int MOD = 1e9+7;
/*
   1,2,3,4,5,6

*/
vector<int> dp(maxN+1, -1);
int rec(int n){
   if(dp[n]!=-1) return dp[n];
   if(n==0 || n==1){
      return 1;
   }
   int ans = 0;
   for(int i=1; i<=6; i++){
     if(n >= i) ans = (ans + rec(n-i))%MOD;
   } 
   return dp[n] = ans;
}

void solve(){
   int n;
   cin>>n;

   cout<<rec(n);
}


int main() {
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   //cout << setprecision(12) << fixed;

   int t = 1;
   //cin>>t;
   while(t--){
      solve();
   }
   return 0;
}