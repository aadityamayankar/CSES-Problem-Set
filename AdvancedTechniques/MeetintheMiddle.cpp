/*

~~~~~~~~~~~~~~https://cses.fi/user/72443~~~~~~~~~~~~~~

Question: https://cses.fi/problemset/task/1628/
Submission: https://cses.fi/paste/9880e42ae2b484d32e63d5/
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

void solve(){
    int n;cin>>n;
    ll x;cin>>x;
    vt<ll> nums(n);
    rep(i,n) cin>>nums[i];
    vt<ll> left, right, numsl = vt<ll>(nums.begin(),nums.begin() + (n / 2)), numsr = vt<ll>(nums.begin()+(n / 2),nums.end());
    ll m = sz(numsl), res = 0ll;
    rep(i,1 << m){
        ll cur = 0;
        rep(j,m) if(i & (1 << j)) cur += numsl[j];
        left.pb(cur);
    }
    m = sz(numsr);
    rep(i,1 << m){
        ll cur = 0;
        rep(j,m) if(i & (1 << j)) cur += numsr[j];
        right.pb(cur);
    }
    sort(all(right));
    each(i,left) res += upper_bound(all(right),x-i) - lower_bound(all(right),x-i);
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