// Frog - 2

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n+1);
    vector<int> dp(n+1);
    for(int i = 0 ; i < n ; i ++ ){
        cin >> v[i];
    }
    dp[0] = 0;
    for(int i = 1 ; i < n ; i ++ ){
        dp[i] = INT_MAX;
        for(int j = 1 ; j <= k ; j++){
            if(i - j < 0) break;
            dp[i] = min(dp[i], dp[i-j] + abs(v[i] - v[i-j]));
        }
    }
    cout << dp[n-1];
    return 0;
}