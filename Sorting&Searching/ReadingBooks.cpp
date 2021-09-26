/*

~~~~~~~~~~~~~~https://cses.fi/user/72443~~~~~~~~~~~~~~

Question: https://cses.fi/problemset/task/1631
Submission: https://cses.fi/paste/caddedcd8c91e4152af43e/
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){
    int n;cin>>n;
    vector<ll> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    sort(nums.begin(),nums.end(),greater<ll>());
    ll sum = (ll)accumulate(nums.begin(),nums.end(),0LL);
    sum += max(0LL,nums[0] - accumulate(nums.begin()+1,nums.end(),0LL));
    cout<<sum<<'\n';
    return 0;
}