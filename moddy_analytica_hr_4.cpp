#include<bits/stdc++.h>
using namespace std;
int dp[100+1][100+1][100+1];
void solve(){
    memset(dp,0,sizeof(dp));
    dp[0][0][0] = 1;
    for(int i=1;i<=100;i++){
        int flag1 = 0;
        for(int j=0;j<=((i)*(i-1))/2;j++){
            for(int k=0;k<=i;k++){
                for(int z=0;z<=i-1;z++){
                    if(i+j<=100)
                        dp[i+j][k+1][i] += dp[j][k][z];
                    else{
                        flag1 = 1;
                        break;
                    }
                }
            }
            if(flag1)
                break;
        }
    }
}
int main(){
    int q;
    scanf("%d",&q);
    solve();
    while(q--){
        int a,m;
        scanf("%d %d",&a,&m);
        int ans=0;
        for(int c=0;c<=m;c++)
            for(int z=int(sqrt(a));z<=a;z++)
                ans += dp[a][c][z];
        printf("%d\n",ans);
    }
    return 0;
}