#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long a[n+1];
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%3){
        cout<<"0"<<endl;
        return 0;
    }
    int dp[n+1][(sum/3)+1];
    for(int i=0;i<=sum/3;i++)
        dp[0][i] = 0;
    for(int j=0;j<=n;j++)
        dp[j][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=(sum/3);j++){
            if(a[i]>j)
                dp[i+1][j] = dp[i][j];
            else
                dp[i+1][j] = dp[i][j] + (dp[i][j-a[i]]);
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum/3;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<sum/3<<endl;
    cout<<dp[n][sum/3]<<endl;
    return 0;
}
