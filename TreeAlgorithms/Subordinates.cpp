#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
using namespace std;

#define INF 1e9+5
#define MOD 1000000007
#define ll long long
#define ld long double
#define vt vector
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define len(x) (int)(x).length()
#define each(x, a) for (auto& x: a)
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(a)-1;i>=int(b);i--)
#define gne(i,a,b) for(int i=int(a);i>int(b);i--)
#define per(i,b) gnr(i,0,b)
#define IOS ios::sync_with_stdio(0);cin.tie(0);
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

class UnionFind{
    public:
    vt<int> parent,rank;
    UnionFind(int n){
        parent.resize(n), rank.resize(n,1);
        iota(parent.begin(),parent.end(),0);
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void unify(int u,int v){
        u = find(u), v = find(v);
        if(u != v){
            if(rank[u] < rank[v]) swap(u,v);
            parent[u] = v;
            if(rank[u] == rank[v]) rank[v]++;
        }
    }
};

void solve(){
    int n;cin>>n;
    vt<int> nums(n);
    rng(i,1,n) cin>>nums[i], nums[i]--;
    UnionFind dsu(n);
    each(i,nums) dsu.unify(i+1,nums[i]);
    each(i,dsu.rank) cout<<i<<' ';
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "a", stderr);
    #endif
    IOS
    
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    cerr<<'\n'<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<'\n';
    return 0;
}