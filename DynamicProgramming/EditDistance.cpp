/*

~~~~~~~~~~~~~~https://cses.fi/user/72443~~~~~~~~~~~~~~

Question: https://cses.fi/problemset/task/1639
Submission: https://cses.fi/paste/bd8c319e6a9c20322c70d3/
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
#define len(x) (int)(x).length()
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

int minOperations(string a,string b,int n,int m){
    vt<vt<int>> dp(n+1,vt<int>(m+1));
    rep(i,n+1){
        rep(j,m+1){
            if(i==0) dp[i][j] = j;
            else if(j==0) dp[i][j] = i;
            else if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
        }
    }
    return dp[n][m];
}


void solve(){
    string a,b;cin>>a>>b;
    int n = len(a), m = len(b);
    cout<<minOperations(a,b,n,m)<<'\n';
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