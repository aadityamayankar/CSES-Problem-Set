#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;cin>>s;
    int n = s.length(), i = 0, j = 0, res = 0;
    while(j < n){
        if(s[i] != s[j])
            res = max(res,j - i), i = j;
        j++;
    }
    cout<<max(res,j - i);
    return 0;
}