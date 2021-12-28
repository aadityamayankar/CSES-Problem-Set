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

struct node{
    ll val, lzAdd, lzSet;
    node(){};
};

ll n,q;
vt<ll> nums;
vt<node> st;

inline void pushup(ll v){
    st[v].val = st[v<<1].val + st[v<<1|1].val;
}

void pushdown(ll v, ll l, ll m, ll r){
	if(st[v].lzSet != 0){
		st[v<<1].lzSet = st[v<<1|1].lzSet = st[v].lzSet;
		st[v<<1].val = (m-l+1) * st[v].lzSet;
		st[v<<1|1].val = (r-m) * st[v].lzSet;
		st[v<<1].lzAdd = st[v<<1|1].lzAdd = 0;
		st[v].lzSet = 0;
	}
	else if(st[v].lzAdd != 0){
		if(st[v<<1].lzSet == 0)st[v<<1].lzAdd += st[v].lzAdd;
		else {
			st[v<<1].lzSet += st[v].lzAdd;
			st[v<<1].lzAdd = 0;
		}
		if(st[v<<1|1].lzSet == 0)st[v<<1|1].lzAdd += st[v].lzAdd;
		else{
			st[v<<1|1].lzSet += st[v].lzAdd;
			st[v<<1|1].lzAdd = 0;
		}
		st[v<<1].val += (m-l+1) * st[v].lzAdd;
		st[v<<1|1].val += (r-m) * st[v].lzAdd;
		st[v].lzAdd = 0;
	}
}

void build(ll v,ll l,ll r){
    st[v].lzAdd = st[v].lzSet = 0;
    if(l == r) st[v].val = nums[l];
    else{
        ll m = l + ((r - l) >> 1);
        build(v<<1,l,m), build(v<<1|1,m+1,r);
        pushup(v);
    }
}

ll qry(ll v,ll l,ll r,ll ql,ll qr){
    if(l > qr || r < ql) return 0ll;
    if(l >= ql && r <= qr) return st[v].val;
    ll m = l + ((r - l) >> 1);
    pushdown(v,l,m,r);
    return qry(v<<1,l,m,ql,qr) + qry(v<<1|1,m+1,r,ql,qr);
}

void add(ll v, ll l, ll r, ll a, ll b, ll val){
	if(a > r || b < l)return;
	if(a <= l && r <= b){
		st[v].val += (r-l+1) * val;
		if(st[v].lzSet == 0)st[v].lzAdd += val;
		else st[v].lzSet += val;
		return;
	}
	ll m = (l+r)>>1;
	pushdown(v,l,m,r);
	add(v<<1,l,m,a,b,val);
	add(v<<1|1,m+1,r,a,b,val);
	pushup(v);
	return;
}

void upd(ll v, ll l, ll r, ll a, ll b, ll val){
	if(a > r || b < l)return;
	if(a <= l && r <= b){
		st[v].val = (r-l+1) * val;
		st[v].lzAdd = 0;
		st[v].lzSet = val;
		return;
	}
	ll m = (l+r)>>1;
	pushdown(v,l,m,r);
	upd(v<<1,l,m,a,b,val), upd(v<<1|1,m+1,r,a,b,val);
	pushup(v);
}

void solve(){
    cin>>n>>q;
    nums = vt<ll>(n), st = vt<node>(n<<2|1);
    rep(i,n) cin>>nums[i];
    build(1,0,n-1);
    while(q--){
        ll x,a,b;cin>>x>>a>>b;
        a--, b--;
        if(x == 1){
            ll c;cin>>c;
            add(1,0,n-1,a,b,c);
        }
        else if(x == 2){
            ll c;cin>>c;
            upd(1,0,n-1,a,b,c);
        }
        else{
            cout<<qry(1,0,n-1,a,b)<<'\n';
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