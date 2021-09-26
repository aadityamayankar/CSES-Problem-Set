/*
~~~~~~~~~~~~~~https://cses.fi/user/72443~~~~~~~~~~~~~~

Question: https://cses.fi/problemset/task/1094
Submission: https://cses.fi/paste/af8c9f286ce1302f27024e/
*/


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
 
void solve(){
    int n;cin>>n;
    vt<int>nums(n);
    rep(i,n) cin>>nums[i];
    ll cnt = 0;
    rep(i,n-1){
        if(nums[i+1]<nums[i]){
            cnt += nums[i]-nums[i+1];
            nums[i+1] = nums[i];
        }
    }
    cout<<cnt<<"\n";
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
