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

int n;
vt<int> nums, st;

void upd(int v,int l,int r){
    if(l == r) st[v] = nums[l];
    else{
        int m = l + ((r - l) >> 1);
        upd(v<<1,l,m), upd((v<<1)+1,m+1,r);
        //upd
    }
}

void solve(){
    int q;cin>>n>>q;
    nums = vt<int>(n);
    rep(i,n) cin>>nums[i];
    vt<int> pref(n+1);
    rep(i,n) pref[i+1] = pref[i] + nums[i];
    st = vt<int>((n<<2)+2);
    rep(i,q){
        int t,a,b;cin>>t>>a>>b;
        upd()
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "a", stderr);
    #endif
    IOS
    
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    cerr<<'\n'<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<'\n';
    return 0;
}