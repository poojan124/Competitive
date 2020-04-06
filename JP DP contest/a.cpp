// Frog - 1

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> v(n+1);
    vector<long long> dp(n+1);
    v[0] = 0;
    for(int i = 1 ; i < n + 1 ; i ++ ){
        cin >> v[i];
    }
    dp[0] = v[1];
    dp[1] = 0;
    for(int i = 2 ; i < n + 1; i ++ ){
        dp[i] = min(dp[i-1] + abs(v[i] - v[i-1]) , dp[i-2] + abs(v[i] - v[i-2]));
    }
    cout << dp[n];
    return 0;
}