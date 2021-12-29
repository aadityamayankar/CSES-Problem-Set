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

ll n,q;
vt<ll> nums;
vt<pl> st;

const ll inf = 1e18;

void upd(ll v,ll l,ll r,ll i,ll val){
	if(l == r) st[v] = {val,val};
	else{
		ll m = l + ((r - l) >> 1);
		if(i <= m) upd(v<<1,l,m,i,val);
		else upd(v<<1|1,m+1,r,i,val);
		st[v].first = st[v<<1].first + st[v<<1|1].first;
		st[v].second = max(st[v<<1].second,st[v<<1].first + st[v<<1|1].second);
	}
}

void build(ll v,ll l,ll r){
	if(l == r) st[v].second = st[v].first = nums[l];
	else{
		ll m = l + ((r - l) >> 1);
		build(v<<1,l,m), build(v<<1|1,m+1,r);
		st[v].first = st[v<<1].first + st[v<<1|1].first;
		st[v].second = max(st[v<<1].second,st[v<<1].first + st[v<<1|1].second);
	}
}

pl qry(ll v,ll l,ll r,ll ql,ll qr){	
	if(l > qr || r < ql) return {0,0};
	if(l >= ql && r <= qr) return st[v];
	ll m = l + ((r - l) >> 1);
	pl left = qry(v<<1,l,m,ql,qr), right = qry(v<<1|1,m+1,r,ql,qr);
	return {left.first + right.first, max(left.second, left.first + right.second)};
}

void solve(){
	cin>>n>>q;
	nums.resize(n), st.resize(n<<2|1);
	rep(i,n) cin>>nums[i];
	build(1,0,n-1);
	while(q--){
		int x,a,b;cin>>x>>a>>b;
		if(x == 1) upd(1,0,n-1,a-1,b);
		else cout<<max(0ll,qry(1,0,n-1,a-1,b-1).second)<<'\n';
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