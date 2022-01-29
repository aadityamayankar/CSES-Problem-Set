#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    if(n <= 4){
        if(n == 1) cout<<1;
        else if(n == 4) cout<<"3 1 4 2";
        else cout<<"NO SOLUTION";
        return 0;
    }
    for(int i=1;i<=n;i+=2) cout<<i<<' ';
    for(int i=2;i<=n;i+=2) cout<<i<<' ';
}