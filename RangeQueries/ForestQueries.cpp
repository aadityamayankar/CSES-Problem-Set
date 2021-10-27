/*

~~~~~~~~~~~~~~https://cses.fi/user/72443~~~~~~~~~~~~~~

Question: https://cses.fi/problemset/task/1652
Submission: https://cses.fi/paste/38a8c5f95ea9b7f72e80dd/
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

vt<vt<int>> mat, bit;
int n;

void update(int _x,int _y,int val){
    int x = _x;
    for(;x<n;x+=(x&-x)){
        int y = _y;
        for(;y<n;y+=(y&-y)){
            bit[x][y] += val;
        }
    }
}

int getSum(int _x,int _y){
    int sum = 0, x = _x;
    for(;x>0;x-=(x&-x)){
        int y = _y;
        for(;y>0;y-=(y&-y)){
            sum += bit[x][y];
        }
    }
    return sum;
}

void build(){
    rng(i,1,n) rng(j,1,n) update(i,j,mat[i][j]);
}

int query(int x1,int y1,int x2,int y2){
    return getSum(x2,y2) - getSum(x2,y1-1) - getSum(x1-1,y2) + getSum(x1-1,y1-1);
}

void solve(){
    int _n,q;cin>>_n>>q;
    n = _n + 1;
    mat = vt<vt<int>> (n+1,vt<int>(n+1)), bit = vt<vt<int>>(n+1,vt<int>(n+1));
    rng(i,1,n){
        rng(j,1,n){
            char c;cin>>c;
            if(c == '*') mat[i][j] = 1;
        }
    }
    build();
    while(q--){
        int y1,x1,y2,x2;cin>>x1>>y1>>x2>>y2;
        cout<<query(x1,y1,x2,y2)<<'\n';
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