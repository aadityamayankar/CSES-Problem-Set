/*

~~~~~~~~~~~~~~https://cses.fi/user/72443~~~~~~~~~~~~~~

Question: https://cses.fi/problemset/task/1651/
Submission: https://cses.fi/paste/76ca6cb8386b77152e7242/
*/

#include <bits/stdc++.h>
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast")
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
#define FASTIO ios::sync_with_stdio(0);cin.tie(0);
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

vt<ll> nums,st;

void build(int v,int l,int r){
    if(l == r) st[v] = nums[l];
    else{
        int m = l + ((r - l) >> 1);
        build(v*2,l,m), build(v*2+1,m+1,r);
        st[v] = 0;
    }
}

void update(int v,int l,int r,int ql,int qr,ll val){
    if(r < ql || l > qr) return;
    if(l == ql && r == qr) st[v] += val;
    else{
        int m = l + ((r - l) >> 1);
        update(v*2,l,m,ql,min(qr,m),val), update(v*2+1,m+1,r,max(ql,m+1),qr,val);
    }
}

ll get(int v,int l,int r,int i){
    if(l == r) return st[v];
    int m = l + ((r - l) >> 1);
    if(i <= m) return st[v] + get(v*2,l,m,i);
    return st[v] + get(v*2+1,m+1,r,i);
}

void solve(){
    int n,q;cin>>n>>q;
    nums = vt<ll>(n), st = vt<ll>(4*n+1);
    rep(i,n) cin>>nums[i];
    build(1,0,n-1);
    while(q--){
        int x;cin>>x;
        if(x == 1){
            int a,b;cin>>a>>b;
            ll u;cin>>u;
            update(1,0,n-1,a-1,b-1,u);
        }
        else{
            int i;cin>>i;
            cout<<get(1,0,n-1,i-1)<<'\n';
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "a", stderr);
    #endif
    FASTIO
    
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    cerr<<'\n'<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<'\n';
    return 0;
}