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
 
bool check(ll m,vt<ll>& a,ll k){
    ll sum = 0;
    each(i,a) sum += m/i;
    return sum >= k;
}
 
void solve(){
    ll n,k;cin>>n>>k;
    vt<ll> a(n);
    rep(i,n) cin>>a[i];
    ll l = 0, r = *min_element(all(a))*k;
    while(l<r){
        ll m = l+((r - l)>>1);
        if(check(m,a,k)) r = m;
        else l = m+1;
    }
    cout<<r<<'\n';
}
 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "a", stderr);
    #endif
    IOS
    
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    cerr<<'\n'<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<'\n';
    return 0;
}