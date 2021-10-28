/*

~~~~~~~~~~~~~~https://cses.fi/user/72443~~~~~~~~~~~~~~

Question: https://cses.fi/problemset/task/1749/
Submission: https://cses.fi/paste/3f44ab8b783de25d2e9536/
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

int n;
vt<int> nums,st,present;

void build(int v,int l,int r){
    if(l == r) st[v] = present[l];
    else{
        int m = l + ((r - l) >> 1);
        build(v<<1,l,m), build((v<<1)+1,m+1,r);
        st[v] = st[v<<1] + st[(v<<1)+1];
    }
}

void update(int v,int l,int r,int i){
    if(l == r) st[v] = 0;
    else{
        int m = l + ((r - l) >> 1);
        if(i <= m) update(v<<1,l,m,i);
        else update((v<<1)+1,m+1,r,i);
        st[v] = st[v<<1] + st[(v<<1)+1];
    }
}

int query(int v,int l,int r,int ql,int qr){
    if(r < ql || l > qr) return 0;
    if(l >= ql && r <= qr) return st[v];
    int m = l + ((r - l) >> 1);
    return query(v<<1,l,m,ql,qr) + query((v<<1)+1,m+1,r,ql,qr);
}

int bs(int q){
    int l = 0, r = n - 1, res = -1;
    while(l <= r){
        int m = l + ((r - l) >> 1);
        if(query(1,0,n-1,0,m) >= q) res = m, r = m - 1;
        else l = m + 1;
    }
    update(1,0,n-1,res);
    return nums[res];
}

void solve(){
    cin>>n;
    nums.resize(n), st.resize((n<<2)+1), present.resize(n,1);
    rep(i,n) cin>>nums[i];
    build(1,0,n-1);
    rep(i,n){
        int q;cin>>q;
        cout<<bs(q)<<' ';
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