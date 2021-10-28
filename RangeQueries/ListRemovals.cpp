/*
 
~~~~~~~~~~~~~~https://cses.fi/user/72443~~~~~~~~~~~~~~
 
Question: https://cses.fi/problemset/task/1749/
Submission: https://cses.fi/paste/675d2ad14e518c432e9560/
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
vt<int> nums,bit,present;

void update(int x,int val){
    for(;x<n;x+=(x&-x)) bit[x] += val;
}

int query(int x){
    int sum = 0;
    for(;x>0;x-=(x&-x)) sum += bit[x];
    return sum;
}

int bs(int q){
    int l = 1, r = n, res = -1;
    while(l <= r){
        int m = l + ((r - l) >> 1);
        if(query(m) >= q) res = m, r = m - 1;
        else l = m + 1;
    }
    update(res,-present[res]);
    return nums[res];
}

void solve(){
    cin>>n;
    n++;
    nums.resize(n), bit.resize(n), present.resize(n,1);
    rng(i,1,n) cin>>nums[i], update(i,1);
    rep(i,n-1){
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