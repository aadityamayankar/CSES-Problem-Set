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

vector<ll> bit;
ll m;

void upd(ll i,ll val){
    for(;i<m;i+=i&-i) bit[i] += val;
}

ll qry(ll i){
    ll sum = 0;
    for(;i>0;i-=i&-i) sum += bit[i];
    return sum;
}

void solve(){
    ll n,q;cin>>n>>q;
    vt<ll> nums(n);
    rep(i,n) cin>>nums[i];
    vt<ll> cords = nums;
    vector<pair<char,pair<ll,ll>>> queries(q);
    for(ll z=0;z<q;z++){
        char c;cin>>c;
        ll a,b;cin>>a>>b;
        queries[z] = {c,{a,b}};
        cords.insert(cords.end(),{a,b});
    }
    sort(all(cords));
    unordered_map<ll,ll> hash;
    ll x = 1;
    each(i,cords) if(!hash.count(i)) hash[i] = x++;
    n = sz(cords);
    m = n + 1;
    bit = vt<ll>(m);
    each(i,nums) upd(hash[i],1);
    each(i,queries){
        char c = i.first;
        if(c == '?') {
            ll a = hash[i.second.first],b = hash[i.second.second];
            cout<<qry(b) - qry(a - 1)<<'\n';
        }
        else{
            ll a = hash[nums[i.second.first - 1]],b = hash[i.second.second];
            upd(a,-1), upd(b,1);
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