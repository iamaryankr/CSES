//iamaryankr
#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define pob pop_back
#define sq(x) x*x
#define cube(x) x*x*x
 
typedef long double ld;
typedef long long ll;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vi;
 
 

//normal dijkstra's algorithm

void solve(){
   ll n,m;
   cin>>n>>m;
 
   ll a, b, c;
   vector<pair<ll,ll>> adj[n+1];
 
   for(int i=0; i<m; i++){
      cin>>a>>b>>c;
      adj[a].pb({b, c});
   }
   vector<ll> dist(n+1, 1e17);
   priority_queue<pair<ll,ll>, 
   vector<pair<ll,ll>>, 
   greater<pair<ll,ll>>> pq;
 
   pq.push({0, 1});
   dist[1] = 0;
   while(!pq.empty()){
      auto it = pq.top();
      ll node = it.second;
      ll wt = it.first;
      pq.pop();
      if(wt > dist[node]) continue;
 
      for(auto it: adj[node]){
         ll adjNode = it.first;
         ll edwt = it.second;
         if(dist[adjNode] > wt + edwt){
            dist[adjNode] = wt + edwt;
            pq.push({wt+edwt, adjNode});
         }
         else continue;
      }
   }
   for(int i=1; i<=n; i++) cout<<dist[i]<<" ";
}
 
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
 
   int t = 1;
   //cin>>t;
   while(t--){
        solve();
   }
   return 0;
}