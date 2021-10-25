#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

#define ll long long
#define vt vector
#define each(x, a) for (auto& x: a)
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define FAST1 ios::sync_with_stdio(0);
#define FAST2 cin.tie(0);
 
const ll inf = 1ll << 60;
 
vt<ll> bellman_ford(vt<vt<ll>> edges,int n){
    vt<ll> dist(n+1,inf);
    dist[1] = 0LL;
    rep(i,n-1){
        each(edge,edges){
            ll u = edge[0], v = edge[1], w = edge[2];
            ll value = dist[u] + w;
            if(dist[u] == inf) value = inf;
            if(value < dist[v]) dist[v] = dist[u] + w;
        }
    }
    rep(i,n-1){
        each(edge,edges){
            ll u = edge[0], v = edge[1], w = edge[2];
            ll value = dist[u] + w;
            if(dist[u] == inf) value = inf;
            if(value < dist[v]) dist[v] = -inf;
        }
    }
    return dist;
}
 
void solve(){
    int n,m;cin>>n>>m;
    vt<vt<ll>> edges(m);
    rep(i,m){
        int u,v,w;cin>>u>>v>>w;
        edges[i] = {u,v,-w};
    }
    vt<ll> dist = bellman_ford(edges,n);
    ll res = dist[n] == -inf ? -1 : -dist[n];
    cout<<res<<'\n';
}
 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "a", stderr);
    #endif
    FAST1
    FAST2
    
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    cerr<<'\n'<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<'\n';
    return 0;
}