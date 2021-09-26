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
#define M 1000000007
#define ll long long
#define ld long double
#define vt vector
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define each(x, a) for (auto& x: a)
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(a)-1;i>=int(b);i--)
#define gne(i,a,b) for(int i=int(a);i>int(b);i--)
#define per(i,b) gnr(i,0,b)
#define FAST1 ios::sync_with_stdio(0);
#define FAST2 cin.tie(0);
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

vt<ll> nums,st;

void build(int v,int l,int r){
    if(l == r) st[v] = nums[l];
    else{
        int m = l + ((r - l) / 2);
        build(v*2,l,m), build(v*2+1,m+1,r);
        st[v] = st[v*2] + st[v* 2+1];
    }
}

void upd(int v,int l,int r,int x,int val){
    if(l == r) st[v] = val;
    else{
        int m = l + ((r - l) / 2);
        if(x <= m) upd(v*2,l,m,x,val);
        else upd(v*2+1,m+1,r,x,val);
        st[v] = st[v*2] + st[v*2+1];
    }
}

ll getSum(int v,int l,int r,int ql, int qr){
    if(r < ql || l > qr) return 0;
    if(l >= ql && r <= qr) return st[v];
    int m = l + ((r - l) / 2);
    ll left = getSum(v*2,l,m,ql,qr);
    ll right = getSum(v*2+1,m+1,r,ql,qr);
    return left + right;
}

void solve(){
    int n,q;cin>>n>>q;
    nums = vt<ll>(n), st = vt<ll>(4*n+1);
    rep(i,n) cin>>nums[i];
    build(1,0,n-1);
    rep(i,q){
        int qt,x,y;cin>>qt>>x>>y;
        if(qt == 1) upd(1,0,n-1,x-1,y);
        else cout<<getSum(1,0,n-1,x-1,y-1)<<'\n';
    }
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
    //cin>>t;
    while(t--){
        solve();
    }
    cerr<<'\n'<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<'\n';
    return 0;
}