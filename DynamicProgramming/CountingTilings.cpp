/*

~~~~~~~~~~~~~~https://cses.fi/user/72443~~~~~~~~~~~~~~

Question: https://cses.fi/problemset/task/2181
Submission: https://cses.fi/paste/5be1c9f16fd7fd002e1a16/
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

int dp[1002][(1<<10)+1];

void getMasks(int cur_mask,int i,int n,int temp_mask,vt<int>& masks){
    if(i == n + 1) {
        masks.push_back(temp_mask);
        return;
    }
    if((cur_mask & (1 << i)) != 0)
        getMasks(cur_mask,i+1,n,temp_mask,masks);
    if(i != n){
        if((cur_mask & (1 << i)) == 0 && (cur_mask & (1 << (i + 1))) == 0)
            getMasks(cur_mask,i+2,n,temp_mask,masks);
    }
    if((cur_mask & (1 << i)) == 0) 
        getMasks(cur_mask,i+1,n,temp_mask + (1 << i),masks);
}

int rec(int col,int mask,int n,int m){
    if(col == m + 1){
        if(mask == 0) return 1;
        return 0;
    }
    if(dp[col][mask] != -1) return dp[col][mask];
    vt<int> masks;
    getMasks(mask,1,n,0,masks);
    int cur = 0;
    each(next_mask,masks){
        cur = (cur + rec(col+1,next_mask,n,m)) % MOD;
    }
    return dp[col][mask] = cur;
}

void solve(){
    memset(dp,-1,sizeof dp);
    int n,m;cin>>n>>m;
    int res = rec(1,0,n,m);
    cout<<res<<'\n';
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "a", stderr);
    #endif
    FASTIO
    
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    cerr<<'\n'<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<'\n';
    return 0;
}