/*

~~~~~~~~~~~~~~https://cses.fi/user/72443~~~~~~~~~~~~~~

Question: https://cses.fi/problemset/task/1636/
Submission: https://cses.fi/paste/32bea73c91c1ed652ba128/
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
#define M 1000000007
#define ll long long
#define ld long double
#define vt vector
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define each(x, a) for (auto& x: a)
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(a)-1;i>=int(b);i--)
#define gne(i,a,b) for(int i=int(a);i>int(b);i--)
#define per(i,b) gnr(i,0,b)
#define FAST1 ios::sync_with_stdio(0);
#define FAST2 cin.tie(0);
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int rec(int n,vt<int> nums,int x){
    vt<vt<int>> dp(n+1,vt<int>(x+1));
    rep(i,n+1){
        rep(j,x+1){
            if(i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 1;
            if(i && j){
                if(nums[i-1] <= j) dp[i][j] = (dp[i][j-nums[i-1]] + dp[i-1][j]) % M;
                else dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][x];
}

void solve(){
    int n,x;cin>>n>>x;
    vt<int> nums(n);
    rep(i,n) cin>>nums[i];
    cout<<rec(n,nums,x)<<'\n';
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "a", stderr);
    #endif
    FAST1
    FAST2
    
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    cerr<<'\n'<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<'\n';
    return 0;
}