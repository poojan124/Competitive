#include<bits/stdc++.h>
using namespace std;
int dp[505][505];
char ar[505][505];
void build(int n,int m){
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0)
                dp[i][j] = 0;
            else{
                if(i-1>=0){
                    if(ar[i][j]=='.')
                        dp[i][j] += dp[i-1][j] + (ar[i-1][j]=='.'?1:0);
                    else
                        dp[i][j] += dp[i-1][j];
                }
                if(j-1>=0){
                    if(ar[i][j]=='.')
                        dp[i][j] += dp[i][j-1] + (ar[i][j-1]=='.'?1:0);
                    else    
                        dp[i][j] += dp[i][j-1];
                }
                if(i-1>=0 && j-1>=0)
                    dp[i][j] -= dp[i-1][j-1];
            }
        }
    }
}
int ask(int x1,int y1,int x2,int y2){
    int ans = dp[x2][y2];
    if(x1-1>=0){
        ans -= dp[x1-1][y2];
        for(int i=y1;i<=y2;i++)
            if(ar[x1][i] == '.' && ar[x1-1][i] == '.')
                ans-=1;
    }
    if(y1-1>=0){
        ans -= dp[x2][y1-1];
        for(int i=x1;i<=x2;i++)
            if(ar[i][y1] =='.' &&  ar[i][y1-1] == '.')
                ans-=1;
    }
    if(y1-1>=0 && x1-1>=0)
        ans += dp[x1-1][y1-1];
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>ar[i][j];
    build(n,m);
    int q;
    cin>>q;
    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<ask(x1-1,y1-1,x2-1,y2-1)<<endl;
    }
}