// Vacation

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n][3], dp[n][3];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    for(int i = 0; i <= 2 ; i++){
        dp[0][i] = a[0][i];
    }
    for(int i = 1 ; i < n ;i++){
        for(int j = 0; j <= 2 ; j++){
            dp[i][j] = 0;
            for(int c = 0 ; c <= 2 ; c++){
                if(c!=j)
                    dp[i][j] = max(dp[i][j], a[i][j] + dp[i-1][c]);
            }
        }
    }
    cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    return 0;
}