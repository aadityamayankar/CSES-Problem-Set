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

const ll inf = 1e18;

ll n, m;
vt<ll> nums;
vt<pl> st;

void upd(ll v,ll l,ll r,ll i,ll val){
    if(l == r) st[v] = {val,1};
    else{
        int m = l + ((r - l) >> 1);
        if(i <= m) upd(v<<1, l, m, i, val);
        else upd(v<<1|1, m+1, r, i, val);
        if(st[v<<1].first == st[v<<1|1].first) st[v] = {st[v<<1].first,st[v<<1].second+st[v<<1|1].second};
        else if(st[v<<1].first < st[v<<1|1].first) st[v] = st[v<<1];
        else st[v] = st[v<<1|1];
    }
}

pl qry(ll v,ll l,ll r,ll ql,ll qr){
    if(l > qr || r < ql) return {inf,1};
    if(l >= ql && r <= qr) return st[v];
    int m = l + ((r - l) >> 1);
    pl left = qry(v<<1, l, m, ql, qr), right = qry(v<<1|1, m+1, r, ql, qr);
    if(left.first == right.first) return {left.first,left.second+right.second};
    return min(left,right);
}

void solve(){
    cin>>n>>m;
    nums = vt<ll>(n), st = vt<pl>(n<<2|1);
    rep(i,n) {
        cin>>nums[i];
        upd(1,0,n-1,i,nums[i]);
    }
    rep(_,m){
        ll q,a,b;cin>>q>>a>>b;
        if(q == 1) upd(1,0,n-1,a,b), nums[a] = b;
        else{
            pl x = qry(1,0,n-1,a,b-1);
            cout<<x.first<<' '<<x.second<<'\n';
        }
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
    // cin>>t;
    while(t--){
        solve();
    }
    cerr<<'\n'<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<'\n';
    return 0;
}