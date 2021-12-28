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
#define aint(c) (c).begin(), (c).end()
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

template<class T> struct LSegTree {
	int N; vector<T> t, lz; T U=-1e18;
	T F(T i, T j) { return max(i,j); } LSegTree() {}
	LSegTree(int N) : N(N), t(4*(N+1),U), lz(4*(N+1),0) {}
	void pull(int i) { t[i] = F(t[i*2],t[i*2+1]); }
	void push(int i, int l, int r) {
		t[i]+=lz[i];
		if(l!=r) lz[i*2]+=lz[i], lz[i*2+1]+=lz[i];
		lz[i]=0; }
	void build(vector<ll> &v) { build(v,1,0,N); }
	void build(vector<ll> &v, int i, int l, int r) {
		if(l==r) { t[i]=v[l]; return; } int m=(l+r)/2;
		build(v,i*2,l,m); build(v,i*2+1,m+1,r); pull(i);
	}
	void upd(int L, int R, T v) { upd(L,R,v,1,0,N); }
	void upd(int L, int R, T v, int i, int l, int r) {
		push(i,l,r); if(R<l || L>r) return;
		if(L<=l && R>=r) { lz[i]+=v; push(i,l,r); return; }
		int m=(l+r)/2; upd(L,R,v,i*2,l,m);
		upd(L,R,v,i*2+1,m+1,r); pull(i);
	}
	T qry(int L, int R) { return qry(L,R,1,0,N); }
	T qry(int L, int R, int i, int l, int r) {
		push(i,l,r); if(R<l || L>r) return U;
		if(L<=l && R>=r) return t[i]; 
        int m=(l+r)/2;
		return F(qry(L,R,i*2,l,m), qry(L,R,i*2+1,m+1,r));
	}
};

ll n, q;
vector<ll> nums, pref;
LSegTree<ll> st;

void solve() {
	cin >> n >> q;
	nums.resize(n), pref.resize(n+1);
	rep(i,n) cin >> nums[i];
    rep(i,n) pref[i+1]=pref[i]+nums[i];
	st = LSegTree<ll>(n+1);
	st.build(pref);
	while(q--) {
		ll x,a,b; cin >> x >> a >> b;
		if(x==1) {
			st.upd(a, n, b-nums[a]); nums[a]=b;
		} else {
			cout << st.qry(a-1,b) - st.qry(a-1,a-1) << '\n';
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
// a[k] += u - a[k]