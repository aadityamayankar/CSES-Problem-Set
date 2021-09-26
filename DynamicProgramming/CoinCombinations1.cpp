#include <bits/stdc++.h>
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

int combinations(vt<int> c,int sum,int n){
    vt<int> dp(sum+1);
    dp[0] = 1;
    rng(i,1,sum+1){
        rng(j,1,n+1){
            if(c[j-1]<=i){
                dp[i] = (dp[i] + dp[i-c[j-1]]) % M;
            }
        }
    }
    return dp[sum];
}

void solve(){
    int n,x;cin>>n>>x;
    vt<int> c(n);
    rep(i,n) cin>>c[i];
    cout<<combinations(c,x,n);
}

int main(){
    FAST1
    FAST2
    
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}