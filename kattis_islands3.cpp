#include<bits/stdc++.h>
using namespace std;
bool v[51][51];
char grid[51][51];
void dfs(int x,int y,int n,int m){
    if(x<0 || x>=n || y<0 || y>=m)
        return;
    if(grid[x][y]=='W' || v[x][y])
        return;
    v[x][y] = 1;
    dfs(x+1,y,n,m);
    dfs(x-1,y,n,m);
    dfs(x,y+1,n,m);
    dfs(x,y-1,n,m);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    memset(v,0,sizeof(v));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='L' && v[i][j]==0){
                ans++;
                dfs(i,j,n,m);
            }
        }
    }
    cout<<ans;
    return 0;
}